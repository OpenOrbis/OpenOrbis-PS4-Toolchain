// This file is a port of flatz' make_fself.py script. Without him this file wouldn't be here.
// Credit for all the fself research goes to flatz :)

package main

import (
	"bytes"
	"crypto/sha256"
	"debug/elf"
	"encoding/binary"
	"encoding/hex"
	"os"
	"strconv"
	"strings"
)

// Default block size
const BLOCK_SIZE = 0x4000

// Magic constants
const SELF_MAGIC_SELF = 0x1D3D154F
const SELF_CONTROL_BLOCK_TYPE_NPDRM = 0x3

// Modes
const SELF_MODE_SPECIFICUSER = 0x1

// Endianness / byte order types
const SELF_DATA_LSB = 0x1

// Property bit shifts
const SELF_ENTRY_PROPERTY_BIT_SIGNED = 2
const SELF_ENTRY_PROPERTY_BIT_HASBLOCKS = 11
const SELF_ENTRY_PROPERTY_BIT_BLOCKSIZE = 12
const SELF_ENTRY_PROPERTY_BIT_HASDIGESTS = 16
const SELF_ENTRY_PROPERTY_BIT_SEGMENT_INDEX = 20

// Struct sizes
const SELF_HEADER_SIZE = 0x20
const SELF_ENTRY_SIZE = 0x50
const SELF_ELF_HEADER_SIZE = 0x40
const SELF_ELF_PROGHEADER_SIZE = 0x38
const SELF_EXTENDED_HEADER_SIZE = 0x40
const SELF_META_FOOTER_SIZE = 0x50
const SELF_NPDRM_BLOCK_SIZE = 0x30
const SELF_META_BLOCK_SIZE = 0x50
const SELF_META_DATA_BLOCK_SIZE = 0x20
const SELF_SIGNATURE_SIZE = 0x100

const SELF_PTYPE_FAKE = 0x1
const SELF_PTYPE_NPDRM_EXEC = 0x4
const SELF_PTYPE_NPDRM_DYNLIB = 0x5
const SELF_PTYPE_SYSTEM_EXEC = 0x8
const SELF_PTYPE_SYSTEM_DYNLIB = 0x9
const SELF_PTYPE_HOST_KERNEL = 0xC
const SELF_PTYPE_SECURE_MODULE = 0xE
const SELF_PTYPE_SECURE_KERNEL = 0xF

// Struct SelfHeader is the SELF file header structure.
type SelfHeader struct {
	Magic      uint32
	Version    uint8
	Mode       uint8
	Endian     uint8
	Attributes uint8
	KeyType    uint32
	HeaderSize uint16
	MetaSize   uint16
	FileSize   uint64
	NumEntries uint16
	Flags      uint16
}

// Struct SelfEntry is the SELF entry structure, which contains metadata information. There are usually two per segment.
type SelfEntry struct {
	Properties uint64
	Offset     uint64
	FileSize   uint64
	MemorySize uint64
}

// Struct SelfEntryInfo is similar to SelfEntry, however it contains a Data field to keep track of segment data.
type SelfEntryInfo struct {
	Properties uint64
	Offset     uint64
	FileSize   uint64
	MemorySize uint64
	Data       *[]byte
}

// Struct SelfNpdrmControlBlock contains the structure for the NPDRM control blow, which includes the type and content ID
type SelfNpdrmControlBlock struct {
	Type      uint16
	Unknown   [0x0E]byte
	ContentID [0x13]byte
	RandomPad [0x0D]byte
}

// Struct SelfExtendedInfo contains app-specific information about the SELF, including the paid type, app type, app/fw
// version, and the sha256 digest.
type SelfExtendedInfo struct {
	Paid       uint64
	Type       uint64
	AppVersion uint64
	FwVersion  uint64
	Digest     [0x20]byte
}

// SelfEntries contains a list of SelfEntryInfo objects so they can be iterated easily.
var SelfEntries []*SelfEntryInfo

// createFself takes a given orbis ELF path, as well as various meta-data parameters, to create an fself for the final
// eboot. Returns error if an issue was encountered in creating the fself, nil otherwise.
func createFself(orbisElfPath string, paid int64, pType string, appVersion int64, fwVersion int64, authInfo string) {
	inputFileBuff := new(bytes.Buffer)

	// Get the file data for getting the digest as well as other parsing
	inputElfFile, err := os.Open(orbisElfPath)
	check(err)

	_, err = inputFileBuff.ReadFrom(inputElfFile)
	check(err)

	err = inputElfFile.Close()
	check(err)

	// Calculate the sha256 digest so we can put it in the extended info header
	sha256Digest := sha256.Sum256(inputFileBuff.Bytes())

	// Open the file as an ELF for parsing
	inputElf, err := elf.Open(orbisElfPath)
	check(err)

	// Open the output file to write to
	outputFilePath := "eboot.bin"

	if TOOL_MODE == "SPRX" {
		outputFilePath = strings.Split(orbisElfPath, ".")[0] + ".prx"
	}

	outputFself, err := os.Create(outputFilePath)
	check(err)

	signature := make([]byte, SELF_SIGNATURE_SIZE)

	if authInfo != "" {
		signature = createSignature(authInfo, paid)
	}

	// Get the header size
	headerSize := SELF_HEADER_SIZE
	headerSize += createSelfEntries(inputElf.Progs)
	headerSize += SELF_ELF_HEADER_SIZE
	headerSize += len(inputElf.Progs) * SELF_ELF_PROGHEADER_SIZE

	headerSize = int(align(uint64(headerSize), 0x10))

	headerSize += SELF_EXTENDED_HEADER_SIZE
	headerSize += SELF_NPDRM_BLOCK_SIZE

	// Process segments
	entryIndex := 0
	offset := uint64(headerSize) + uint64((len(SelfEntries)*SELF_ENTRY_SIZE)+SELF_META_FOOTER_SIZE+SELF_SIGNATURE_SIZE)

	for _, prog := range inputElf.Progs {
		// Skip non-load and non-sce related segments
		if prog.Type != elf.PT_LOAD && prog.Type != PT_SCE_RELRO && prog.Type != PT_SCE_DYNLIBDATA {
			continue
		}

		// Write meta block for the segment (null bytes)
		numBlocks := align(prog.Filesz, BLOCK_SIZE) / BLOCK_SIZE
		metaData := make([]byte, SELF_META_DATA_BLOCK_SIZE*numBlocks)

		SelfEntries[entryIndex].Data = &metaData
		SelfEntries[entryIndex].Offset = offset
		SelfEntries[entryIndex].FileSize = uint64(len(metaData))
		SelfEntries[entryIndex].MemorySize = uint64(len(metaData))

		offset += SelfEntries[entryIndex].FileSize
		offset = align(offset, 0x10)

		// Write data block for the segment (segment data)
		segmentData := make([]byte, prog.Filesz)

		_, err = prog.ReadAt(segmentData, 0)
		check(err)

		SelfEntries[entryIndex+1].Data = &segmentData
		SelfEntries[entryIndex+1].Offset = offset
		SelfEntries[entryIndex+1].FileSize = prog.Filesz
		SelfEntries[entryIndex+1].MemorySize = prog.Filesz

		offset += SelfEntries[entryIndex+1].FileSize
		offset = align(offset, 0x10)

		entryIndex += 2
	}

	fileSize := offset

	// Get the flags for the self
	signedBlockCount := 0x2
	flags := 0x2 | ((signedBlockCount & 0x7) << 4)

	// Write the fake self
	finalFileSize := 0

	finalFileSize += writeSelfHeader(outputFself,
		0,
		SELF_MODE_SPECIFICUSER,
		SELF_DATA_LSB,
		0x12,
		uint16(headerSize),
		fileSize,
		uint16(flags),
	)

	finalFileSize += writeNullPadding(outputFself, finalFileSize, 0x10)
	finalFileSize += writeSelfEntries(outputFself)
	finalFileSize += writeELFHeaders(outputFself, inputElf, inputFileBuff)
	finalFileSize += writeNullPadding(outputFself, finalFileSize, 0x10)
	finalFileSize += writeExtendedInfo(outputFself, pType, uint64(paid), uint64(appVersion), uint64(fwVersion), sha256Digest)
	finalFileSize += writeNpdrmControlBlock(outputFself)
	finalFileSize += writeMetaBlocks(outputFself)
	finalFileSize += writeMetaFooter(outputFself, 0x10000)
	finalFileSize += writeSignature(outputFself, signature)
	finalFileSize += writeSegments(outputFself)

	err = outputFself.Close()
	check(err)
}

// createSelfEntries takes a list of program headers and creates an entry list for them. Empty entries with the expected
// properties are created and inserted into SelfEntries. The Offset, FileSize, MemorySize, and Data fields are set later.
// Returns the number of bytes that consist of SelfEntries.
func createSelfEntries(programHeaders []*elf.Prog) int {
	entryIndex := 0

	for i, prog := range programHeaders {
		// Skip non-load and non-sce related segments
		if prog.Type != elf.PT_LOAD && prog.Type != PT_SCE_RELRO && prog.Type != PT_SCE_DYNLIBDATA {
			continue
		}

		// Create meta entry
		metaEntryProperties := uint64(0)

		// Meta entries are signed and have digests
		metaEntryProperties = setProperty(metaEntryProperties, SELF_ENTRY_PROPERTY_BIT_SIGNED, 1, 1)
		metaEntryProperties = setProperty(metaEntryProperties, SELF_ENTRY_PROPERTY_BIT_HASDIGESTS, 1, 1)
		metaEntryProperties = setProperty(metaEntryProperties, SELF_ENTRY_PROPERTY_BIT_SEGMENT_INDEX, 0xFFFF, uint64(entryIndex+1))

		SelfEntries = append(SelfEntries, &SelfEntryInfo{
			Properties: metaEntryProperties,
			Offset:     0,
			FileSize:   0,
			MemorySize: 0,
		})

		// Create data entry
		dataEntryProperties := uint64(0)

		// Data entries are signed and have data blocks
		dataEntryProperties = setProperty(dataEntryProperties, SELF_ENTRY_PROPERTY_BIT_SIGNED, 1, 1)
		dataEntryProperties = setProperty(dataEntryProperties, SELF_ENTRY_PROPERTY_BIT_HASBLOCKS, 1, 1)
		dataEntryProperties = setProperty(dataEntryProperties, SELF_ENTRY_PROPERTY_BIT_BLOCKSIZE, 0xF, ilog2(BLOCK_SIZE)-12)
		dataEntryProperties = setProperty(dataEntryProperties, SELF_ENTRY_PROPERTY_BIT_SEGMENT_INDEX, 0xFFFF, uint64(i))

		SelfEntries = append(SelfEntries, &SelfEntryInfo{
			Properties: dataEntryProperties,
			Offset:     0,
			FileSize:   0,
			MemorySize: 0,
		})

		entryIndex += 2
	}

	return len(SelfEntries) * SELF_META_DATA_BLOCK_SIZE
}

// createSignature takes the given authinfo and paid parameters and creates a signature for the file. Returns the []byte
// slice containing the signature.
func createSignature(authInfo string, paid int64) []byte {
	signatureBuff := new(bytes.Buffer)
	authInfoBytes := make([]byte, hex.DecodedLen(len(authInfo)))

	_, _ = hex.Decode(authInfoBytes, []byte(authInfo))

	// First 8 bytes are the length of the auth info unpadded, followed by the paid information
	_ = binary.Write(signatureBuff, binary.LittleEndian, uint64(len(authInfoBytes)))
	_ = binary.Write(signatureBuff, binary.LittleEndian, uint64(paid))

	// The first 8 bytes of auth info are trimmed out of the signature
	signatureBuff.Write(authInfoBytes[8:])

	// Pad to 0x100 bytes
	signature := signatureBuff.Bytes()
	writePaddingBytes(&signature, uint64(len(signature)), 0x100)

	return signature
}

// writeSelfHeader takes the given file and attributes, and writes a SelfHeader to it. Returns the number of bytes written.
func writeSelfHeader(file *os.File, version uint8, mode uint8, endian uint8, attr uint8, headerSize uint16, fileSize uint64, flags uint16) int {
	selfHeaderBuff := new(bytes.Buffer)

	selfHeader := SelfHeader{
		Magic:      SELF_MAGIC_SELF,
		Version:    version,
		Mode:       mode,
		Endian:     endian,
		Attributes: attr,
		KeyType:    0x101,
		HeaderSize: headerSize,
		MetaSize:   uint16((len(SelfEntries) * SELF_ENTRY_SIZE) + SELF_META_FOOTER_SIZE + SELF_SIGNATURE_SIZE),
		FileSize:   fileSize,
		NumEntries: uint16(len(SelfEntries)),
		Flags:      flags,
	}

	_ = binary.Write(selfHeaderBuff, binary.LittleEndian, selfHeader)

	writtenBytes, _ := file.Write(selfHeaderBuff.Bytes())
	return writtenBytes
}

// writeSelfEntries takes the given file and writes the list of SelfEntries constructed earlier to it. Returns the number
// of bytes written.
func writeSelfEntries(file *os.File) int {
	selfEntriesBuff := new(bytes.Buffer)

	for _, entry := range SelfEntries {
		selfEntry := SelfEntry{
			Properties: entry.Properties,
			Offset:     entry.Offset,
			FileSize:   entry.FileSize,
			MemorySize: entry.MemorySize,
		}

		_ = binary.Write(selfEntriesBuff, binary.LittleEndian, selfEntry)
	}

	writtenBytes, _ := file.Write(selfEntriesBuff.Bytes())
	return writtenBytes
}

// writeELFHeaders takes a given file and input ELF as well as input ELF data, and writes them to a file. These headers
// include the ELF file header as well as the program headers. Returns the number of bytes written.
func writeELFHeaders(file *os.File, inputFile *elf.File, inputFileData *bytes.Buffer) int {
	elfSegmentHeaders := new(bytes.Buffer)

	// Write the ELF header
	_, _ = file.Write(inputFileData.Bytes()[0:0x40])

	// Write the program headers
	for _, prog := range inputFile.Progs {
		prog64 := elf.Prog64{
			Type:   uint32(prog.Type),
			Flags:  uint32(prog.Flags),
			Off:    prog.Off,
			Vaddr:  prog.Vaddr,
			Paddr:  prog.Paddr,
			Filesz: prog.Filesz,
			Memsz:  prog.Memsz,
			Align:  prog.Align,
		}

		_ = binary.Write(elfSegmentHeaders, binary.LittleEndian, prog64)
	}

	writtenBytes, _ := file.Write(elfSegmentHeaders.Bytes())
	return writtenBytes
}

// writeExtendedInfo takes a given file and various app parameters, and writes the SelfExtendedInfo header to it. Returns
// the number of bytes written.
func writeExtendedInfo(file *os.File, pType string, paid uint64, appVersion uint64, fwVersion uint64, digest [0x20]byte) int {
	programType := uint64(SELF_PTYPE_FAKE)
	extendedHeaderBuff := new(bytes.Buffer)

	// Get the type from user argument
	switch pType {
	case "npdrm_exec":
		programType = SELF_PTYPE_NPDRM_EXEC
	case "npdrm_dynlib":
		programType = SELF_PTYPE_NPDRM_DYNLIB
	case "system_exec":
		programType = SELF_PTYPE_SYSTEM_EXEC
	case "system_dynlib":
		programType = SELF_PTYPE_SYSTEM_DYNLIB
	case "host_kernel":
		programType = SELF_PTYPE_HOST_KERNEL
	case "secure_module":
		programType = SELF_PTYPE_SECURE_MODULE
	case "secure_kernel":
		programType = SELF_PTYPE_SECURE_KERNEL
	}

	extendedHeader := SelfExtendedInfo{
		Paid:       paid,
		Type:       programType,
		AppVersion: appVersion,
		FwVersion:  fwVersion,
		Digest:     digest,
	}

	_ = binary.Write(extendedHeaderBuff, binary.LittleEndian, extendedHeader)

	writtenBytes, _ := file.Write(extendedHeaderBuff.Bytes())
	return writtenBytes
}

// writeNpdrmControlBlock takes a given file and writes the Npdrm control block header to it. Currently, this contains
// null data. Returns the number of bytes written.
func writeNpdrmControlBlock(file *os.File) int {
	controlBlockBuff := new(bytes.Buffer)

	controlBlock := SelfNpdrmControlBlock{
		Type: SELF_CONTROL_BLOCK_TYPE_NPDRM,
	}

	_ = binary.Write(controlBlockBuff, binary.LittleEndian, controlBlock)

	writtenBytes, _ := file.Write(controlBlockBuff.Bytes())
	return writtenBytes
}

// writeMetaBlocks takes a given file and writes a list of MetaBlocks for each SelfEntry to it. Currently, these blocks
// contain NULL data. Returns the number of bytes written.
func writeMetaBlocks(file *os.File) int {
	metaBlocks := make([]byte, SELF_META_BLOCK_SIZE*len(SelfEntries))

	writtenBytes, _ := file.Write(metaBlocks)
	return writtenBytes
}

// writeMetaFooter takes a given file and value, and writes a MetaFooter struct to it.  Returns the number of bytes written.
func writeMetaFooter(file *os.File, val uint32) int {
	metaFooterBuff := new(bytes.Buffer)

	metaFooterPad1 := make([]byte, 0x30)
	metaFooterPad2 := make([]byte, 0x1C)

	_ = binary.Write(metaFooterBuff, binary.LittleEndian, metaFooterPad1)
	_ = binary.Write(metaFooterBuff, binary.LittleEndian, val)
	_ = binary.Write(metaFooterBuff, binary.LittleEndian, metaFooterPad2)

	writtenBytes, _ := file.Write(metaFooterBuff.Bytes())
	return writtenBytes
}

// writeSignature takes a given file and signature, and writes that signature into the file. Returns the number of bytes written.
func writeSignature(file *os.File, signature []byte) int {
	writtenBytes, _ := file.Write(signature)
	return writtenBytes
}

// writeSegments takes a given file and iterates the SelfEntries list to write segment data to the file using it's offset
// value. Returns the number of bytes written.
func writeSegments(file *os.File) int {
	writtenBytes := 0

	for _, entry := range SelfEntries {
		writtenBytesEntry, _ := file.WriteAt(*entry.Data, int64(entry.Offset))
		writtenBytes += writtenBytesEntry
	}

	return writtenBytes
}

// writeNullPadding is a utility function that writes null bytes to the given file to a given align. Returns the number
// of bytes written.
func writeNullPadding(file *os.File, size int, align int) int {
	padNum := -size & (align - 1)
	padding := make([]byte, padNum)

	writtenBytes, _ := file.Write(padding)
	return writtenBytes
}

// align takes a given int and aligns it to a given value. Returns the aligned value.
func align(val uint64, align uint64) uint64 {
	return (val + (align - 1)) & ^(align - 1)
}

// ilog2 takes a given value and does a log2 on it as a 64-bit value. Returns the log'd value as a uint64.
func ilog2(val uint64) uint64 {
	// Perform the log2 based on the length of the binary representation of the value
	lenOfBin := len(strconv.FormatInt(int64(val), 2))

	// Subtract one to account for leading byte
	return uint64(lenOfBin - 1)
}

// setProperty takes a given property, bit shift, mask, and value, and applies the value to it. Returns the new property.
func setProperty(property uint64, bit uint64, mask uint64, val uint64) uint64 {
	property |= (val & mask) << bit
	return property
}
