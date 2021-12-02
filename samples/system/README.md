# Sample: system

[![Version](https://img.shields.io/badge/Version-1.02-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code that gets the logged in user's ID and username and prints it to the screen.

- **Title ID**: BREW00088
- **Content ID**: IV0000-BREW00088_00-GETUSRIDEX000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/system
|-- assets
    |-- fonts
        |-- Gontserrat-Regular.ttf  // Font truetype file
        |-- OFL.txt                 // Font license
|-- system
    |-- x64
        |-- Debug                   // Object files / intermediate directory
    |-- build.bat                   // Batch file for building on Windows
    |-- system.vcxproj              // Visual studio project files
    |-- system.vcxproj.filters
    |-- system.cvxproj.user
    |-- main.cpp                    // main source file
|-- sce_module                      // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                         // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                       // final eboot (not present until built)
|-- Makefile                        // Make rules for building on Linux
|-- pkg.gp4                         // Package project file
|-- system.sln                      // Visual studio solution file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceVideoOut
- libSceSysmodule
- libSceFreeType
- libSceUserService



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "system" "%OO_PS4_TOOLCHAIN%\\samples\\system"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
