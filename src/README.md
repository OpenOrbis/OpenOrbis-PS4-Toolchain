
# OpenOrbis PS4 Toolchain - Source Files

This directory contains source files for the library CRT, sce_module replacements, and VS project templates.

## C-Runtime Library
`./crt`

The C-Runtime (CRT) stubs are linked with ELFs, and include important initialization instructions for libc. Games/apps CRT is handled by musl already, however we have a crtlib stub here for PRXs to use, `crtlib.o`.

## Module Stubs
`./modules`

This directory contains the source for empty stub modules for `libc` and `libSceFios2`, which are needed in packages. Generally this source shouldn't need to be touched.

## Templates
`./templates`

This directory contains two Visual Studio projects, one for `OpenOrbis SELF Project`, and the other for `OpenOrbis SPRX Project`. These projects are exported to templates, and is the source code for the project templates found in `/extra`.
