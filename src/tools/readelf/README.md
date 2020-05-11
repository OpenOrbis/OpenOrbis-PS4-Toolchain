# Readelf Documentation

## Summary
The `readelf` tool is meant to be a replacement for the standard `readelf` found on most systems. The reason a replacement was written is because PS4 ELFs (OELFs) have many proprietary types for most tables, including program header types, relocation types, as well as a completely custom linking system. This tool will allow developers to get detailed information on OELFs built with the SDK.

Note that this tool may work on standard ELFs / ELFs not targeting the PS4, however many of the options will not function properly. File, program, and section headers will likely work, however other options such as printing the dynamic, relocation, or symbol table, will not.

### Build
The tool is written in Golang. Commands should be the same between Windows and Linux assuming Golang is installed on the target system.

Building is very easy, simply go to the root directory of the tool (`/src/tools/readelf/`) and run the `go build` command.

There is a Linux build script to compile `readelf` on Linux, and cross-compile them for Windows. A batch script will be added at a later date.

### Usage
The `readelf` tool requires one argument, being the file to evaluate.

There are also additional optional arguments for customizing app information in the final SELF or PRX.

```
Options:
  --all / -a
        Display all information
  --headers / -e
        Display all header-related information, including the file header, section headers, and program headers
  --file-header / -h
        Display file header information
  --program-headers / --segments / -l
        Display segment/program header information
  --section-headers / --sections / -S
        Display section header information
  --symbols / --syms / --dyn-syms / -s
        Display dynamic symbol table information
  --relocs / -r
        Display relocation table information
  --dynamic / -d
        Display dynamic table information
```

## Source code overview
Each source file is responsible for a group of actions invoked by the tool. Below is a list of source files and what they're generally responsible for.

**ELFParsing.go**

Contains functions necessary for parsing the ELF, and contains the functions that print out the various table information to stdout.

**main.go**

Contains the main entry point and handles argument parsing.

***
