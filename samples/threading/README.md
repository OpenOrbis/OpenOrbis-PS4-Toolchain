# Sample: threading

[![Version](https://img.shields.io/badge/Version-1.02-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for running pthreads for concurrent programming. Writes to the screen with 2 threads in a loop.

- **Title ID**: BREW00087
- **Content ID**: IV0000-BREW00087_00-PTHREADDEX000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/threading
|-- assets
    |-- fonts
        |-- Gontserrat-Regular.ttf  // Font truetype file
        |-- OFL.txt                 // Font license
|-- sce_module                      // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                         // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- threading
    |-- x64
        |-- Debug                   // Object files / intermediate directory
    |-- build.bat                   // Batch file for building on Windows
    |-- main.cpp                    // main source file
    |-- threading.vcxproj           // Visual studio project files
    |-- threading.vcxproj.filters
    |-- threading.cvxproj.user
|-- eboot.bin                       // final eboot (not present until built)
|-- Makefile                        // Make rules for building on Linux
|-- pkg.gp4                         // Package project file
|-- threading.sln                   // Visual studio solution file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceVideoOut
- libSceSysmodule
- libSceFreeType



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "networking" "%OO_PS4_TOOLCHAIN%\\samples\\networking"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
- CrazyVoid
