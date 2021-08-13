# Changelog

## Beta

**v0.5.1 - November 19th, 2020**

- Fixed various discrepancies between BSD and MUSL including function prototypes, structure definitions, and macros!
- Added Docker container support (thanks alazif)!
- Added proper TLS support (thanks sleirsgoevy)!
- Added a battery of unit tests for issues addressed in v0.5.1. These tests will be kept up to date with future additions to attempt to improve release qualities.
- Fixed an issue where MUSL was not thread-safe due to custom CRT.
- Added support '+' and '-' escaping in NIDs (thanks sleirsgoevy).
- Fixed an issue where relocations could refer to incorrect symbols due to not accounting for an additional `SECTION` entry (thanks sleirsgoevy).
- Fixed copy/paste induced bugs in the autobuild.py script (thanks alazif).
- Fixed a minor issue where the `__bswap32` macro in the endian include header produced compiler warnings (thanks astrelsky).

**v0.5 - August 7th, 2020**

- The toolchain now includes stub/empty libc and libSceFios2 modules to avoid breaking non-homebrew games and applications!
  - *Note: This change works in conjunction with Mira, meaning you'll want to update the version of Mira you're loading as well.*
  - *Additional note: these modules can be found in /bin/data/modules/libc.prx and /bin/data/modules/libSceFios2.prx, and should be placed in `sce_module/` in your homebrew's package file.*
- SDL2 headers as well as a mini game sample have now been added (thanks znullptr for the original SDL port)!
- C++ threading (std::thread) support has been added!
- C++ locking / synchronization support has been added!
- Fixed a performance issue in create-eboot, giving it a 7858% performance boost (measured with the SDL sample)!
- Visual studio project templates now support and link with C++ by default.
- Added various macros and function definitions to libkernel, libScePad, libSceUserService, and libSceVideoOut, as well as documentation for these additions.
- Added right.prx by IDC to all samples (thanks IDC for right.prx).
- Slightly adjusted sample pkg gp4 files to use the same eboot.bin created by build scripts instead of unnecessarily using a copy.
- Fixed jagged text rendering in `/samples/_common/graphics.cpp` due to not factoring in the freetype greyscale bitmap alpha properly.
- Buffering is now disabled on stdout automatically due to it not handling buffering well.
- Updated pthread header to use PS4/BSD-specific values.
- Samples now have DWARF / debug symbols included by default (thanks sleirsgoevy).
- Reworked the threading sample to use std::thread and std::mutex now that C++ threading is supported.
- Reworked the networking sample to a TCP server instead of a TCP client.
- Fixed an issue where a really silly FreeBSD change broke any networking functions that need to use the sockaddr struct such as bind.
- Fixed an issue where GP4 project files were using non-portable windows-style path separators (thanks sleirsgoevy).
- Fixed an issue where the non-sce sleep() function didn't work due to a MUSL-related issues (thanks LM, ChendoChap).
- Fixed an issue where SPRX visual studio projects contained a typo in an include statement and an incorrect set of libraries for the build script.
- Fixed the cmath c++ header, which included `using` statements for functions that are macros on FreeBSD targets (thanks kiwidog).
- Fixed an issue where the `sockaddr_in` structure was incorrect due to a discrepancy between Linux and FreeBSD (thanks kiwidog).
- Fixed an issue where the pipe() function didn't work due to a discrepancy between Linux and FreeBSD (thanks sleirsgoevy).
- Fixed an issue where AF_INET6 was erroneously set to 10 due to a discrepancy between Linux and FreeBSD (thanks sleirsgoevy).

**v0.4 - June 23rd, 2020**

- Added C++ support via `include/c++/v1` headers and statically built libcxx.
- Added support for C++ init_array/fini_array dynamic tags in create-eboot / create-lib.
- Remade a new fancy windows installer.
- Created a script to streamline the release creation process.
- Added initial PS4 library documentation into `/docs` for libkernel, pad, sysmodule, userservice, and videoout.
- Common functionality between samples (graphics and logging as well as PNG decoding) have been moved into `/samples/_common`.
- Font sample has been rewritten to use C++.
- Hello world sample has been rewritten to use C++.
- Input sample has been rewritten to use C++ and now has a visual component to make the sample more obvious in what it does.
- PNG decoding sample has been rewritten to use C++.
- System sample has been rewritten to use C++ and now prints to the screen instead of stdout to better demonstrate what it does.
- Threading sample has been rewritten to use C++ and similar to system sample, now prints to the screen.
- Fixed an issue where the create-eboot/lib and readelf build scripts were not building for macOS.
- Fixed a minor typo in readelf which caused `DT_INIT_ARRAY_SZ` and `DT_FINI_ARRAY_SZ` tags to be incorrectly identified as `DT_INIT_ARRAY` and `DT_FINI_ARRAY` tags.
- Updated various sample readmes to account for reworked samples.
- Removed old installer NSIS script.

*Known Issues*
- iostream's std::cout does not function properly and will cease to work after one write. For writing to stdout, use the `DEBUGLOG` macro in `samples/_uncommon/log.h`. We hope to address this in the future.

**v0.3 - June 17th, 2020**

- Added MUSL libc support, removed old BSD headers, and reworked samples to use MUSL.
- Added libraries sources for Continuous Integration (CI).
- Added debugging info via section header table into OELFs via create-eboot.
- Fixed an issue in create-eboot where NIDs were written for local symbols when they shouldn't be.
- Fixed an issue where `drawPixel()` in the font, graphics, and pngdec samples were not inlined, causing performance slowdown (thanks m0rph3us1987).
- Added interpreter string write to linker script and removed it from create-eboot.
- Removed condition from create-eboot where requiring a `.got.plt` section was only checked for SPRX libraries and not SELF eboots; all binaries need this section.
- Removed sample package files to reduce bloat. They will later be available as separate releases.
- Disabled buffering on stdout on various samples for MUSL.

**v0.2 - May 15th, 2020**

- Added macOS support (thanks Lord Friky).
- Added package file sources for samples to make deploying samples easier, and to better demonstrate how packages should be constructed.
- Fixed an issue where create-lib did not properly export NIDs and therefore dynamic resolving would fail (thanks IDC).
- Fixed an issue where create-eboot/create-lib would occasionally calculate an incorrect data program size due to not accounting for the size of the `.sce_proc_param` section (thanks IDC).
- Fixed an issue where create-eboot/create-lib would occasionally calculate an incorrect size of the string table due to an off by one via a subtle logic bug related to section padding (thanks IDC).
- Fixed an issue where libraries would not have their Global Offset Table (GOT) / Procedure Linkage Table (PLT) aligned if no `.data.rel.ro` section was present (thanks IDC).
- Added a build script for create-eboot/create-lib for Windows (thanks IDC).
- Fixed an issue where the `__GNUC__` fix was being applied even if it was already defined, causing the compiler to complain if you manually defined it via compiler flags (thanks IDC).
- Added `include/x86` directory for systems that don't have it.
- Fixed an issue where even if there was no GOT/PLT, the PS4 would complain on libraries because it needs it for some silly reason. `.got.plt` is now forced into the build, even if there are no PLT entries (thanks IDC).

**v0.1.1 - May 13th, 2020**

- Added MiraLib C# library on Continuous Integration (CI).

**v0.1.1 - May 12th, 2020**

- Fixed an issue where samples would fail to build on clang 10+ due to a sneaky change in LLVM where it no longer defines `__GNUC__`.
- Fixed an issue where Makefiles would not automatically create directories for intermediate files, causing them to fail on systems where the directories didn't already exist (ie. Visual Studio didn't create them).
- Fixed script line endings in `/extra` scripts from CRLF to LF for release.

**v0.1.0 - May 11th, 2020**

- Public release.
- Put create-eboot/create-lib on Continuous Integration (CI).



## Alpha

*Note: Some changes that didn't go anywhere / were deadends were left out as they were irrelevant, and a lot of the dead time spaces in the earlier versions were reversing periods where CrazyVoid and Specter were reversing the OELF format.*

**v0.0.54 - May 11th, 2020**

- Prepared for release, initiated basic CI for create-eboot.

**v0.0.53 - May 6th, 2020**

- Add new C# MiraLib library.

**v0.0.52 - May 2nd, 2020**

- Added linux build script for crt1 and crtlib.

**v0.0.51 - March 7th, 2020**

- Added audio sample - znullptr.
- Fixed formatting issues in sample READMEs.
- Add wav decoding to audio-wav sample.
- Updated PS4 library headers to add more definitions.

**v0.0.50 - March 7th, 2020**

- Fixed an issue where the bss section was not being considered when generating data program headers.
- Removed a prototype that could cause issues in certain build situations from freetype proto header.
- Updated crt1 to `Need_sceLibc` is set to 1.

**v0.0.49 - March 6th, 2020**

- Added text wrapping to font sample.

**v0.0.48 - March 5th, 2020**

- Major PS4 library header update.
- Added PNG/JPEG decoding sample.
- Fixed an issue where the custom heap size was not being respected due to a bug in the CRT stub.

**v0.0.47 - March 5th, 2020**

- Added font sample.
- Added freetype lib.
- Updated graphics sample.
- Added STB freestanding header library.

**v0.0.46 - March 3rd, 2020**

- Added video sample which rendered graphics to the screen via CPU rendering.
- Added CrazyVoid's pthread sample.

**v0.0.45 - March 3rd, 2020**

- Added readelf tool.
- Updated source documentation.
- Removed redundant files from readelf.

**v0.0.44 - March 2nd, 2020**

- Added CrazyVoid's new headers.
- Fixed an issue where SSE instructions would trigger a SIGBUS crash due to the CRT stub not aligning the stack to a 16-byte boundary.

**v0.0.43 - February 1st, 2020**

- Added missing crtlib source.

**v0.0.42 - January 31st, 2020**

- Added PDF documentation.
- Removed deprecated documentation.
- Reworked samples into Visual Studio projects and makefiles.
- Fixed a nil dereference in create-lib when no .data.rel_ro section was present.

**v0.0.41 - January 30th, 2020**

- Added PS4 SELF Project and PS4 SPRX Project Visual Studio templates.
- Moved linker script to root directory.

**v0.0.40 - January 29th, 2020**

- Added crtlib stub
- Added ldflags and script to build create-eboot/create-lib cross-platform.
- Fixed an issue where if an input ELF contained no dynamic functions or globals, a crash would occur due to bad checking logic.
- Fixed an issue where create-lib would write the interpreter string at the top of .text when it shouldn't for libraries.
- Fixed an issue where sce_process_param was dereferenced in create-lib, when it should be dereferencing sce_module_param.

**v0.0.39 - January 28th, 2020**

- Added library sample.

**v0.0.38 - January 24th, 2020**

- Added make FSELF functionality into create-eboot, removing the need for flatz' script.

**v0.0.37 - January 23rd, 2020**

- Rebranded elf-to-oelf as create-eboot.
- Fixed an issue where the `Need_sceLibc` symbol entry was off by one.

**v0.0.36 - January 23rd, 2020**

- Fixed an issue where certain relocations were not ported due to a missing PIE (position independent executable) flag.
- Fixed build scripts to use elf-to-oelf.
- Added dictionary definitions for module to lib in elf-to-oelf.

**v0.0.35 - January 22nd, 2020**

- Added system example.
- Added executables into the repo for testing (to be removed later).

**v0.0.34 - January 22nd, 2020**

- Added networking sample.
- Added documentation.

**v0.0.33 - January 22nd, 2020**

- Added BSD libc library headers.
- Deprecated PS4 Assistant payload in favor of Mira.

**v0.0.32 - January 21st, 2020**

- Added controller input sample.

**v0.0.31 - January 21st, 2020**

- Added hello_world sample.
- Removed deprecated test/usleep sample.
- Fixed an issue where `stdio.h` was using a type that was not valid on linux.
- Fixed an issue where the prototype for `sceKernelUsleep` and `rename` was not correct.

**v0.0.30 - January 20th, 2020**

- Added comment documentation to elf-to-oelf.
- Added information to OELF specification documentation.

**v0.0.29 - January 20th, 2020**

- Finished elf-to-oelf v0.1.
  - Added support for need_sceLibc object.
  - Added globals to keep track of the need_sceLibc object as well as the number of entries for the hash table.
  - Added rela table entries for .data.rel.ro entries sceLibcMallocReplace, sceLibcNewReplace, Need_sceLibc, sceLibcMallocReplaceForTls.
  - Added rela table entries for .sce_process_param entries sceLibcParam, sceKernelMemParam, sceKernelFsParam.
  - Added sorting for program headers to ensure a standard order is followed.
  - Added support for PT_GNU_EH_FRAME / exception handler frames.
  - Added a helper function to write relative rela entries.
  - Added a helper function to write object rela entries.
  - Added a helper function to get a symbol value by name from the input ELF.
  - Fixed an issue where OrbisElf.ProgramHeaders was of type []elf.ProgHeader - it is now of type []elf.Prog64.
  - Fixed an issue where libkernel was not the first library included.
  - Fixed an issue where the size of NID entries was incorrect and caused calculation issues in building the symbol table.
  - Fixed an issue where the nchain field of the hash table and by extension the number of entries in the hash table itself were incorrect due to not factoring in non-external symbols.
  - Fixed an issue where DT_FLAGS was incorrect and used a deprecated value.
  - Fixed an issue where DT_SCE_MODULE_INFO was incorrect because it used the size of the module table when it should have been using the offset.
  - Fixed an issue where PT_DYNAMIC's memory size was null, which caused the PS4's ELF loader to fail.
  - Fixed other various offset miscalculations in the program header table generator.
  - Fixed an issue where the program header count 'Phnum' was sometimes incorrect in the ELF header.

**v0.0.28 - January 15th, 2020**

- Added program header rewriting.
- Added alignment between the string table and the symbol table in dynlib data.
- Fixed an issue where the relocation / rela table size was incorrect as it did not account for the size of the jump table.

**v0.0.27 - January 14th, 2020**

- Added program header generators for PT_SCE_DYNLIB_DATA, PT_DYNAMIC.
- Added code to commit the write of the generated dynlib data segment to the output file.
- Added code to record the file offset of the dynlib data segment.
- Fixed an issue where the file offset and size of the dynamic table were not recorded.

**v0.0.26 - January 11th, 2020**

- Added program header generators for PT_INTERP, PT_TLS, PT_LOAD (text), PT_GNU_EH_FRAME, PT_SCE_RELRO, PT_LOAD (data), and PT_SCE_PROC_PARAM.
- Added a helper function to get program headers by type and flag.
- Fixed `OrbisElf.ProgramHeaders` type to `[]elf.ProgHeader` instead of `[]elf.Prog`.

**v0.0.25 - January 9th, 2020**

- Add program header table generator (elf-to-oelf).
- Removed redundant `[]byte()` cast from the `writeFingerprint()` function in the dynlib data generator (elf-to-oelf).

**v0.0.24 - January 7th, 2020**

- Added relocation table generator (elf-to-oelf).
- Added symbol hash table generator (elf-to-oelf).
- Added helper function to get a dynamic tag value that isn't string-related.

**v0.0.23 - January 4th, 2020**

- Added refactored dynlib data generator to elf-to-oelf.
- Added helper function to check if a given library file contains an external symbol, which will be needed for relocation table generation.
- Fixed an issue where `OrderedMap.Set()` would not take into account if a key was already created and would add duplicate key entries.

**v0.0.22 - January 3rd, 2020**

- Fixed `program_headers.py` so that it now displays the virtual address and physical address of the segment.
- Fixed `rela_entries.py` so that it now displays all entries instead of just some of them.

**v0.0.21 - January 3rd, 2020**

- Switched static library stubs to dynamic libraries so we can put more of the workload on the LLVM linker and less on elf-to-oelf.
- Fixed an issue where a bad typedef in `stdio.h` caused compilation issues (`wchar_t`).

**v0.0.20 - November 21st, 2019**

- Added relinker, which goes which goes back through the .text segment and rewrites the stubs to create jumps that dereference the Procedure Linkage Table (PLT) (elf-to-oelf).
- Added program header entries for the interpreter and TLS.
- Reworked the way `writeOriginalText()` worked so that stubs are also written, where they weren't before due to an oversight.
- Fixed R_AMD64_RELATIVE constant to the proper name, being R_AMD64_JUMP_SLOT for the 0x7 RELA type.
- Fixed `writeStrTable()` off-by-one error when calculating the size of the table.
- Fixed an issue where `writeRelaTable()` would write the entries r_info backwards. Now the symbol index is stored in the upper 32-bits, and the type in the lower to properly adhere to ELF standards.
- Fixed `rela_entries.py` script so that it properly calculates the number of RELA entries.
- Removed redundant integer cast in `writeSectionPadding()`.

**v0.0.19 - November 16th, 2019**

- Added dynamic table building to SCE_Dynlib_Data segment builder (elf-to-oelf).
- Fixed `.sce_proc_param` to align to a 0x10 byte boundary.
- 

**v0.0.18 - November 13th, 2019**

- Added hash table building to SCE_Dynlib_Data segment builder (elf-to-oelf).
- Added section padding before NID, symbol, rela, and hash table to align to a 0x10 byte boundary.
- Added section padding before dynamic table to align to a 0x10 byte boundary.

**v0.0.17 - November 12th, 2019**

- Refactored elf-to-oelf (complete overhaul).

**v0.0.16 - October 29th, 2019**

- Added base RELA table building to SCE_Dynlib_Data segment builder (elf-to-oelf).
- Fixed relro segment header to use proper virtual and physical addresses.
- Fixed the `rela_entries.py` script to more accurately reflect the `r_sym` field as "symbol" rather than "info".

**v0.0.15 - October 23rd, 2019**

- Added symbol table building to SCE_Dynlib_Data segment builder (elf-to-oelf).
- Refactored how structs are written via binary serialization (elf-to-oelf).

**v0.0.14 - October 22nd, 2019**

- Added script to read symbol table entries.

**v0.0.13 - October 21st, 2019**

- Added initial SCE_Dynlib_Data segment builder (elf-to-oelf).

**v0.0.8 - July 29th, 2019**

- Fixed various script bugs due to improperly reading RELA information.

**v0.0.7 - July 28th, 2019**

- Added data segment builder (elf-to-oelf).

**v0.0.6 - July 26th, 2019**

- Switched elf-to-oelf to Golang codebase.
- Added EH frame builder (elf-to-oelf).

**v0.0.5 - March 28th, 2019**

- Added preliminary orbisLibGen.
- Added flatz' make_fself.py script.
- Added initial PS4 library headers (reversing).

**v0.0.4 - March 27th, 2019**

- Added elf-to-oelf segment builders (C++).

**v0.0.3 - March 26th, 2019**

- Added additional OELF documentation (reversing).
- Added script to print out dynamic entries of OELFs.
- Added script to print out program headers of OELFs.
- Added script to print out RELA entries of OELFs.

**v0.0.2 - March 5th, 2019**

- Added initial elf-to-oelf implementation (C++).
- Added preliminary OELF documentation (reversing).

**v0.0.1 - Feb. 26th, 2019**

- Added README, LICENSE, and BSD libc header files.
