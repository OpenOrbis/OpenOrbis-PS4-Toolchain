package main

import (
	"debug/elf"
	"fmt"
	"os"
)

func getELFFile(args []string) string {
	// Search for a non-option argument (options are notated via a hyphen (-)). Returns the first non-option string found,
	// a blank string otherwise.
	for _, arg := range args {
		if arg[0] != '-' {
			return arg
		}
	}
	
	return ""
}

// Search for any flag in flags in a given set of args. Returns true if flag is found, false otherwise.
func checkFlagSet(args []string, flags []string) bool {
	for _, arg := range args {
		for _, flag := range flags {
			if arg == flag {
				return true
			}
		}
	}
	
	return false
}

// Checks the given err against nil. If it's not nil, the error is printed to stdout and os.Exit() is called.
func check(err error) {
	if err != nil {
		fmt.Printf("Error occurred: %s", err.Error())
		os.Exit(-1)
	}
}

func main() {
	// Check to make sure there are at least arguments provided
	if len(os.Args) < 2 {
		return
	}
	
	// Get command line flags
	args := os.Args[1:]
	
	inputFilePath := getELFFile(args)
	
	if inputFilePath == "" {
		fmt.Println("No ELF file given.")
		return
	}
	
	// Parse the input ELF file
	inputFile, err := os.Open(inputFilePath)
	check(err)
	
	inputElf, err := elf.Open(inputFilePath)
	check(err)

	// Set what to display and what not to based on flags. The "displayAll" variable will be checked in every case.
	displayAll := checkFlagSet(args, []string{"--all", "-a"})
	displayHeaders := displayAll || checkFlagSet(args, []string{"--headers", "-e"})
	
	displayFileHeader := displayAll || displayHeaders || checkFlagSet(args, []string{"--file-header", "-h"})
	displayProgramHeaders := displayAll || displayHeaders || checkFlagSet(args, []string{"--program-headers", "--segments", "-l"})
	displaySectionHeaders := displayAll || displayHeaders || checkFlagSet(args, []string{"--section-headers", "--sections", "-S"})
	displaySymbols := displayAll || checkFlagSet(args, []string{"--symbols", "--syms", "-s"})
	displayDynamicSymbols := displayAll || displaySymbols || checkFlagSet(args, []string{"--dyn-syms"})
	displayRelocs := displayAll || checkFlagSet(args, []string{"--relocs", "-r"})
	displayDynamic := displayAll || checkFlagSet(args, []string{"--dynamic", "-d"})
	
	// Write ELF header if specified
	if displayFileHeader {
		printFileHeader(inputFile, inputElf)
	}

	if displaySectionHeaders {
		printSectionHeaders(inputElf)
	}
	
	if displayProgramHeaders {
		printProgramHeaders(inputElf)
	}

	if displayDynamic {
		printDynamicEntries(inputFile, inputElf)
	}
	
	if displayRelocs {
		printRelocations(inputFile, inputElf)
	}

	if displayDynamicSymbols {
		printDynamicSymbols(inputFile, inputElf)
	}
}
