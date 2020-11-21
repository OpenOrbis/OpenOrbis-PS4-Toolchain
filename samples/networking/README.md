# Sample: networking

[![Version](https://img.shields.io/badge/Version-1.01-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for a basic TCP server that runs on `0.0.0.0:9025` and sends "Hello" to any client that connects to it before terminating the connection.

- **Title ID**: BREW00085
- **Content ID**: IV0000-BREW00085_00-NETWORKKEX000000



## Directory structure
```
samples/networking
|-- assets                            // Empty assets directory
|-- networking
    |-- x64
        |-- Debug                     // Object files / intermediate directory
    |-- build.bat                     // Batch file for building on Windows
    |-- networking.vcxproj            // Visual studio project files
    |-- networking.vcxproj.filters
    |-- networking.cvxproj.user
    |-- main.cpp                      // main source file
|-- sce_module                        // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                           // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                         // final eboot (not present until built)
|-- Makefile                          // Make rules for building on Linux
|-- networking.sln                    // Visual studio solution file
|-- pkg.gp4                           // Package project file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel



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
