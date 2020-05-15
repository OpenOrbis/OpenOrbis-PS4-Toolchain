package main

import (
	"bytes"
	"crypto/sha1"
	"debug/elf"
	"encoding/base64"
	"encoding/binary"
	"encoding/hex"
	"io"
	"path/filepath"
	"strings"
)

// Const nidSuffixKey holds the suffix appended to the end of symbol names before calculating the NID hash.
const nidSuffixKey = "518D64A635DED8C1E6B039B1C3E55230"

// Const indexEncodingTable provides the encoding table for module indices that are appended to the end of NIDs.
const indexEncodingTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Struct TableOffsets holds all necessary offsets and sizes of various tables that are referenced by the dynamic table.
type TableOffsets struct {
	linkingTable      uint64
	linkingTableSz    uint64
	stringTable       uint64
	stringTableSz     uint64
	symbolTable       uint64
	symbolTableSz     uint64
	jumpTable         uint64
	relocationTable   uint64
	relocationTableSz uint64
	hashTable         uint64
	hashTableSz       uint64
	dynamicTable      uint64
	dynamicTableSz    uint64
}

// moduleToLibDictionary contains a mapping of module names to library (prx) paths
var moduleToLibDictionary = map[string]string{
	"libc":                       "libc.prx",
	"libkernel":                  "libkernel.prx",
	"libSceAjm":                  "libSceAjm.prx",
	"libSceAppContent":           "libSceAppContent.prx",
	"libSceAudio3d":              "libSceAudio3d.prx",
	"libSceAudioIn":              "libSceAudioIn.prx",
	"libSceAudioOut":             "libSceAudioOut.prx",
	"libSceAvSetting":            "libSceAvSetting.prx",
	"libSceCamera":               "libSceCamera.prx",
	"libSceCommonDialog":         "libSceCommonDialog.prx",
	"libSceConvertKeycode":       "libSceConvertKeycode.prx",
	"libSceFios2":                "libSceFios2.prx",
	"libSceFont":                 "libSceFont-module.prx",
	"libSceFontFt":               "libSceFontFt-module.prx",
	"libSceGameCustomDataDialog": "libSceGameCustomDataDialog.prx",
	"libSceGnmDriver":            "libSceGnmDriver.prx",
	"libSceHttp":                 "libSceHttp.prx",
	"libSceInvitationDialog":     "libSceInvitationDialog.prx",
	"libSceJpegDec":              "libSceJpegDec.prx",
	"libSceJpegEnc":              "libSceJpegEnc.prx",
	"libSceKeyboard":             "libSceKeyboard.prx",
	"libSceMouse":                "libSceMouse.prx",
	"libSceNetCtl":               "libSceNetCtl.prx",
	"libSceNpCommon":             "libSceNpCommon.prx",
	"libSceNpParty":              "libSceNpParty.prx",
	"libSceNpTrophy":             "libSceNpTrophy.prx",
	"libSceNpUtility":            "libSceNpUtility.prx",
	"libScePad":                  "libScePad.prx",
	"libScePadTracker":           "libScePadTracker.prx",
	"libScePlayReady":            "libScePlayReady.prx",
	"libScePngDec":               "libScePngDec.prx",
	"libScePngEnc":               "libScePngEnc.prx",
	"libSceSaveData":             "libSceSaveData.prx",
	"libSceSaveDataDialog":       "libSceSaveDataDialog.prx",
	"libSceScreenShot":           "libSceScreenShot.prx",
	"libSceShareUtility":         "libSceShareUtility.prx",
	"libSceSsl":                  "libSceSsl.prx",
	"libSceSystemService":        "libSceSystemService.prx",
	"libSceSysmodule":            "libSceSysmodule.prx",
	"libSceSysUtil":              "libSceSysUtil.prx",
	"libSceUserService":          "libSceUserService.prx",
	"libSceVideodec":             "libSceVideodec.prx",
	"libSceVideoCoreInterface":   "libSceVideoCoreInterface.prx",
	"libSceVideoOut":             "libSceVideoOut.prx",
	"libSceVoice":                "libSceVoice.prx",
	"libSceWebBrowserDialog":     "libSceWebBrowserDialog.prx",
	"libSceZlib":                 "libSceZlib.prx",
	"libSceFreeType":             "libSceFreeType.prx",
}

var (
	libraryOffsets []uint64
	moduleOffsets  []uint64

	offsetOfProjectName uint64
	offsetOfFileName    uint64
	offsetOfNidTable    uint64
	offsetOfDynlibData  uint64
	offsetOfDynamic     uint64

	sizeOfDynlibData uint64
	sizeOfDynamic    uint64

	sizeOfStrTable uint64

	needSceLibcIndex int
	numHashEntries   int
)

////
// Dynlib Data Generation
////

// OrbisElf.GenerateLibrarySymbolDictionary parses the input ELF for any libraries as well as symbols it needs from shared
// libraries, and creates a dictionary of library names to symbol lists for later use. Returns an error if a library failed
// to open, or if we failed to get a symbol list for any library, nil otherwise.
func (orbisElf *OrbisElf) GenerateLibrarySymbolDictionary() error {
	var libraryObjs []*elf.File

	orbisElf.ModuleSymbolDictionary = NewOrderedMap()

	// Get all the imported libraries, create dictionary keys for them, and open them for symbol searching
	libraries, err := orbisElf.ElfToConvert.ImportedLibraries()

	if err != nil {
		return err
	}

	// Swap libkernel with the first library to ensure it comes before anything else
	for i, library := range libraries {
		if library == "libkernel.so" {
			libraries[i] = libraries[0]
			libraries[0] = "libkernel.so"

			break
		}
	}

	// Ensure libkernel is the first library
	if libraryObj, err := elf.Open(sdkPath + "/lib/libkernel.so"); err == nil {
		libraryObjs = append(libraryObjs, libraryObj)
		orbisElf.ModuleSymbolDictionary.Set("libkernel", []string{})
	} else {
		return err
	}

	// Create the list of libraries
	for _, library := range libraries {
		// Skip libkernel as it's already there
		if library == "libkernel.so" {
			continue
		}

		// Open the library file for parsing
		if libraryObj, err := elf.Open(sdkPath + "/lib/" + library); err == nil {
			libraryObjs = append(libraryObjs, libraryObj)
		} else {
			return err
		}

		// Add it to the dictionary
		purifiedLibrary := strings.Replace(library, ".so", "", 1)
		orbisElf.ModuleSymbolDictionary.Set(purifiedLibrary, []string{})
	}

	// Iterate the symbol table and cross-reference the shared object files to find which library they belong to, and
	// add them to the dictionary.
	symbols, err := orbisElf.ElfToConvert.Symbols()

	if err != nil {
		return err
	}

	// Add symbol lists to the library dictionary
	for _, symbol := range symbols {
		symbolName := symbol.Name

		// Skip _DYNAMIC
		if symbolName == "_DYNAMIC" {
			continue
		}

		// Check all linked libraries for the symbol
		for i, libraryObj := range libraryObjs {
			foundSymbol, err := checkIfLibraryContainsSymbol(libraryObj, symbolName)

			// We need to check error because if we just let it slide, we could end up with mis-alignments later, which
			// would cause really shitty bugs that would be hard to debug.
			if err != nil {
				return err
			}

			// Found it? Add it
			if foundSymbol {
				library := strings.Replace(libraries[i], ".so", "", 1)

				symbolList := orbisElf.ModuleSymbolDictionary.Get(library).([]string)
				symbolList = append(symbolList, symbolName)

				orbisElf.ModuleSymbolDictionary.Set(library, symbolList)
			}
		}
	}

	return nil
}

// OrbisElf.GenerateDynlibData generates the .sce_dynlib_data segment at the end of the file via the given sizeOfFile.
// Returns an error if an issue was encountered generating the segment, nil otherwise.
func (orbisElf *OrbisElf) GenerateDynlibData(sizeOfFile uint64) error {
	var segmentData []byte
	var segmentSize uint64
	var err error

	// Parse symbol information to create a dictionary of libraries to symbols
	if err = orbisElf.GenerateLibrarySymbolDictionary(); err != nil {
		return err
	}

	segmentSize = 0
	tableOffsets := TableOffsets{}

	// Get PLT information for dynamic table generation later
	if tableOffsets.linkingTable, err = orbisElf.getDynamicTag(elf.DT_PLTGOT); err != nil {
		return err
	}

	if tableOffsets.linkingTableSz, err = orbisElf.getDynamicTag(elf.DT_PLTRELSZ); err != nil {
		return err
	}

	offsetOfDynlibData = sizeOfFile

	// Write the fingerprint
	segmentSize += writeFingerprint("OPENORBIS-HOMEBREW", &segmentData)

	// Write linking tables
	tableOffsets.stringTable = segmentSize
	tableOffsets.stringTableSz = writeStringTable(orbisElf, orbisElf.ElfToConvertName, orbisElf.LibraryName, orbisElf.ModuleSymbolDictionary, &segmentData)
	segmentSize += tableOffsets.stringTableSz

	// Align to 0x8 byte boundary
	segmentSize += writePaddingBytes(&segmentData, segmentSize, 0x8)

	tableOffsets.symbolTable = segmentSize
	tableOffsets.symbolTableSz = writeSymbolTable(orbisElf, &segmentData)
	segmentSize += tableOffsets.symbolTableSz

	// We can pre-calculate the location of the relocation table by using the PLTRELSZ. Since rela entries and symbol
	// entries are the same size, the offset will match.
	tableOffsets.jumpTable = segmentSize

	tableOffsets.relocationTable = segmentSize + tableOffsets.linkingTableSz
	tableOffsets.relocationTableSz = writeRelocationTable(orbisElf, &segmentData)

	segmentSize += tableOffsets.relocationTableSz

	// The relocation table size must omit the jump table, so we'll subtract the size of the jump table from the relocation
	// table size.
	tableOffsets.relocationTableSz -= tableOffsets.linkingTableSz

	tableOffsets.hashTable = segmentSize
	tableOffsets.hashTableSz = writeHashTable(&segmentData)
	segmentSize += tableOffsets.hashTableSz

	// Align to 0x10 byte boundary
	segmentSize += writePaddingBytes(&segmentData, segmentSize, 0x10)

	// Write dynamic table
	tableOffsets.dynamicTable = segmentSize
	tableOffsets.dynamicTableSz = writeDynamicTable(&tableOffsets, &segmentData)
	segmentSize += tableOffsets.dynamicTableSz

	offsetOfDynamic = offsetOfDynlibData + tableOffsets.dynamicTable
	sizeOfDynamic = tableOffsets.dynamicTableSz
	sizeOfDynlibData = segmentSize

	_, err = orbisElf.FinalFile.WriteAt(segmentData, int64(sizeOfFile))
	return err
}

// writeFingerprint writes a given fingerprint to segmentData
func writeFingerprint(fingerprint string, segmentData *[]byte) uint64 {
	fingerprintSize := uint64(0x18)
	interpreterBuff := make([]byte, fingerprintSize)

	copy(interpreterBuff[:], fingerprint)
	*segmentData = append(*segmentData, interpreterBuff...)

	return fingerprintSize
}

////
// String table generation
////

// writeStringTable writes the module table, project meta data, and NID table to segmentData. Returns the number of bytes
// written.
func writeStringTable(orbisElf *OrbisElf, projectName string, libName string, moduleSymbolDictionary *OrderedMap, segmentData *[]byte) uint64 {
	sizeOfStrTable = 0
	
	// Write the first null module entry
	writeNullBytes(segmentData, 1)

	sizeOfStrTable += writeModuleTable(moduleSymbolDictionary, segmentData)
	offsetOfProjectName = sizeOfStrTable + 1 // Account for null entry

	sizeOfStrTable += writeProjectMetaData(projectName, libName, segmentData)
	offsetOfNidTable = sizeOfStrTable + 1 // Account for null entry

	sizeOfStrTable += writeNIDTable(orbisElf, segmentData)

	if TOOL_MODE == "SPRX" {
		sizeOfStrTable += writeModuleStrings(segmentData)
	}

	return sizeOfStrTable + 1 // Account for null entry
}

// writeModuleTable writes the module string table using the given moduleSymbolDictionary to segmentData. Returns the
// number of bytes written.
func writeModuleTable(moduleSymbolDictionary *OrderedMap, segmentData *[]byte) uint64 {
	moduleTableBuff := new(bytes.Buffer)

	modules := moduleSymbolDictionary.Keys()

	// Write library list
	for _, module := range modules {
		moduleStr := module.(string)
		moduleStr = strings.Replace(moduleStr, "_stub", "", 1)

		// Record the offset of the library for processing later
		libName := moduleToLibDictionary[moduleStr]

		if libName == "" {
			libName = moduleStr + ".prx"
		}

		libName += "\x00"

		libOffset := uint64(len(moduleTableBuff.Bytes())) + 1

		// Add to the table
		libraryOffsets = append(libraryOffsets, libOffset)
		moduleTableBuff.WriteString(libName)
	}

	// Write module list
	for _, module := range modules {
		moduleStr := module.(string)
		moduleStr = strings.Replace(moduleStr, "_stub", "", 1)

		// Record the offset of the library for processing later
		moduleName := moduleStr + "\x00"
		moduleOffset := uint64(len(moduleTableBuff.Bytes())) + 1

		// Add to the table
		moduleOffsets = append(moduleOffsets, moduleOffset)
		moduleTableBuff.WriteString(moduleName)
	}

	// The filename of the project will proceed these entries in the string table, and is needed for dynamic table
	// generation, so we'll record it here.
	offsetOfFileName = uint64(len(moduleTableBuff.Bytes())) + 1

	// Commit to segment data
	*segmentData = append(*segmentData, moduleTableBuff.Bytes()...)
	return uint64(len(moduleTableBuff.Bytes()))
}

// writeProjectMetaData writes the file name and project name to segmentData. Returns the number of bytes written.
func writeProjectMetaData(fileName string, libName string, segmentData *[]byte) uint64 {
	projectMetaBuff := new(bytes.Buffer)

	projectName := filepath.Base(fileName)
	projectName = strings.Replace(projectName, filepath.Ext(fileName), "", -1)

	// The module name will be either
	// 1) the libName is given, or, if none is given,
	// 2) the file name without the path'ing or extension
	if libName != "" {
		projectName = libName
	}

	// Write the module name
	projectMetaBuff.WriteString(projectName + "\x00")

	// Record the offset of the file name, then write the file name
	offsetOfFileName += uint64(len(projectMetaBuff.Bytes()))
	projectMetaBuff.WriteString(fileName + "\x00")
	
	// Commit to segment data
	*segmentData = append(*segmentData, projectMetaBuff.Bytes()...)
	return uint64(len(projectMetaBuff.Bytes()))
}

// writeModuleStrings writes the file name and project name to segmentData. Returns the number of bytes written.
func writeModuleStrings(segmentData *[]byte) uint64 {
	moduleStringBuff := new(bytes.Buffer)

	// These tags will always be "module_stop" and "module_start", in that order
	moduleStop := "module_stop" + "\x00"
	moduleStart := "module_start" + "\x00"

	moduleStringBuff.WriteString(moduleStop)
	moduleStringBuff.WriteString(moduleStart)

	// Commit to segment data
	*segmentData = append(*segmentData, moduleStringBuff.Bytes()...)
	return uint64(len(moduleStringBuff.Bytes()))
}

// writeNIDTable uses the given module to symbol dictionary created earlier to generate and write a table of NIDs to
// segmentData. Returns the number of bytes written.
func writeNIDTable(orbisElf *OrbisElf, segmentData *[]byte) uint64 {
	nidTableBuff := new(bytes.Buffer)

	// Iterate the symbol table of the input ELF to generate entries. We don't need to check err here because we've already
	// checked it before we reach this point.
	symbols, _ := orbisElf.ElfToConvert.DynamicSymbols()
	modules := orbisElf.ModuleSymbolDictionary.Keys()
	moduleIndex := 0

	// Get libc index for Need_sceLibc
	libcModuleIndex := 0

	for _, module := range modules {
		if module == "libc" {
			break
		}

		libcModuleIndex++
	}

	// Each symbol will need an NID entry
	for _, symbol := range symbols {
		moduleIndex = 0

		// Check which library this symbol is from
		for _, module := range modules {
			moduleSymbols := orbisElf.ModuleSymbolDictionary.Get(module).([]string)

			if contains(moduleSymbols, symbol.Name) {
				break
			}

			moduleIndex++
		}

		// Build the NID and insert it into the table
		nidTableBuff.WriteString(buildNIDEntry(symbol.Name, moduleIndex, false))
	}

	// Add an additional symbol for Need_sceLibc
	nidTableBuff.WriteString(buildNIDEntry("Need_sceLibc", libcModuleIndex, false))

	// Add exported symbols for libraries
	if TOOL_MODE == "SPRX" {
		moduleSymbols, _ := orbisElf.ElfToConvert.Symbols()

		for _, symbol := range moduleSymbols {
			// Only export global symbols that we have values for
			if (symbol.Info >> 4 & uint8(elf.STB_GLOBAL)) == uint8(elf.STB_GLOBAL) && symbol.Value != 0 {
				nidTableBuff.WriteString(buildNIDEntry(symbol.Name, moduleIndex + 1, true))
			}
		}
	}

	// Commit to segment data
	*segmentData = append(*segmentData, nidTableBuff.Bytes()...)
	return uint64(len(nidTableBuff.Bytes()))
}

// buildNIDEntry is a helper function that takes a symbolName and moduleIndex to construct an NID entry for the string table.
// If exported is set to true, the library index is overwritten with 0. Returns the final constructed string of the NID entry.
func buildNIDEntry(symbolName string, moduleIndex int, exported bool) string {
	nid := calculateNID(symbolName)

	// Module index will always be the library index + 1, since module indexing is one-based where library indexing is
	// zero-based.
	libraryIndex := moduleIndex + 1

	if exported {
		libraryIndex = 0
	}

	// Format: [NID Hash] + '#' + [Module Index] + '#' + [Library Index]
	moduleIndexChar := string(indexEncodingTable[moduleIndex])
	libraryIndexChar := string(indexEncodingTable[libraryIndex])

	nid += "#" + moduleIndexChar + "#" + libraryIndexChar + "\x00"
	return nid
}

// calculateNID is a helper function that takes a symbolName and calculates the NID hash using a sha1 of the symbol name
// with the suffix key appended to it. Returns the string of the NID hash base64'd.
func calculateNID(symbolName string) string {
	// Here's a brief overview of how NID's are calculated:
	//    1) Symbol plaintext name + a hardcoded suffix defined as nidSuffixKey is sha1 hashed
	// 	  2) The first 8 bytes of this hash are read as a uint64 (big endian)
	// 	  3) This uint64 is then base64 encoded, and this base64 excluding the padded '=' is the NID
	hashBytes := make([]byte, 8)
	suffix, _ := hex.DecodeString(nidSuffixKey)

	symbol := append([]byte(symbolName), suffix...)
	hash := sha1.Sum(symbol)

	// The order of the bytes has to be reversed. We can hack big endian to do this.
	binary.LittleEndian.PutUint64(hashBytes, binary.BigEndian.Uint64(hash[:8]))

	// The final NID is the hash bytes base64'd with the last '=' character removed
	nidHash := base64.StdEncoding.EncodeToString(hashBytes)
	nidHash = nidHash[0 : len(nidHash)-1]

	//  We also need to replace all forward slashes with dashes for encoding reasons
	nidHash = strings.Replace(nidHash, "/", "-", -1)

	return nidHash
}

////
// Symbol, relocation, and hash table generation
////

// writeSymbolTable uses the input ELF symbols to generate and write the symbol table to segmentData. Returns the number
// of bytes written.
func writeSymbolTable(orbisElf *OrbisElf, segmentData *[]byte) uint64 {
	symbolTableBuff := new(bytes.Buffer)

	// Add no type entry
	_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{})

	// Add section entry
	_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{
		Info: uint8(elf.STT_SECTION),
	})

	// Add external symbol entries
	numSymbols := 0
	numExportedSymbols := 0
	symbols, _ := orbisElf.ElfToConvert.DynamicSymbols()

	for _, symbol := range symbols {
		if symbol.Name != "" {
			_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{
				Name: uint32(offsetOfNidTable + uint64(numSymbols*0x10)),
				Info: symbol.Info,
			})

			numSymbols++
		}
	}

	needSceLibcIndex = numSymbols

	// Add Need_sceLibc entry
	_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{
		Name: uint32(offsetOfNidTable + uint64((needSceLibcIndex)*0x10)),
		Info: (uint8(elf.STB_GLOBAL) << 4) | uint8(elf.STT_OBJECT),
	})
	
	numSymbols++

	// Add exported symbols for libraries
	if TOOL_MODE == "SPRX" {
		moduleSymbols, _ := orbisElf.ElfToConvert.Symbols()

		for _, symbol := range moduleSymbols {
			// Only export global symbols that we have values for
			if (symbol.Info >> 4 & uint8(elf.STB_GLOBAL)) == uint8(elf.STB_GLOBAL) && symbol.Value != 0 {
				_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{
					Name: uint32(offsetOfNidTable + uint64(numSymbols*0x10)),
					Info: symbol.Info,
					Other: symbol.Other,
					Value: symbol.Value,
					Size: symbol.Size,
					Shndx: uint16(symbol.Section),
				})
				
				numSymbols++
				numExportedSymbols++
			}
		}
	}

	// Add module weak symbols (libraries only)
	if TOOL_MODE == "SPRX" {
		moduleStopOffset := ((numSymbols) * 0x10)
		moduleStartOffset := moduleStopOffset + len("module_stop"+"\x00")

		_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{
			Name: uint32(offsetOfNidTable + uint64(moduleStopOffset)),
			Info: uint8(elf.STB_WEAK) << 4,
		})

		_ = binary.Write(symbolTableBuff, binary.LittleEndian, elf.Sym64{
			Name: uint32(offsetOfNidTable + uint64(moduleStartOffset)),
			Info: uint8(elf.STB_WEAK) << 4,
		})

		numExportedSymbols += 2
	}

	sizeOfTable := uint64(len(symbolTableBuff.Bytes()))
	numHashEntries = int(sizeOfTable / 0x18)

	// In the case of libraries, the exported symbols don't have hash entries, so we must account for this.
	//if TOOL_MODE == "SPRX" {
	//	//numHashEntries -= numExportedSymbols
	//}

	// Commit to segment data
	*segmentData = append(*segmentData, symbolTableBuff.Bytes()...)
	return sizeOfTable
}

// writeRelocationTable uses the input ELF's Procedure Linkage Table (PLT) as well as .data.rel.ro and .sce_process_param
// to write a table of relocation / rela entries to segmentData. Returns the number of bytes written.
func writeRelocationTable(orbisElf *OrbisElf, segmentData *[]byte) uint64 {
	relocationTableBuff := new(bytes.Buffer)

	// Get the old relocation procedure linkage table
	if oldRelaPltTableSection := orbisElf.ElfToConvert.Section(".rela.plt"); oldRelaPltTableSection != nil {
		oldRelaPltTableData, err := oldRelaPltTableSection.Data()

		if err != nil {
			return 0
		}

		// Add entries from the old relocation PLT table - jump slots / PLT entries
		for len(oldRelaPltTableData) > 0 {
			rOffset := orbisElf.ElfToConvert.ByteOrder.Uint64(oldRelaPltTableData[0x0:0x8])
			rInfo := orbisElf.ElfToConvert.ByteOrder.Uint64(oldRelaPltTableData[0x8:0x10])
			rAddend := orbisElf.ElfToConvert.ByteOrder.Uint64(oldRelaPltTableData[0x10:0x18])

			oldRelaPltTableData = oldRelaPltTableData[0x18:]

			_ = binary.Write(relocationTableBuff, binary.LittleEndian, elf.Rela64{
				Off:    rOffset,
				Info:   rInfo + (1 << 32), // Add one to the symbol index to account for STT_SECTION
				Addend: int64(rAddend),
			})
		}
	}

	// Get the old relocation dynamic table
	if oldRelaDynTableSection := orbisElf.ElfToConvert.Section(".rela.dyn"); oldRelaDynTableSection != nil {
		oldRelaDynTableData, err := oldRelaDynTableSection.Data()

		if err != nil {
			return 0
		}

		// Add entries from the old relocation dynamic table - relative entries
		for len(oldRelaDynTableData) > 0 {
			rOffset := orbisElf.ElfToConvert.ByteOrder.Uint64(oldRelaDynTableData[0x0:0x8])
			rInfo := orbisElf.ElfToConvert.ByteOrder.Uint64(oldRelaDynTableData[0x8:0x10])
			rAddend := orbisElf.ElfToConvert.ByteOrder.Uint64(oldRelaDynTableData[0x10:0x18])

			oldRelaDynTableData = oldRelaDynTableData[0x18:]

			_ = binary.Write(relocationTableBuff, binary.LittleEndian, elf.Rela64{
				Off:    rOffset,
				Info:   rInfo,
				Addend: int64(rAddend),
			})
		}
	}

	sceNeedLibc := orbisElf.getSymbol("_sceLibc")

	if TOOL_MODE == "SELF" {
		// Add entries for Need_sceLibc
		sceLibcParamSym := orbisElf.getSymbol("_sceLibcParam")

		// _sceLibcParam->Need_sceLibc
		writeObjectRelaEntry(relocationTableBuff, sceLibcParamSym.Value+0x48, needSceLibcIndex+2)
	}

	// .data->Need_sceLibc0
	writeObjectRelaEntry(relocationTableBuff, sceNeedLibc.Value, needSceLibcIndex+2)

	// Commit to segment data
	*segmentData = append(*segmentData, relocationTableBuff.Bytes()...)
	return uint64(len(relocationTableBuff.Bytes()))
}

// writeHashTable uses numHashEntries which was set when constructing the symbol table to write the hash table to
// segmentData. Returns the number of bytes written.
func writeHashTable(segmentData *[]byte) uint64 {
	hashTableBuff := new(bytes.Buffer)

	// The hash table consists of buckets and chains to make accessing into the symbol table quicker. The way Sony
	// calculates the buckets is insanity and doesn't match up with standard ELF's - so we're going to do a bit of a hack.
	// We're going to put all the symbols into one bucket and just have one chain for all the symbols (for now at least).

	// Marked for potential future update.
	hashTableInfo := SceHashTable{
		nbucket: 1,
		nchain:  uint32(numHashEntries),
	}

	_ = binary.Write(hashTableBuff, binary.LittleEndian, hashTableInfo)

	// Write chain entries
	for i := 0; i < numHashEntries; i++ {
		// Each entry contains the index of the next entry, so add 1 for all entries except the last entry.
		if i != numHashEntries-1 {
			_ = binary.Write(hashTableBuff, binary.LittleEndian, uint32(i+1))
		} else {
			// On the last entry, write a 0 to note the end of the chain.
			_ = binary.Write(hashTableBuff, binary.LittleEndian, uint32(0))
		}
	}

	// Commit to segment data
	*segmentData = append(*segmentData, hashTableBuff.Bytes()...)
	return uint64(len(hashTableBuff.Bytes()))
}

// writeDynamicTable uses the given tableOffsets object and various other globals to write the dynamic table to segmentData.
// Returns the number of bytes written.
func writeDynamicTable(tableOffsets *TableOffsets, segmentData *[]byte) uint64 {
	dynamicTableBuff := new(bytes.Buffer)

	// Hash table
	writeDynamicEntry(dynamicTableBuff, DT_SCE_HASH, tableOffsets.hashTable)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_HASHSZ, tableOffsets.hashTableSz)

	// String table
	writeDynamicEntry(dynamicTableBuff, DT_SCE_STRTAB, tableOffsets.stringTable)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_STRSZ, tableOffsets.stringTableSz)

	// Symbol table
	writeDynamicEntry(dynamicTableBuff, DT_SCE_SYMTAB, tableOffsets.symbolTable)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_SYMTABSZ, tableOffsets.symbolTableSz)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_SYMENT, 0x18)

	// Relocation table
	writeDynamicEntry(dynamicTableBuff, DT_SCE_RELA, tableOffsets.relocationTable)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_RELASZ, tableOffsets.relocationTableSz)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_RELAENT, 0x18)

	// PLT
	writeDynamicEntry(dynamicTableBuff, DT_SCE_PLTGOT, tableOffsets.linkingTable)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_PLTRELSZ, tableOffsets.linkingTableSz)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_PLTREL, uint64(elf.DT_RELA))
	writeDynamicEntry(dynamicTableBuff, DT_SCE_JMPREL, tableOffsets.jumpTable)

	// Debugging-related tags
	writeDynamicEntry(dynamicTableBuff, uint64(elf.DT_DEBUG), 0)
	
	if TOOL_MODE == "SELF" {
		writeDynamicEntry(dynamicTableBuff, uint64(elf.DT_TEXTREL), 0)
	}
	
	dtFlags := elf.DF_TEXTREL

	if TOOL_MODE == "SPRX" {
		dtFlags = 0
	}

	writeDynamicEntry(dynamicTableBuff, uint64(elf.DT_FLAGS), uint64(dtFlags))

	// Needed libraries
	for _, libraryOffset := range libraryOffsets {
		writeDynamicEntry(dynamicTableBuff, uint64(elf.DT_NEEDED), libraryOffset)
	}

	// Needed modules
	for i, moduleOffset := range moduleOffsets {
		moduleMeta := uint64((0x10000*(i+1))+0x101) << 32
		writeDynamicEntry(dynamicTableBuff, DT_SCE_NEEDED_MODULE, moduleMeta+moduleOffset)
	}

	// Exported modules (libraries only)
	if TOOL_MODE == "SPRX" {
		writeDynamicEntry(dynamicTableBuff, DT_SCE_EXPORT_LIB, uint64(0x20001<<32)+offsetOfProjectName)
		writeDynamicEntry(dynamicTableBuff, DT_SCE_EXPORT_LIB_ATTR, uint64(0x20000<<32)+1)
	}

	// Imported modules
	for i, moduleOffset := range moduleOffsets {
		moduleMeta := uint64((0x10000*i)+0x1) << 32
		moduleAttrMeta := uint64(0x10000*i) << 32

		writeDynamicEntry(dynamicTableBuff, DT_SCE_IMPORT_LIB, moduleMeta+moduleOffset)
		writeDynamicEntry(dynamicTableBuff, DT_SCE_IMPORT_LIB_ATTR, moduleAttrMeta+0x9)
	}

	// Metadata
	writeDynamicEntry(dynamicTableBuff, DT_SCE_FINGERPRINT, 0) // Fingerprint will always be at 0x0
	writeDynamicEntry(dynamicTableBuff, DT_SCE_FILENAME, offsetOfFileName)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_MODULE_INFO, uint64(0x101<<32)+offsetOfProjectName)
	writeDynamicEntry(dynamicTableBuff, DT_SCE_MODULE_ATTR, 0)

	// Null tag to mark the end of the table
	writeDynamicEntry(dynamicTableBuff, uint64(elf.DT_NULL), uint64(0))

	// Commit to segment data
	*segmentData = append(*segmentData, dynamicTableBuff.Bytes()...)
	return uint64(len(dynamicTableBuff.Bytes()))
}

// writeDynamicEntry is a helper function that takes a given tag and value and writes it to a given writer.
func writeDynamicEntry(dynamicTable io.Writer, tag uint64, value uint64) {
	_ = binary.Write(dynamicTable, binary.LittleEndian, tag)
	_ = binary.Write(dynamicTable, binary.LittleEndian, value)
}

// writeObjectRelaEntry is a helper function that takes a given offset and writes an R_AMD64_64 entry to the given writer.
func writeObjectRelaEntry(relaTable io.Writer, offset uint64, symbolIndex int) {
	// Create the entry
	_ = binary.Write(relaTable, binary.LittleEndian, elf.Rela64{
		Off:    offset,
		Info:   uint64((symbolIndex << 32) + R_AMD64_64),
		Addend: 0,
	})
}
