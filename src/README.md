
# OpenOrbis PS4 Toolchain - Source Files

This directory contains source files for all the tools included in the OpenOrbis PS4 toolchain. As a quick index, below is a table of the current projects that can be found here.
| Directory | Project | Lead Author/Maintainer |
|--|--|--|
| `./crt` | C-Runtime Library | Specter |
| `./lib` | Library stub files | Auto-generated via orbislibgen |
| `./modules` | Empty library source | Specter |
| `./templates` | Visual Studio Templates | Specter |
| `./tools/create-eboot` | `create-eboot` / `create-lib` | Specter |
| `./tools/create-gp4` | `create-gp4` | Specter + John Tornblom |
| `./tools/miralib` | MiraLib library | Specter |
| `./tools/orbisLibGen` | Library stub generator | CrazyVoid |
| `./tools/readelf` | Readelf replacement | Specter |



## C-Runtime Library
`./crt`

The C-Runtime (CRT) stubs are linked with ELFs, and include starter code and data that every application or library should have. Games/applications should be linked with `crt1.o`, and libraries with `crtlib.o`.

The source files are all .S x64 assembly files (intel syntax).

The `crt1` stub is responsible for ensuring final ELFs for applications have a proper entrypoint defined as `_start`. It is also responsible for including important data structures, namely `sceLibcParam`, `sceKernelMemParam`, `sceKernelFsParam`,  `sceLibcMallocReplace`, `sceLibcNewReplace`, `sceLibcMallocReplaceForTLS`, and `.sce_process_param` structures. It is also responsible for the `sceLibcHeapSize`, `sce_libc_heap_delayed_alloc`, `sce_libc_heap_extended_alloc`, `__dso_handle`, and `sceLibc` global variables. For more information on these structures, consult the wiki or documentation.

The `crtlib` stub is responsible for ensuring final ELFs for libraries have the `.sce_module_param` structure, as well as the `__dso_handle` and `sceLibc` global variables. The `crtlib` stub is responsible for a lot less than `crt1`, and as such is far smaller.

Games/apps should *always* link against the `crt1` stub, and libraries should *always* link against the `crtlib` stub.



## Library Stubs
`./lib`

This directory is populated with auto-generated files from orbislibgen, however, additions / modifications should be made here for missed functions and such.



## Module Stubs
`./modules`

This directory contains the source for empty stub modules for `libc` and `libSceFios2`, which are needed in packages. Generally this source shouldn't need to be touched.
## Templates
`./templates`

This directory contains two Visual Studio projects, one for `OpenOrbis SELF Project`, and the other for `OpenOrbis SPRX Project`. These projects are exported to templates, and is the source code for the project templates found in `/extra`.



## Create-eboot/create-lib
`./tools/create-eboot`

The `create-eboot` project contains the source for both `create-eboot` and `create-lib`. The project was written in Golang.

Since much of the process of creating applications and libraries is the same, we thought it best to not unnecessarily duplicate code and keep it all in one code-base. Which tool is compiled is determined by a linker flag. More information on this can be found on the tool's own `README.md`.



## Create-GP4
`./tools/create-gp4`

The `create-gp4` project contains the source for a tool to generate .gp4 project files. The project was written in Golang.

More information on this tool can be found on the tool's own `README.md`.



## Library stub generator (orbisLibGen)
`./tools/orbisLibGen`

This project contains a python script for generating the library source files found in `./lib`.



## MiraLib Library
`./tools/miralib`

This project contains all the language bindings and libraries for interacting with Mira from the PC side.

## Readelf replacement
`./tools/readelf`

This project contains a replacement for readelf for PS4 / Orbis ELFs (OELFs).
