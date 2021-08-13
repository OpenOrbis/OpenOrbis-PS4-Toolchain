package main

import (
	"bytes"
	"debug/elf"
	"encoding/binary"
	"math"
	"sort"
)

type programHeaderList []elf.Prog64

// OrbisElf.GenerateProgramHeaders parses the input ELF's section header table to generate fresh new program headers.
// Returns nil.
func (orbisElf *OrbisElf) GenerateProgramHeaders() error {
	// Get all the necessary sections first
	// TODO: Verify these sections exist in OrbisElf.ValidateInputELF()
	textSection := orbisElf.ElfToConvert.Section(".text")
	relroSection := orbisElf.ElfToConvert.Section(".data.rel.ro")
	gotSection := orbisElf.ElfToConvert.Section(".got")
	gotPltSection := orbisElf.ElfToConvert.Section(".got.plt")
	procParamSection := orbisElf.ElfToConvert.Section(".data.sce_process_param")

	if TOOL_MODE == "SPRX" {
		procParamSection = orbisElf.ElfToConvert.Section(".data.sce_module_param")
	}

	// Get proper data segment information
	dataSection := orbisElf.ElfToConvert.Section(".data")
	bssSection := orbisElf.ElfToConvert.Section(".bss")

	// We don't need to check if these are nil because we've already verified the input ELF has a .text segment
	oldTextHeader := orbisElf.getProgramHeader(elf.PT_LOAD, elf.PF_R|elf.PF_X)

	// PT_INTERP - The interpreter string. This will always be at text + 0x00.
	if TOOL_MODE == "SELF" {
		interpreterHeader := generateInterpreterHeader(textSection.Offset)
		orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, interpreterHeader)
	}

	// PT_TLS - Empty TLS header. Unsure if it's needed, but we'll add it anyways as it's not hard to generate.
	oldTlsHeader := orbisElf.getProgramHeader(elf.PT_TLS, elf.PF_R)
	tlsHeader := generateEmptyTLSHeader()
	if oldTlsHeader != nil {
		tlsHeader = generateTLSHeader(oldTlsHeader)
	}
	orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, tlsHeader)

	// PT_LOAD - The text segment.
	textHeader := generateTextHeader(oldTextHeader)
	orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, textHeader)

	// PT_GNU_EH_FRAME - Might not always exist, but if it does we'll need it for exception handling.
	oldGnuEhFrameHeader := orbisElf.getProgramHeader(PT_GNU_EH_FRAME, elf.PF_R)

	if oldGnuEhFrameHeader != nil {
		gnuEhFrameHeader := generateEHFrameHeader(oldGnuEhFrameHeader)
		orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, gnuEhFrameHeader)
	}

	// PT_SCE_RELRO - This segment is a little weird since we have to generate it from multiple segments, and it *must*
	// be contiguous with the data LOAD segment, so we need to connect the in-memory size. To do that, we'll use the
	// offset for the first section we find for relro, and subtract it from the data LOAD segment offset.
	dataSegmentOffset := procParamSection.Offset
	dataSegmentAddr := procParamSection.Addr

	// Check for the existence of relro-related sections
	if gotPltSection != nil || gotSection != nil || relroSection != nil {
		relroOffset := uint64(0)
		relroAddr := uint64(0)

		// Order of potential first sections in the relro segment:
		// 1) .data.rel.ro
		// 2) .got
		// 3) .got.plt
		if gotPltSection != nil {
			relroOffset = gotPltSection.Offset
			relroAddr = gotPltSection.Addr
		}

		if gotSection != nil {
			relroOffset = gotSection.Offset
			relroAddr = gotSection.Addr
		}

		if relroSection != nil {
			relroOffset = relroSection.Offset
			relroAddr = relroSection.Addr
		}

		sizeOfSceRelro := dataSegmentAddr - relroAddr

		relroHeader := generateRelroHeader(relroOffset, relroAddr, sizeOfSceRelro)
		orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, relroHeader)
	}

	// We'll get the size by subtracting the proc param offset from data's offset so we get padding for free, which the
	// header size will not provide.
	dataSize := (dataSection.Offset - procParamSection.Offset) + dataSection.Size
	dataMemSize := (dataSection.Addr - procParamSection.Addr) + dataSection.Size

	// Also check for .bss - if it exists, factor it into the size
	if bssSection != nil {
		dataMemSize += (bssSection.Addr - (dataSection.Addr + dataSection.Size)) + bssSection.Size
	}

	// PT_LOAD - The data segment.
	dataHeader := generateDataHeader(dataSegmentOffset, dataSegmentAddr, dataSize, dataMemSize)
	orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, dataHeader)

	// PT_SCE_PROC_PARAM or PT_SCE_MODULE_PARAM - The SCE process (or module) param segment.
	procParamHeader := generateSceProcParamHeader(procParamSection.Offset, procParamSection.Addr, procParamSection.Size)
	orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, procParamHeader)

	// PT_SCE_DYNLIB_DATA - The SCE dynlib data segment. This contains all the information necessary for the dynamic
	// linker.
	dynlibHeader := generateSceDynlibDataHeader(offsetOfDynlibData, sizeOfDynlibData)
	orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, dynlibHeader)

	// PT_DYNAMIC - The dynamic table segment. This segment overlaps partially with PT_SCE_DYNLIB_DATA.
	dynamicHeader := generateDynamicHeader(offsetOfDynamic, sizeOfDynamic)
	orbisElf.ProgramHeaders = append(orbisElf.ProgramHeaders, dynamicHeader)

	sort.Sort(programHeaderList(orbisElf.ProgramHeaders))

	return nil
}

// OrbisElf.RewriteProgramHeaders iterates the list of new program headers and overwrites the ELF's program header table
// with the new headers. Returns an error if the write failed, nil otherwise.
func (orbisElf *OrbisElf) RewriteProgramHeaders() error {
	programHeaderTable := 0x40

	for i, progHeader := range orbisElf.ProgramHeaders {
		progHeaderBuff := new(bytes.Buffer)

		// Calculate the offset to write to by indexing into the program header table
		writeOffset := int64(programHeaderTable + (i * 0x38))

		// Write the structure into a buffer
		if err := binary.Write(progHeaderBuff, binary.LittleEndian, progHeader); err != nil {
			return err
		}

		// Overwrite the entry in the file
		if _, err := orbisElf.FinalFile.WriteAt(progHeaderBuff.Bytes(), writeOffset); err != nil {
			return err
		}
	}

	return nil
}

// generateInterpreterHeader takes a given interpreterOffset and creates a program header for it. Returns the final program
// header.
func generateInterpreterHeader(interpreterOffset uint64) elf.Prog64 {
	return elf.Prog64{
		Type:  uint32(elf.PT_INTERP),
		Flags: uint32(elf.PF_R),
		Vaddr: 0,
		Paddr: 0,

		// Interpreter will always be at offset 0 in the .text segment
		Off: interpreterOffset,

		Filesz: 0x15,
		Memsz:  0x15,
		Align:  1,
	}
}

// generateEmptyTLSHeader creates an empty program header for TLS. Returns the final program header.
func generateEmptyTLSHeader() elf.Prog64 {
	return elf.Prog64{
		Type:   uint32(elf.PT_TLS),
		Flags:  uint32(elf.PF_R),
		Vaddr:  0,
		Paddr:  0,
		Off:    0,
		Filesz: 0,
		Memsz:  0,
		Align:  1,
	}
}

// generateInterpreterHeader takes the original PT_LOAD (.text) program header and copies it over. Returns the final
// program header.
func generateTextHeader(originalTextHeader *elf.Prog) elf.Prog64 {
	return elf.Prog64{
		Type:   uint32(originalTextHeader.Type),
		Flags:  uint32(originalTextHeader.Flags),
		Vaddr:  originalTextHeader.Vaddr,
		Paddr:  originalTextHeader.Paddr,
		Off:    originalTextHeader.Off,
		Filesz: originalTextHeader.Filesz,
		Memsz:  originalTextHeader.Memsz,
		Align:  0x4000,
	}
}
func generateTLSHeader(originalTLSHeader *elf.Prog) elf.Prog64 {
	return elf.Prog64{
		Type:   uint32(originalTLSHeader.Type),
		Flags:  uint32(originalTLSHeader.Flags),
		Vaddr:  originalTLSHeader.Vaddr,
		Paddr:  originalTLSHeader.Paddr,
		Off:    originalTLSHeader.Off,
		Filesz: originalTLSHeader.Filesz,
		Memsz:  originalTLSHeader.Memsz,
		Align:  1,
	}
}

// generateEHFrameHeader takes the original PT_GNU_EH_FRAME program header and copies it over. Returns the final program
// header.
func generateEHFrameHeader(originalEHHeader *elf.Prog) elf.Prog64 {
	return elf.Prog64{
		Type:   uint32(originalEHHeader.Type),
		Flags:  uint32(originalEHHeader.Flags),
		Vaddr:  originalEHHeader.Vaddr,
		Paddr:  originalEHHeader.Vaddr,
		Off:    originalEHHeader.Off,
		Filesz: originalEHHeader.Filesz,
		Memsz:  originalEHHeader.Memsz,
		Align:  0x4,
	}
}

// generateInterpreterHeader takes a given offset, virtualAddr, and size to create a new PT_SCE_RELRO program header.
// Returns the final program header.
func generateRelroHeader(offset uint64, virtualAddr uint64, size uint64) elf.Prog64 {
	return elf.Prog64{
		Type:   PT_SCE_RELRO,
		Flags:  uint32(elf.PF_R),
		Vaddr:  virtualAddr,
		Paddr:  virtualAddr,
		Off:    offset,
		Filesz: size,
		Memsz:  size,
		Align:  0x4000,
	}
}

// generateDataHeader takes the given offset, virtualAddr, and size to create a new PT_LOAD (.data) program header.
// Returns the final program header.
func generateDataHeader(offset uint64, virtualAddr uint64, size uint64, memSize uint64) elf.Prog64 {
	return elf.Prog64{
		Type:   uint32(elf.PT_LOAD),
		Flags:  uint32(elf.PF_R | elf.PF_W),
		Vaddr:  virtualAddr,
		Paddr:  virtualAddr,
		Off:    offset,
		Filesz: size,
		Memsz:  memSize,
		Align:  0x4000,
	}
}

// generateSceProcParamHeader takes the given offset, virtualAddr, and size to create a new PT_SCE_PROC_PARAM program
// header. Returns the final program header.
func generateSceProcParamHeader(offset uint64, virtualAddr uint64, size uint64) elf.Prog64 {
	segmentType := PT_SCE_PROC_PARAM

	if TOOL_MODE == "SPRX" {
		segmentType = PT_SCE_MODULE_PARAM
	}

	return elf.Prog64{
		Type:   uint32(segmentType),
		Flags:  uint32(elf.PF_R),
		Vaddr:  virtualAddr,
		Paddr:  virtualAddr,
		Off:    offset,
		Filesz: size,
		Memsz:  size,
		Align:  0x8,
	}
}

// generateSceDynlibDataHeader takes the given offset and size to create a new PT_SCE_DYNLIBDATA program header. Returns
// the final program header.
func generateSceDynlibDataHeader(offset uint64, size uint64) elf.Prog64 {
	return elf.Prog64{
		Type:   PT_SCE_DYNLIBDATA,
		Flags:  uint32(elf.PF_R),
		Vaddr:  0,
		Paddr:  0,
		Off:    offset,
		Filesz: size,
		Memsz:  0,
		Align:  0x10,
	}
}

// generateDynamicHeader takes a given offset and size to create a new PT_DYNAMIC header with updated values. Returns
// the final program header.
func generateDynamicHeader(offset uint64, size uint64) elf.Prog64 {
	return elf.Prog64{
		Type:   uint32(elf.PT_DYNAMIC),
		Flags:  uint32(elf.PF_R | elf.PF_W),
		Vaddr:  0,
		Paddr:  0,
		Off:    offset,
		Filesz: size,
		Memsz:  size,
		Align:  0x8,
	}
}

////
// Sorting for program headers
////

// Create two priority mappings - one of program header types, and one of program header permissions for PT_LOAD.
// The first mapping will be used to re-order the table. The second mapping will be used when PT_LOAD is encountered,
// as we'll want an order defined for PT_LOAD as well.
var progHeaderTypeOrder = []elf.ProgType{
	elf.PT_LOAD,
	PT_SCE_RELRO,
	elf.PT_LOAD,
	PT_SCE_PROC_PARAM,
	PT_SCE_MODULE_PARAM,
	elf.PT_DYNAMIC,
	elf.PT_INTERP,
	elf.PT_TLS,
	PT_GNU_EH_FRAME,
	PT_SCE_DYNLIBDATA,
}

// getProgramHeaderPriority is a sorting function that will utilize the progHeaderTypeOrder mapping to determine an index
// for the program header, which will be utilized by the programHeaderList.Less() function for sorting.
func getProgramHeaderPriority(progHeaderOrder []elf.ProgType, progType uint32, progFlags uint32) int {
	for i, v := range progHeaderOrder {
		if uint32(v) == progType {
			// Ensure with PT_LOAD that the flags are correct (ie. the second PT_LOAD should have R|W flags
			if v == elf.PT_LOAD && i == 0 && progFlags == uint32(elf.PF_R|elf.PF_W) {
				continue
			}

			return i
		}
	}

	// Force unknown program headers to the end
	return math.MaxInt32
}

// programHeaderList.Len() is a standard function that just returns the length of the list.
func (s programHeaderList) Len() int {
	return len(s)
}

// programHeaderList.Swap() is a standard function that just swaps i and j elements in the list.
func (s programHeaderList) Swap(i int, j int) {
	s[i], s[j] = s[j], s[i]
}

// programHeaderList.Less() uses the getProgramHeaderPriority() function to sort the list by priority.
func (s programHeaderList) Less(i int, j int) bool {
	return getProgramHeaderPriority(progHeaderTypeOrder, s[i].Type, s[i].Flags) < getProgramHeaderPriority(progHeaderTypeOrder, s[j].Type, s[j].Flags)
}
