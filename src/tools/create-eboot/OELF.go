package main

import (
	"debug/elf"
	"encoding/binary"
	"errors"
	"io/ioutil"
	"os"
)

// Struct OrbisElf groups together information important to the final converted Orbis ELF. It also contains information
// about the ELF file to convert to be accessed from OrbisElf's methods.
type OrbisElf struct {
	ProgramHeaders []elf.Prog64
	SectionHeaders []elf.Section64

	LibraryName            string
	ElfToConvertName       string
	ElfToConvert           *elf.File
	ModuleSymbolDictionary *OrderedMap

	FinalFile *os.File
}

// OrbisElf.ValidateInputELF performs checks on the ELF to be converted. It checks the byte order, machine, class, and
// ensures the necessary segments exist. Returns an error if a check fails, nil otherwise.
func (orbisElf *OrbisElf) ValidateInputELF() error {
	// The input ELF must be little endian, and of AMD64 architecture
	if orbisElf.ElfToConvert.ByteOrder != binary.LittleEndian {
		return errors.New("byte order must be little endian")
	}

	if orbisElf.ElfToConvert.Machine != elf.EM_X86_64 {
		return errors.New("architecture must be x86_64 / AMD64")
	}

	if orbisElf.ElfToConvert.Class != elf.ELFCLASS64 {
		return errors.New("elf must be a 64-bit elf")
	}

	return nil
}

// buildOrbisElf parses an ELF path from inputFile and writes an output Orbis ELF to outputFile. Returns an error if
// an issue occurred during conversion, nil otherwise.
func buildOrbisElf(inputFilePath string, outputFilePath string, libName string, sdkVer int) {
	// Open the ELF file to be converted, and create a file for the final Orbis ELF
	inputElf, err := elf.Open(inputFilePath)
	check(err)

	// Create final oelf file
	outputElf, err := os.Create(outputFilePath)
	check(err)

	orbisElf := OrbisElf{
		LibraryName:      libName,
		ElfToConvertName: inputFilePath,
		ElfToConvert:     inputElf,
		FinalFile:        outputElf,
	}

	// Validate ELF to convert before processing
	err = orbisElf.ValidateInputELF()
	check(err)

	// Copy contents of input file into output file
	inputFileBytes, err := ioutil.ReadFile(inputFilePath)
	check(err)

	writtenBytes, err := orbisElf.FinalFile.Write(inputFileBytes)
	check(err)

	// Create the .sce_dynlib_data segment onto the end of the file
	err = orbisElf.GenerateDynlibData(uint64(writtenBytes))
	check(err)

	// Generate updated program headers
	err = orbisElf.GenerateProgramHeaders()
	check(err)

	// Overwrite ELF file header with PS4-ified values, as well as the SDK version in .sce_process_param/.sce_module_param
	err = orbisElf.RewriteELFHeader()
	check(err)

	err = orbisElf.RewriteSDKVersion(sdkVer)
	check(err)

	// Overwrite program header table
	err = orbisElf.RewriteProgramHeaders()
	check(err)

	err = orbisElf.FinalFile.Close()
	check(err)
}
