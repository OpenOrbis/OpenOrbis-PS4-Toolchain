# Create Eboot + Create Lib Documentation

## Summary
The `create-eboot` and `create-lib` tools takes 64-bit Executable Linkable Format (ELF) input files, and produces 64-bit Orbis ELF (OELF) output files that are converted to be compatible with the PlayStation 4 (PS4) ELF loader. It further takes these OELF files and creates a final binary that the PS4 expects. For `create-eboot`, this is `eboot.bin`, which is a Signed Executable Linkable Format (SELF). For `create-lib`, this is a Playstation Relocatable eXecutable (PRX).

### Build
The tool is written in Golang. Commands should be the same between Windows and Linux assuming Golang is installed on the target system.

Building is very easy, simply go to the root directory of the tool (`/src/tools/create-eboot/`) and run the `go build` command.

There is a shell and batch build script to compile both `create-eboot` and `create-lib` on all platforms (Windows, Linux, and macOS).

### Usage
The `create-eboot` tool requires two arguments. These arguments are `-in` and `-out` for the input and output files respectively.

The `create-lib` tool requires only one argument, being `-in`.

There are also additional optional arguments for customizing app information in the final SELF or PRX.

```
Usage of create-eboot (as well as create-lib):
  -appversion int
        application version
  -authinfo string
        authentication info
  -fwversion int
        firmware version
  -in input ELF path
        input ELF path to convert
  -out output ELF path
        output ELF path to write to
  -paid int
        program authentication ID (default 4035225266123964433)
  -ptype string
        program type {fake, npdrm_exec, npdrm_dynlib, system_exec, system_dynlib, host_kernel, secure_module, secure_kernel}
  -sdkver int
        SDK version integer (default 72384769)
```

## Source code overview
Each source file is responsible for a group of actions invoked by the tool. Below is a list of source files and what they're generally responsible for.

**MakeFSELF.go**

Contains functions and structures necessary for creating a fake SELF (FSELF). This is mostly a port of flatz' `make_fself.py` script.

**OELF.go**

Main file that invokes functions to rewrite the input ELF and writes to the final output ELF given.

**OELFGenDynlibData.go**

Contains functions necessary for build the `.sce_dynlib_data` segment for dynamic linking. This file and it's functions are the heart of the tool.

**OELFGenProgramHeaders.go**

Contains functions necessary for generating a list of program headers for the final ELF file.

**OELFRewriteData.go**

Contains functions necessary for rewriting the ELF. This includes rewriting various ELF header fields, the program header table, the SDK version, and the interpreter.

**PS4Constants.go**

Contains constants for ELF-related types that are specific to PS4, as well as other types that are not in the `debug/elf` package. This includes ELF types, program header types, dynamic table tags, and relocation types.

**Utils.go**

Contains various helper functions used by other files. The helper functions available can be found further down.

**main.go**

Contains the main entry point and handles argument parsing.

***

## Utility functions
A list of the helper functions provided in Utils.go is provided below for convenience.

#### func (*OrbisElf) getFileOffsetBySectionName(string) (int64, error)
```golang
func (orbisElf *OrbisElf) getFileOffsetBySectionName(name string) (int64, error)
```
OrbisElf.getFileOffsetsBySectionName searches the section header table of the input ELF with the given name and returns that section's offset as well as error. If the section name does not exist, an offset of 0 and an error is returned. The offset and nil are returned otherwise.

#### func (*OrbisElf) getDynamicTag(elf.DynTag) (uint64, error)
```golang
func (orbisElf *OrbisElf) getDynamicTag(tag elf.DynTag) (uint64, error)
```
OrbisElf.getDynamicTag searches the dynamic table of the input ELF with the given tag and returns that tag's value as well as error. If the tag does not exist, or if the dynamic table cannot be found, a value of 0 and an error is returned. The value and nil are returned otherwise.

#### func (*OrbisElf) getSymbol(string) elf.Symbol
```golang
func (orbisElf *OrbisElf) getSymbol(name string) elf.Symbol
```
OrbisElf.getSymbol searches the symbol table of the input ELF with the given name and returns the corresponding elf.Symbol object. If the symbol does not exist, an empty elf.Symbol object is returned.

#### func (*OrbisElf) getProgramHeader(elf.ProgType, elf.ProgFlag) *elf.Prog
```golang
func (orbisElf *OrbisElf) getProgramHeader(headerType elf.ProgType, headerFlags elf.ProgFlag) *elf.Prog
```
OrbisElf.getProgramHeader searches the program header table of the input ELF with the given type and flags, and returns a pointer to that program header if it's found. If it cannot be found, a nil pointer is returned.

#### func checkIfLibraryContainsSymbol(*elf.File, string) (bool, error)
```golang
func checkIfLibraryContainsSymbol(library *elf.File, symbolName string) (bool, error)
```
checkIfLibraryContainsSymbol takes a given library and symbol name, and checks if the library contains that symbol. It returns a boolean of whether or not that library contains that symbol, as well as error. If we cannot get a libraries symbol list, false and an error is returned. Otherwise, the true or false and nil are returned.

#### func intToByteArray(int) []byte
```golang
func intToByteArray(value int) []byte
```
intToByteArray takes a given integer and writes it into a byte array (little endian) and returns it.

#### func writeNullBytes(uint64, uint64, *[]byte) uint64
```golang
func writeNullBytes(size uint64, align uint64, buffer *[]byte) uint64
```
writeNullBytes takes a given size and alignment, and uses that to write null padding to buffer. Returns the number of null bytes written.

#### func contains([]string, string) bool
```golang
func contains(slice []string, element string) bool
```
contains takes a given slice and element, and checks if the element is present within the slice. Returns true if it is present, false otherwise.

#### func NewOrderedMap() *OrderedMap
```golang
func NewOrderedMap() *OrderedMap
```
NewOrderedMap creates a new OrderedMap structure and returns it.

#### func (*OrderedMap) Get(interface{}) interface{}
```golang
func (orderedMap *OrderedMap) Get(key interface{}) interface{}
```
OrderedMap.Get uses a given key to return the corresponding mapping.

#### func (*OrderedMap) Set(interface{}, interface{})
```golang
func (orderedMap *OrderedMap) Set(key interface{}, value interface{})
```
OrderedMap.Set uses a given key to set that key's mapping to a given value.

#### func (*OrderedMap) Keys() []interface{}
```golang
func (orderedMap *OrderedMap) Keys() []interface{}
```
OrderedMap.Keys returns the current list of keys for the OrderedMap.
