// This file only contains the entry point, and calls into the Orbis ELF Builder to start generating an output ELF using
// the information passed by command line.

package main

import (
	"flag"
	"fmt"
	"os"
	"strings"
)

// This constant is important for building!
//
// This "mode" constant determines if the tool is treated as a tool to build eboots / SELFs, or if it's used to build
// libraries / SPRXs. When building `create-eboot`, this mode should be set to "SELF". When building `create-lib`, this
// mode should be set to "SPRX". This can be set by the `ldflags` option in Go build, via
// `-ldflags='-X main.TOOL_MODE="SELF"'` or `-ldflags='-X main.TOOL_MODE="SPRX"'`.
//
// SELF = eboots / self
// SPRX = libraries / sprx
var TOOL_MODE = "SELF"

// sdkPath holds the path of the SDK root directory. Gets set in main, most likely via environment variable.
var sdkPath string
var libPath string

// errorExit function will print the given formatted error to stdout and exit immediately after.
func errorExit(format string, params ...interface{}) {
	fmt.Printf(format, params...)
	os.Exit(-1)
}

// check will check the error given by argument. If it's not nil, it will print the error to the console and the program
// will exit.
func check(err error) {
	if err != nil {
		if TOOL_MODE == "SELF" {
			errorExit("Failed to build FSELF: %s\n", err.Error())
		} else if TOOL_MODE == "SPRX" {
			errorExit("Failed to build FSPRX: %s\n", err.Error())
		}
	}
}

func main() {
	// Verify the TOOL_MODE constant is a valid value. This is mostly a dev-check, but still important because if it's wrong
	// there *will* be undefined behavior.
	if TOOL_MODE != "SELF" && TOOL_MODE != "SPRX" {
		errorExit("The 'TOOL_MODE' dev constant is set to an invalid value, it MUST be either 'SELF' or 'SPRX'.\n"+
			"Currently, it is: %s\n", TOOL_MODE)
	}

	// Get the SDK path in the environment variables. If it's not set, we need to state so and bail because we *need* it
	sdkPath = os.Getenv("OO_PS4_TOOLCHAIN")

	if sdkPath == "" {
		errorExit("The 'OO_PS4_TOOLCHAIN' environment variable is not set. It must be set to the root directory of the toolchain.\n")
	}

	// Required flags
	inputFilePathPtr := flag.String("in", "", "`input ELF path` to convert")

	// Only make the output flag required for *libraries*. In `create-eboot`, output can be left blank because ultimately,
	// the final file is the eboot.bin file itself, and the input filename will be used for the intermediate orbis ELF.
	outputFilePathUsage := "`output ELF path` to write to"

	if TOOL_MODE == "SPRX" {
		outputFilePathUsage = "`output PRX + stub path` to write to"
	}

	outputFilePathPtr := flag.String("out", "", outputFilePathUsage)

	// Optional flags
	sdkVerPtr := flag.Int("sdkver", 0x4508101, "SDK version integer")
	pType := flag.String("ptype", "", "program type {fake, npdrm_exec, npdrm_dynlib, system_exec, system_dynlib, host_kernel, secure_module, secure_kernel}")
	authInfo := flag.String("authinfo", "", "authentication info")
	paid := flag.Int64("paid", 0x3800000000000011, "program authentication ID")
	appVer := flag.Int64("appversion", 0, "application version")
	fwVer := flag.Int64("fwversion", 0, "firmware version")
	libNamePtr := flag.String("libname", "", "library name (ignored in create-eboot)")
	libPathPtr := flag.String("library-path", "", "additional directories to search for .so files")

	flag.Parse()

	// Set the SDK version for overwriting .sce_process_param later on
	sdkVer := *sdkVerPtr
	libPath = *libPathPtr
	if libPath == "" {}

	inputFilePath := *inputFilePathPtr
	outputFilePath := *outputFilePathPtr
	libName := *libNamePtr

	// Check for required flags
	if inputFilePath == "" {
		errorExit("Input file not specified, try -in=[input ELF path]\n")
	}

	if outputFilePath == "" && TOOL_MODE == "SPRX" {
		errorExit("Output file path not specified, try -out=[output PRX path]\n")
	}

	// If an output file path is not set, we'll set it to the input file path and just change the file type
	if outputFilePath == "" {
		outputFilePath = strings.Split(inputFilePath, ".")[0] + ".oelf"
	}

	buildOrbisElf(inputFilePath, outputFilePath, libName, sdkVer)
	createFself(outputFilePath, *paid, *pType, *appVer, *fwVer, *authInfo)
}
