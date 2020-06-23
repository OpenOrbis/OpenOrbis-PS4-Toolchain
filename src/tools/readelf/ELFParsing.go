package main

import (
	"debug/elf"
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

const PT_GNU_EH_FRAME = 0x6474E550

// SCE-specific program header types
const PT_SCE_DYNLIBDATA = 0x61000000   // Dynamic Linking Data
const PT_SCE_PROC_PARAM = 0x61000001   // Process Parameters
const PT_SCE_MODULE_PARAM = 0x61000002 // Module Parameters
const PT_SCE_RELRO = 0x61000010        // Read-Only Reallocation Data

// SCE-specific dynamic table tags
const DT_SCE_FINGERPRINT = 0x61000007       // Fingerprint data. Not important for homebrew.
const DT_SCE_FILENAME = 0x61000009          // Original filename
const DT_SCE_MODULE_INFO = 0x6100000D       // Module information
const DT_SCE_NEEDED_MODULE = 0x6100000F     // Needed module
const DT_SCE_MODULE_ATTR = 0x61000011       // Module attributes
const DT_SCE_EXPORT_LIB = 0x61000013        // Library exports
const DT_SCE_IMPORT_LIB = 0x61000015        // Library imports
const DT_SCE_EXPORT_LIB_ATTR = 0x61000017   // Library attributes
const DT_SCE_IMPORT_LIB_ATTR = 0x61000019   // Library attributes
const DT_SCE_STUB_MODULE_NAME = 0x6100001D  // Module name for the associated stub
const DT_SCE_STUB_MODULE_VER = 0x6100001F   // Module version for the associated stub
const DT_SCE_STUB_LIBRARY_NAME = 0x61000021 // ???
const DT_SCE_STUB_LIBRARY_VER = 0x61000023  // ???
const DT_SCE_HASH = 0x61000025              // Symbol hash table (NID's?)
const DT_SCE_PLTGOT = 0x61000027            // Address associated with the SCE linkage table
const DT_SCE_JMPREL = 0x61000029            // Address of relocations associated with SCE PLT
const DT_SCE_PLTREL = 0x6100002b            // Type of relocation entry used for linking (SCE)
const DT_SCE_PLTRELSZ = 0x6100002d          // Size of relocation entries in SCE PLT
const DT_SCE_RELA = 0x6100002f              // Address of SCE relocation table
const DT_SCE_RELASZ = 0x61000031            // Size of SCE Rela relocation table
const DT_SCE_RELAENT = 0x61000033           // Size of SCE Rela relocation table entries
const DT_SCE_STRTAB = 0x61000035            // Address of SCE dynamic string table
const DT_SCE_STRSZ = 0x61000037             // Total size of SCE dynamic string table
const DT_SCE_SYMTAB = 0x61000039            // Address of SCE dynamic symbol table
const DT_SCE_SYMENT = 0x6100003b            // Total size of SCE dynamic symbol table entry
const DT_SCE_HASHSZ = 0x6100003d            // Total size of SCE symbol hash table (NID's?)
const DT_SCE_SYMTABSZ = 0x6100003f          // Total size of SCE dynamic symbol table

// getString takes a given slice and starting index, and returns the string at that index in the table, as well as bool
// indicating whether or not the index actually contains a valid string.
func getString(section []byte, start int) (string, bool) {
	if start < 0 || start >= len(section) {
		return "", false
	}

	for end := start; end < len(section); end++ {
		if section[end] == 0 {
			return string(section[start:end]), true
		}
	}

	return "", false
}

// getProgramHeader takes a given list of program headers, a header type, and a set of header flags, and searches the
// list using the header type and header flags as a query. Returns a pointer to the found program header, or nil if the
// query couldn't be satisfied.
func getProgramHeader(progs []*elf.Prog, headerType elf.ProgType, headerFlags elf.ProgFlag) *elf.Prog {
	for _, header := range progs {
		if header.Type == headerType && header.Flags == headerFlags {
			return header
		}
	}

	return nil
}

// encodeToHexStringWithSpaces takes a given source buffer and returns a string that contains the hexadecimal representation
// of the bytes in the buffer spaced out.
func encodeToHexStringWithSpaces(src []byte) string {
	return fmt.Sprintf("% x", src)
}

// encodeToHexString takes a given uint64 value and a bool of whether or not to pad it, and returns a string that contains
// the hexadecimal representation of the value with a 0x prefix. If pad is set to true, it's also padded with zeros to 16
// bytes.
func encodeToHexString(src uint64, pad bool) string {
	if pad {
		return fmt.Sprintf("%#016x", src)
	}

	return fmt.Sprintf("%#x", src)
}

// convertProgramHeaderTypeToString takes a given program header type and returns a string representation of it.
func convertProgramHeaderTypeToString(progType elf.ProgType) string {
	switch progType {
	case elf.PT_LOAD:
		return "LOAD"
	case elf.PT_DYNAMIC:
		return "DYNAMIC"
	case elf.PT_INTERP:
		return "INTERP"
	case elf.PT_TLS:
		return "TLS"
	case PT_GNU_EH_FRAME:
		return "GNU_EH_FRAME"
	case PT_SCE_DYNLIBDATA:
		return "SCE_DYNLIBDATA"
	case PT_SCE_PROC_PARAM:
		return "SCE_PROC_PARAM"
	case PT_SCE_MODULE_PARAM:
		return "SCE_MODULE_PARAM"
	case PT_SCE_RELRO:
		return "SCE_RELRO"
	}

	return "Unknown"
}

// getSectionFlags takes a given set of section flags and constructs a string of one letter representations for each flag.
func getSectionFlags(sectionFlags elf.SectionFlag) string {
	finalFlags := ""

	if sectionFlags&elf.SHF_WRITE != 0 {
		finalFlags += "W"
	}

	if sectionFlags&elf.SHF_ALLOC != 0 {
		finalFlags += "A"
	}

	if sectionFlags&elf.SHF_EXECINSTR != 0 {
		finalFlags += "X"
	}

	if sectionFlags&elf.SHF_MERGE != 0 {
		finalFlags += "M"
	}

	if sectionFlags&elf.SHF_STRINGS != 0 {
		finalFlags += "S"
	}

	if sectionFlags&elf.SHF_INFO_LINK != 0 {
		finalFlags += "I"
	}

	if sectionFlags&elf.SHF_LINK_ORDER != 0 {
		finalFlags += "L"
	}

	if sectionFlags&elf.SHF_OS_NONCONFORMING != 0 {
		finalFlags += "O"
	}

	if sectionFlags&elf.SHF_GROUP != 0 {
		finalFlags += "G"
	}

	if sectionFlags&elf.SHF_TLS != 0 {
		finalFlags += "T"
	}

	if sectionFlags&elf.SHF_COMPRESSED != 0 {
		finalFlags += "C"
	}

	return finalFlags
}

// getDynamicTagType takes a given tag and returns a string representation of the tag type.
func getDynamicTagType(tag elf.DynTag) string {
	var tagLiteral string

	switch tag {
	// Standard ELF stuff
	case elf.DT_NULL:
		tagLiteral = "NULL"
	case elf.DT_NEEDED:
		tagLiteral = "NEEDED"
	case elf.DT_PLTRELSZ:
		tagLiteral = "PLTRELSZ"
	case elf.DT_PLTGOT:
		tagLiteral = "PLTGOT"
	case elf.DT_HASH:
		tagLiteral = "HASH"
	case elf.DT_STRTAB:
		tagLiteral = "STRTAB"
	case elf.DT_SYMTAB:
		tagLiteral = "SYMTAB"
	case elf.DT_RELA:
		tagLiteral = "RELA"
	case elf.DT_RELASZ:
		tagLiteral = "RELASZ"
	case elf.DT_RELAENT:
		tagLiteral = "RELAENT"
	case elf.DT_STRSZ:
		tagLiteral = "STRSZ"
	case elf.DT_SYMENT:
		tagLiteral = "SYMENT"
	case elf.DT_INIT:
		tagLiteral = "INIT"
	case elf.DT_FINI:
		tagLiteral = "FINI"
	case elf.DT_SONAME:
		tagLiteral = "SONAME"
	case elf.DT_RPATH:
		tagLiteral = "RPATH"
	case elf.DT_SYMBOLIC:
		tagLiteral = "SYMBOLIC"
	case elf.DT_REL:
		tagLiteral = "REL"
	case elf.DT_RELSZ:
		tagLiteral = "RELSZ"
	case elf.DT_RELENT:
		tagLiteral = "RELENT"
	case elf.DT_PLTREL:
		tagLiteral = "PLTREL"
	case elf.DT_DEBUG:
		tagLiteral = "DEBUG"
	case elf.DT_TEXTREL:
		tagLiteral = "TEXTREL"
	case elf.DT_JMPREL:
		tagLiteral = "JMPREL"
	case elf.DT_BIND_NOW:
		tagLiteral = "BIND_NOW"
	case elf.DT_INIT_ARRAY:
		tagLiteral = "INIT_ARRAY"
	case elf.DT_FINI_ARRAY:
		tagLiteral = "FINI_ARRAY"
	case elf.DT_INIT_ARRAYSZ:
		tagLiteral = "INIT_ARRAYSZ"
	case elf.DT_FINI_ARRAYSZ:
		tagLiteral = "FINI_ARRAYSZ"
	case elf.DT_RUNPATH:
		tagLiteral = "RUNPATH"
	case elf.DT_FLAGS:
		tagLiteral = "FLAGS"
	case elf.DT_PREINIT_ARRAY:
		tagLiteral = "PREINIT_ARRAY"
	case elf.DT_PREINIT_ARRAYSZ:
		tagLiteral = "PREINIT_ARRAYSZ"

	// Sony stuff
	case DT_SCE_FINGERPRINT:
		tagLiteral = "SCE_FINGERPRINT"
	case DT_SCE_FILENAME:
		tagLiteral = "SCE_FILENAME"
	case DT_SCE_MODULE_INFO:
		tagLiteral = "SCE_MODULE_INFO"
	case DT_SCE_NEEDED_MODULE:
		tagLiteral = "SCE_NEEDED_MODULE"
	case DT_SCE_MODULE_ATTR:
		tagLiteral = "SCE_MODULE_ATTR"
	case DT_SCE_EXPORT_LIB:
		tagLiteral = "SCE_EXPORT_LIB"
	case DT_SCE_IMPORT_LIB:
		tagLiteral = "SCE_IMPORT_LIB"
	case DT_SCE_EXPORT_LIB_ATTR:
		tagLiteral = "SCE_EXPORT_LIB_ATTR"
	case DT_SCE_IMPORT_LIB_ATTR:
		tagLiteral = "SCE_IMPORT_LIB_ATTR"
	case DT_SCE_STUB_MODULE_NAME:
		tagLiteral = "SCE_STUB_MODULE_NAME"
	case DT_SCE_STUB_MODULE_VER:
		tagLiteral = "SCE_STUB_MODULE_VER"
	case DT_SCE_STUB_LIBRARY_NAME:
		tagLiteral = "SCE_STUB_LIBRARY_NAME"
	case DT_SCE_STUB_LIBRARY_VER:
		tagLiteral = "SCE_STUB_LIBRARY_VER"
	case DT_SCE_HASH:
		tagLiteral = "SCE_HASH"
	case DT_SCE_PLTGOT:
		tagLiteral = "SCE_PLTGOT"
	case DT_SCE_JMPREL:
		tagLiteral = "SCE_JMPREL"
	case DT_SCE_PLTREL:
		tagLiteral = "SCE_PLTREL"
	case DT_SCE_PLTRELSZ:
		tagLiteral = "SCE_PLTRELSZ"
	case DT_SCE_RELA:
		tagLiteral = "SCE_RELA"
	case DT_SCE_RELASZ:
		tagLiteral = "SCE_RELASZ"
	case DT_SCE_RELAENT:
		tagLiteral = "SCE_RELAENT"
	case DT_SCE_STRTAB:
		tagLiteral = "SCE_STRTAB"
	case DT_SCE_STRSZ:
		tagLiteral = "SCE_STRSZ"
	case DT_SCE_SYMTAB:
		tagLiteral = "SCE_SYMTAB"
	case DT_SCE_SYMENT:
		tagLiteral = "SCE_SYMENT"
	case DT_SCE_HASHSZ:
		tagLiteral = "SCE_HASHSZ"
	case DT_SCE_SYMTABSZ:
		tagLiteral = "SCE_SYMTABSZ"

	default:
		tagLiteral = "UNKNOWN"
	}

	return "(" + tagLiteral + ")"
}

// getDynamicTagVal takes a given tag, value, and string table, and will do a lookup for the string in the case of
// DT_NEEDED, DT_SCE_NEEDED_MODULE, DT_SONAME, DT_SCE_STUB_LIBRARY_NAME, DT_SCE_STUB_MODULE_NAME, and DT_SCE_FILENAME
// tag types, and return the string. If the tag is not one of the ones listed, it falls back on returning a hexadecimal
// representation of the value (non-padded).
func getDynamicTagVal(tag elf.DynTag, val uint64, stringTable []byte) string {
	switch tag {
	// Mix standard ELF + sony
	case elf.DT_NEEDED, DT_SCE_NEEDED_MODULE:
		// For needed modules, the upper 32-bits are meta-data, we must clear it
		if tag == DT_SCE_NEEDED_MODULE {
			val = val & 0xFFFFFFFF
		}
		lib, _ := getString(stringTable, int(val))
		return fmt.Sprintf("Shared library: [%s]", lib)
	case elf.DT_SONAME, DT_SCE_STUB_LIBRARY_NAME:
		lib, _ := getString(stringTable, int(val))
		return fmt.Sprintf("Library soname: [%s]", lib)
	case DT_SCE_STUB_MODULE_NAME:
		module, _ := getString(stringTable, int(val))
		return fmt.Sprintf("Module name: [%s]", module)
	case DT_SCE_FILENAME:
		filename, _ := getString(stringTable, int(val))
		return fmt.Sprintf("File name: [%s]", filename)
	}

	// Fall back on just returning the hex encoded value
	return encodeToHexString(val, false)
}

// getRelaType takes a given relocation type as a uint64, and returns a string representation of it.
func getRelaType(rela uint64) string {
	relaType := rela & 0xffffffff

	switch relaType {
	case uint64(elf.R_X86_64_NONE):
		return "R_AMD64_NONE"
	case uint64(elf.R_X86_64_64):
		return "R_AMD64_64"
	case uint64(elf.R_X86_64_GLOB_DAT):
		return "R_AMD64_GLOB_DAT"
	case uint64(elf.R_X86_64_JMP_SLOT):
		return "R_AMD64_JUMP_SLOT"
	case uint64(elf.R_X86_64_RELATIVE):
		return "R_AMD64_RELATIVE"
	}

	return "Unknown"
}

// getSymbolType takes a given symbol's info byte, and returns the string representation of the type.
func getSymbolType(info uint8) string {
	switch info {
	case uint8(elf.STT_FUNC):
		return "FUNC"
	case uint8(elf.STT_OBJECT):
		return "OBJECT"
	case uint8(elf.STT_SECTION):
		return "SECTION"
	}

	return "NOTYPE"
}

// getSymbolBind takes a given symbol's info byte, and returns the string representation of the binding.
func getSymbolBind(info uint8) string {
	switch info {
	case uint8(elf.STB_LOCAL):
		return "LOCAL"
	case uint8(elf.STB_GLOBAL):
		return "GLOBAL"
	case uint8(elf.STB_WEAK):
		return "WEAK"
	}

	return "UNK"
}

// printFileHeader parses the given inputFile and inputElf, and prints out the ELF header to stdout.
func printFileHeader(inputFile *os.File, inputElf *elf.File) {
	// Get header info
	hdr := new(elf.Header64)

	_, err := inputFile.Seek(0, io.SeekStart)
	check(err)

	err = binary.Read(inputFile, inputElf.ByteOrder, hdr)
	check(err)

	// Get magic
	magicBuff := make([]byte, 0x10)

	_, err = inputFile.ReadAt(magicBuff, 0)
	check(err)

	// Get data type
	dataStr := "2's complement, little endian"

	if inputElf.Data == elf.ELFDATA2MSB {
		dataStr = "2's complement, big endian"
	}

	// Get ELF type
	typeStr := "Unknown"

	switch inputElf.Type {
	case 0xFE00:
		typeStr = "SCE Executable (no ASLR) - 0xFE00"
	case 0xFE10:
		typeStr = "SCE Executable (ASLR) - 0xFE10"
	case 0xFE18:
		typeStr = "SCE Dynamic Library - 0xFE18"
	}

	// Format output
	outputLines := "ELF Header:\n"
	outputLines += fmt.Sprintf("  Magic:   %s\n", encodeToHexStringWithSpaces(magicBuff))
	outputLines += fmt.Sprintf("  Class: %28s%s\n", "", strings.Replace(inputElf.Class.String(), "CLASS", "", 1))
	outputLines += fmt.Sprintf("  Data:  %28s%s\n", "", dataStr)
	outputLines += fmt.Sprintf("  Version: %26s%s\n", "", inputElf.Version.String())
	outputLines += fmt.Sprintf("  OS/ABI: %27s%s\n", "", strings.Replace(inputElf.OSABI.String(), "ELFOSABI_", "", 1))
	outputLines += fmt.Sprintf("  ABI Version: %22s%s\n", "", strconv.Itoa(int(inputElf.ABIVersion)))
	outputLines += fmt.Sprintf("  Type:  %28s%s\n", "", typeStr)
	outputLines += fmt.Sprintf("  Machine: %26s%s\n", "", inputElf.Machine.String())
	outputLines += fmt.Sprintf("  Version: %26s%s\n", "", inputElf.Version.String())
	outputLines += fmt.Sprintf("  Entry point address: %14s%s\n", "", encodeToHexString(inputElf.Entry, false))
	outputLines += fmt.Sprintf("  Start of program headers: %9s%s (bytes into file)\n", "", strconv.Itoa(int(hdr.Phoff)))
	outputLines += fmt.Sprintf("  Start of section headers: %9s%s (bytes into file)\n", "", strconv.Itoa(int(hdr.Shoff)))
	outputLines += fmt.Sprintf("  Flags: %28s%s\n", "", encodeToHexString(uint64(hdr.Flags), false))
	outputLines += fmt.Sprintf("  Size of this header: %14s%s (bytes)\n", "", strconv.Itoa(int(hdr.Ehsize)))
	outputLines += fmt.Sprintf("  Size of program headers: %10s%s (bytes)\n", "", strconv.Itoa(int(hdr.Phentsize)))
	outputLines += fmt.Sprintf("  Number of program headers: %8s%s\n", "", strconv.Itoa(int(hdr.Phnum)))
	outputLines += fmt.Sprintf("  Size of section headers: %10s%s (bytes)\n", "", strconv.Itoa(int(hdr.Shentsize)))
	outputLines += fmt.Sprintf("  Number of section headers: %8s%s\n", "", strconv.Itoa(int(hdr.Shnum)))
	outputLines += fmt.Sprintf("  Section header string table index: %s\n\n", strconv.Itoa(int(hdr.Shstrndx)))

	fmt.Print(outputLines)
}

// printSectionHeaders parses the given inputElf, and prints out all the section header table entries to stdout.
func printSectionHeaders(inputElf *elf.File) {
	// First, check if there even are program headers at all
	if len(inputElf.Sections) == 0 {
		fmt.Printf("There are no sections in this file.\n\n")
		return
	}

	// Header
	outputLines := "Section Headers:\n"
	outputLines += "  [Nr] Name                      Type                Address               Offset\n"
	outputLines += "       Size                      EntSize             Flags    Link  Info   Align\n"

	for i, sectionHeader := range inputElf.Sections {
		// Row 1 (nr, name, type, address, offset)
		outputLines += fmt.Sprintf("  [%2d] %-24s  %-18s  %-18s  %-18s\n",
			i,
			sectionHeader.Name,
			sectionHeader.Type.String(),
			encodeToHexString(sectionHeader.Addr, true),
			encodeToHexString(sectionHeader.Offset, true),
		)

		// Row 2 (size, entsize, flags, link, info, align)
		outputLines += fmt.Sprintf("       %-24s  %-18s  %3s      %4d  %4d   %d\n",
			encodeToHexString(sectionHeader.FileSize, true),
			encodeToHexString(sectionHeader.Entsize, true),
			getSectionFlags(sectionHeader.Flags),
			sectionHeader.Link,
			sectionHeader.Info,
			sectionHeader.Addralign)
	}

	outputLines += "\n"
	fmt.Print(outputLines)
}

// printProgramHeaders parses the given inputElf, and prints out all the program header table entries to stdout.
func printProgramHeaders(inputElf *elf.File) {
	// Theoretically this should **never** happen, but we should cover our bases just in case
	if len(inputElf.Progs) == 0 {
		fmt.Printf("There are no segments in this file.\n\n")
		return
	}

	// Header
	outputLines := "Program Headers:\n"
	outputLines += "  Type             Offset             VirtAddr           PhysAddr\n"
	outputLines += "                   FileSiz            MemSiz             Flags  Align\n"

	for _, progHeader := range inputElf.Progs {
		// Compile the flags string
		flagRead := ' '
		flagWrite := ' '
		flagExec := ' '

		if progHeader.Flags&elf.PF_R != 0 {
			flagRead = 'R'
		}

		if progHeader.Flags&elf.PF_W != 0 {
			flagWrite = 'W'
		}

		if progHeader.Flags&elf.PF_X != 0 {
			flagExec = 'E'
		}

		// Row 1 (type, offset, virtual address, physical address)
		outputLines += fmt.Sprintf("  %-16s %-18s %-18s %-18s\n",
			convertProgramHeaderTypeToString(progHeader.Type),
			encodeToHexString(progHeader.Off, true),
			encodeToHexString(progHeader.Vaddr, true),
			encodeToHexString(progHeader.Paddr, true),
		)

		// Row 2 (file size, mem size, flags, align)
		outputLines += fmt.Sprintf("                   %-18s %-18s %c%c%c    %s\n",
			encodeToHexString(progHeader.Filesz, true),
			encodeToHexString(progHeader.Memsz, true),
			flagRead, flagWrite, flagExec,
			encodeToHexString(progHeader.Align, false),
		)
	}

	outputLines += "\n"
	fmt.Print(outputLines)
}

// printDynamicEntries parses the given inputFile and inputElf, and prints out all the dynamic table entries to stdout.
func printDynamicEntries(inputFile *os.File, inputElf *elf.File) {
	var dynamicSegment *elf.Prog
	var dynlibDataSegment *elf.Prog

	// Check if dynamic segment and the SCE_DynlibData segment exists
	if dynamicSegment = getProgramHeader(inputElf.Progs, elf.PT_DYNAMIC, elf.PF_R|elf.PF_W); dynamicSegment == nil {
		fmt.Printf("There are no dynamic entries in this file.\n\n")
		return
	}

	if dynlibDataSegment = getProgramHeader(inputElf.Progs, PT_SCE_DYNLIBDATA, elf.PF_R); dynlibDataSegment == nil {
		fmt.Printf("Non-Sony ELF's are not supported by this version of readelf for reading dynamic entries.\n\n")
		return
	}

	// Get the entry count based on the class. Technically, the class should **always** be ELFCLASS64, but once again, we
	// cover our bases.
	var entries float64

	switch inputElf.Class {
	case elf.ELFCLASS32:
		entries = float64(dynamicSegment.Filesz) / 8
	case elf.ELFCLASS64:
		entries = float64(dynamicSegment.Filesz) / 16
	}

	// Ensure it's a whole number, because if it's not something's messed up
	if entries != float64(int64(entries)) {
		// Guaranteed to exit
		check(errors.New("dynamic section is not divisible by the dynamic entry size"))
	}

	// Header
	outputLines := fmt.Sprintf("Dynamic section at offset %#x contains %d entries:\n", dynamicSegment.Off, int(entries))
	outputLines += "  Tag (Type)                                 Name/Value\n"

	// We have to do dynamic table parsing manually because for some reason debug/elf doesn't provide that capability
	data := make([]byte, dynamicSegment.Filesz)
	_, _ = inputFile.ReadAt(data[0:], int64(dynamicSegment.Off))

	var stringTable []byte
	var stringTableAddr int64

	for len(data) > 0 {
		var tag elf.DynTag
		var val uint64

		// Get dynamic tag info based on arch
		switch inputElf.Class {
		case elf.ELFCLASS32:
			tag = elf.DynTag(inputElf.ByteOrder.Uint32(data[0:4]))
			val = uint64(inputElf.ByteOrder.Uint32(data[4:8]))
			data = data[8:]

		case elf.ELFCLASS64:
			tag = elf.DynTag(inputElf.ByteOrder.Uint64(data[0:8]))
			val = inputElf.ByteOrder.Uint64(data[8:16])
			data = data[16:]
		}

		// At least in OpenOrbis SDK-built ELFs, the string table tag will always precede any tags that link to strings,
		// and the string table size tag will always proceed the string table tag. We can take advantage of this to set
		// the string table while iterating the dynamic table, specifically on the size tag.
		if tag == DT_SCE_STRTAB {
			stringTableAddr = int64(dynlibDataSegment.Off + val)
		}

		if tag == DT_SCE_STRSZ {
			// Set the string table
			stringTable = make([]byte, val)
			_, _ = inputFile.ReadAt(stringTable, stringTableAddr)
		}

		// Row (tag, tag (string), value)
		outputLines += fmt.Sprintf("  %-18s %-23s %s\n",
			encodeToHexString(uint64(tag), true),
			getDynamicTagType(tag),
			getDynamicTagVal(tag, val, stringTable),
		)
	}

	outputLines += "\n"
	fmt.Print(outputLines)
}

// printRelocations parses the given inputFile and inputElf, and prints out all the relocation table entries to stdout.
func printRelocations(inputFile *os.File, inputElf *elf.File) {
	// First we have to parse the dynamic table to get relocation table information via dynamic tags
	var (
		dynamicSegment    *elf.Prog
		dynlibDataSegment *elf.Prog

		relaDynOffset uint64
		relaDynSize   uint64
		relaPltOffset uint64
		relaPltSize   uint64
	)

	// Check if dynamic segment and the SCE_DynlibData segment exists
	if dynamicSegment = getProgramHeader(inputElf.Progs, elf.PT_DYNAMIC, elf.PF_R|elf.PF_W); dynamicSegment == nil {
		fmt.Printf("There are no relocations in this file.\n\n")
		return
	}

	if dynlibDataSegment = getProgramHeader(inputElf.Progs, PT_SCE_DYNLIBDATA, elf.PF_R); dynlibDataSegment == nil {
		fmt.Printf("Non-Sony ELF's are not supported by this version of readelf for reading relocation entries.\n\n")
		return
	}

	// We have to do dynamic table parsing manually because for some reason debug/elf doesn't provide that capability
	data := make([]byte, dynamicSegment.Filesz)
	_, _ = inputFile.ReadAt(data[0:], int64(dynamicSegment.Off))

	for len(data) > 0 {
		var tag elf.DynTag
		var val uint64

		// Get dynamic tag info based on arch
		switch inputElf.Class {
		case elf.ELFCLASS32:
			tag = elf.DynTag(inputElf.ByteOrder.Uint32(data[0:4]))
			val = uint64(inputElf.ByteOrder.Uint32(data[4:8]))
			data = data[8:]

		case elf.ELFCLASS64:
			tag = elf.DynTag(inputElf.ByteOrder.Uint64(data[0:8]))
			val = inputElf.ByteOrder.Uint64(data[8:16])
			data = data[16:]
		}

		switch tag {
		case DT_SCE_RELA:
			relaDynOffset = val
		case DT_SCE_RELASZ:
			relaDynSize = val
		case DT_SCE_JMPREL:
			relaPltOffset = val
		case DT_SCE_PLTRELSZ:
			relaPltSize = val
		}
	}

	// Print .rela.dyn entries. Ensure .rela.dyn is existant before printing any information related to it.
	if relaDynOffset > 0 && relaDynSize > 0 {
		// These offsets are relative to .sce_dynlib_data, they're not file offsets *yet*, we must make them file offsets
		// by adding the file offset of .sce_dynlib_data to them. We do this post-check as to not incur logic bugs.
		relaDynOffset += dynlibDataSegment.Off

		// Get the entry count based on the class. Technically, the class should **always** be ELFCLASS64, but once again, we
		// cover our bases.
		var entries float64

		switch inputElf.Class {
		case elf.ELFCLASS32:
			entries = float64(relaDynSize) / 0x10
		case elf.ELFCLASS64:
			entries = float64(relaDynSize) / 0x18
		}

		// Ensure it's a whole number, because if it's not something's messed up
		if entries != float64(int64(entries)) {
			// Guaranteed to exit
			check(errors.New(".rela.dyn section is not divisible by the rela entry size"))
		}

		// Header
		outputLines := fmt.Sprintf("Relocation section '.rela.dyn' at offset %#x contains %d entries:\n", relaDynOffset, int(entries))
		outputLines += "  Offset             Info               Type                 Sym.      Addend\n"

		data := make([]byte, relaDynSize)
		_, _ = inputFile.ReadAt(data[0:], int64(relaDynOffset))

		for len(data) > 0 {
			var offset uint64
			var info uint64
			var addend uint64

			// Get dynamic tag info based on arch
			switch inputElf.Class {
			case elf.ELFCLASS32:
				offset = uint64(inputElf.ByteOrder.Uint32(data[0x0:0x4]))
				info = uint64(inputElf.ByteOrder.Uint32(data[0x4:0x8]))
				addend = uint64(inputElf.ByteOrder.Uint32(data[0x8:0xC]))
				data = data[0x10:]

			case elf.ELFCLASS64:
				offset = inputElf.ByteOrder.Uint64(data[0x0:0x8])
				info = inputElf.ByteOrder.Uint64(data[0x8:0x10])
				addend = inputElf.ByteOrder.Uint64(data[0x10:0x18])
				data = data[0x18:]
			}

			// Row (offset, info, info (string), symbol (info >> 32), addend)
			outputLines += fmt.Sprintf("  %-18s %-18s %-20s %-6s %-18s\n",
				encodeToHexString(offset, true),
				encodeToHexString(info, true),
				getRelaType(info),
				encodeToHexString(info>>32, false),
				encodeToHexString(addend, true),
			)
		}

		outputLines += "\n"
		fmt.Print(outputLines)
	} else {
		fmt.Printf("There are no dynamic relocations in this file.\n\n")
	}

	// Print .rela.plt entries. Ensure .rela.plt is existant before printing any information related to it.
	if relaPltOffset > 0 && relaPltSize > 0 {
		// These offsets are relative to .sce_dynlib_data, they're not file offsets *yet*, we must make them file offsets
		// by adding the file offset of .sce_dynlib_data to them. We do this post-check as to not incur logic bugs.
		relaPltOffset += dynlibDataSegment.Off

		// Get the entry count based on the class. Technically, the class should **always** be ELFCLASS64, but once again, we
		// cover our bases.
		var entries float64

		switch inputElf.Class {
		case elf.ELFCLASS32:
			entries = float64(relaPltSize) / 0x10
		case elf.ELFCLASS64:
			entries = float64(relaPltSize) / 0x18
		}

		// Ensure it's a whole number, because if it's not something's messed up
		if entries != float64(int64(entries)) {
			// Guaranteed to exit
			check(errors.New(".rela.plt section is not divisible by the rela entry size"))
		}

		// Header
		outputLines := fmt.Sprintf("Relocation section '.rela.plt' at offset %#x contains %d entries:\n", relaPltOffset, int(entries))
		outputLines += "  Offset             Info               Type                 Sym.      Addend\n"

		data := make([]byte, relaPltSize)
		_, _ = inputFile.ReadAt(data[0:], int64(relaPltOffset))

		for len(data) > 0 {
			var offset uint64
			var info uint64
			var addend uint64

			// Get dynamic tag info based on arch
			switch inputElf.Class {
			case elf.ELFCLASS32:
				offset = uint64(inputElf.ByteOrder.Uint32(data[0x0:0x4]))
				info = uint64(inputElf.ByteOrder.Uint32(data[0x4:0x8]))
				addend = uint64(inputElf.ByteOrder.Uint32(data[0x8:0xC]))
				data = data[0x10:]

			case elf.ELFCLASS64:
				offset = inputElf.ByteOrder.Uint64(data[0x0:0x8])
				info = inputElf.ByteOrder.Uint64(data[0x8:0x10])
				addend = inputElf.ByteOrder.Uint64(data[0x10:0x18])
				data = data[0x18:]
			}

			// Row (offset, info, info (string), symbol (info >> 32), addend)
			outputLines += fmt.Sprintf("  %-18s %-18s %-20s %-6s %-18s\n",
				encodeToHexString(offset, true),
				encodeToHexString(info, true),
				getRelaType(info),
				encodeToHexString(info>>32, false),
				encodeToHexString(addend, true),
			)
		}

		outputLines += "\n"
		fmt.Print(outputLines)
	} else {
		fmt.Printf("There are no PLT relocations in this file.\n\n")
	}
}

// printDynamicSymbols parses the given inputFile and inputElf, and prints out all the dynamic symbol table entries to stdout.
func printDynamicSymbols(inputFile *os.File, inputElf *elf.File) {
	// First we have to parse the dynamic table to get relocation table information via dynamic tags
	var (
		dynamicSegment    *elf.Prog
		dynlibDataSegment *elf.Prog

		symTabOffset uint64
		symTabSize   uint64
	)

	// Check if dynamic segment and the SCE_DynlibData segment exists
	if dynamicSegment = getProgramHeader(inputElf.Progs, elf.PT_DYNAMIC, elf.PF_R|elf.PF_W); dynamicSegment == nil {
		fmt.Printf("There are no symbols in this file.\n\n")
		return
	}

	if dynlibDataSegment = getProgramHeader(inputElf.Progs, PT_SCE_DYNLIBDATA, elf.PF_R); dynlibDataSegment == nil {
		fmt.Printf("Non-Sony ELF's are not supported by this version of readelf for reading symbol entries.\n\n")
		return
	}

	// We have to do dynamic table parsing manually because for some reason debug/elf doesn't provide that capability
	data := make([]byte, dynamicSegment.Filesz)
	_, _ = inputFile.ReadAt(data[0:], int64(dynamicSegment.Off))

	var stringTable []byte
	var stringTableAddr int64

	for len(data) > 0 {
		var tag elf.DynTag
		var val uint64

		// Get dynamic tag info based on arch
		switch inputElf.Class {
		case elf.ELFCLASS32:
			tag = elf.DynTag(inputElf.ByteOrder.Uint32(data[0:4]))
			val = uint64(inputElf.ByteOrder.Uint32(data[4:8]))
			data = data[8:]

		case elf.ELFCLASS64:
			tag = elf.DynTag(inputElf.ByteOrder.Uint64(data[0:8]))
			val = inputElf.ByteOrder.Uint64(data[8:16])
			data = data[16:]
		}

		switch tag {
		case DT_SCE_SYMTAB:
			symTabOffset = val
		case DT_SCE_SYMTABSZ:
			symTabSize = val
		case DT_SCE_STRTAB:
			stringTableAddr = int64(dynlibDataSegment.Off + val)
		case DT_SCE_STRSZ:
			stringTable = make([]byte, val)
			_, _ = inputFile.ReadAt(stringTable, stringTableAddr)
		}
	}

	if symTabOffset > 0 && symTabSize > 0 {
		// These offsets are relative to .sce_dynlib_data, they're not file offsets *yet*, we must make them file offsets
		// by adding the file offset of .sce_dynlib_data to them. We do this post-check as to not incur logic bugs.
		symTabOffset += dynlibDataSegment.Off

		// Get the entry count based on the class. Technically, the class should **always** be ELFCLASS64, but once again, we
		// cover our bases.
		var entries float64

		switch inputElf.Class {
		case elf.ELFCLASS32:
			entries = float64(symTabSize) / 0x10
		case elf.ELFCLASS64:
			entries = float64(symTabSize) / 0x18
		}

		// Ensure it's a whole number, because if it's not something's messed up
		if entries != float64(int64(entries)) {
			// Guaranteed to exit
			check(errors.New(".sym section is not divisible by the symbol entry size"))
		}

		// Header
		outputLines := fmt.Sprintf("Symbol table '.dynsym' at offset %#x contains %d entries:\n", symTabOffset, int(entries))
		outputLines += "  Num:  Value              Size Type    Bind   Vis      Ndx Name\n"

		data := make([]byte, symTabSize)
		_, _ = inputFile.ReadAt(data[0:], int64(symTabOffset))

		i := 0

		for len(data) > 0 {
			var name uint32
			var info uint8
			var val uint64
			var size uint64

			// Get dynamic tag info based on arch
			switch inputElf.Class {
			case elf.ELFCLASS32:
				name = inputElf.ByteOrder.Uint32(data[0x0:0x4])
				val = uint64(inputElf.ByteOrder.Uint32(data[0x4:0x8]))
				size = uint64(inputElf.ByteOrder.Uint32(data[0x8:0xC]))
				info = data[0xC]
				data = data[0x10:]

			case elf.ELFCLASS64:
				name = inputElf.ByteOrder.Uint32(data[0x0:0x4])
				info = data[0x4]
				val = inputElf.ByteOrder.Uint64(data[0x8:0x10])
				size = inputElf.ByteOrder.Uint64(data[0x10:0x18])
				data = data[0x18:]
			}

			symbolName, _ := getString(stringTable, int(name))

			// Row (num, value, size, type, bind, vis, ndx, name)
			outputLines += fmt.Sprintf("  %3s:  %-18s %4s %7s %6s %8s %3s %s\n",
				strconv.Itoa(i),
				encodeToHexString(val, true),
				strconv.Itoa(int(size)),
				getSymbolType(info&0xF),
				getSymbolBind(info>>4),
				"DEFAULT",
				"UND",
				symbolName,
			)

			i++
		}

		outputLines += "\n"
		fmt.Print(outputLines)
	} else {
		fmt.Printf("There are no symbols in this file.\n\n")
	}
}
