# Sample: library_example

[![Version](https://img.shields.io/badge/Version-1.00-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for creating a library with a dummy function. It will generate an output .prx (Playstation Relocatable Executable) for the PS4, as well as a stub .so shared object file for linking on the PC side.



## Directory structure
```
samples/library_example
|-- library_example
    |-- x64
        |-- Debug                          // Object files / intermediate directory
    |-- build.bat                          // Batch file for building on Windows
    |-- library_example.vcxproj            // Visual studio project files
    |-- library_example.vcxproj.filters
    |-- library_example.cvxproj.user
    |-- lib.cpp                            // library source file
    |-- libExample.h                       // library header file
|-- libExample.prx                         // final library file (not present until built)
|-- libExample_stub.so                     // final library stub (not present until built)
|-- library_example.sln                    // Visual studio solution file
|-- Makefile                               // Make rules for building on Linux
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final library prx and stub files will be found in the root directory.



## Libraries used

- libc
- libkernel



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "library_example" "%OO_PS4_TOOLCHAIN%\\samples\\library_example"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
