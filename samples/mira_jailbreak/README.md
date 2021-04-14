# Sample: Mira Jailbreak sample

[![Version](https://img.shields.io/badge/Version-1.0-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for calling the Mira Driver to jailbreak a given process.



## Directory structure
```
samples/mira_jailbreak
|-- mira_jailbreak 
    |-- x64
        |-- Debug                      // Object files / intermediate directory
    |-- build.bat                      // Batch file for building on Windows
    |-- mira_jailbreak.vcxproj            // Visual studio project files
    |-- mira_jailbreak.vcxproj.filters
    |-- mira_jailbreak.cvxproj.user
    |-- main.cpp                       // main source file
    |-- mira_header.h                       // Mira IOCTL Structs and enums
|-- eboot.bin                          // final eboot (not present until built)
|-- mira_jailbreak.sln                    // Visual studio solution file
|-- Makefile                           // Make rules for building on Linux
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "mira_jailbreak" "%OO_PS4_TOOLCHAIN%\\samples\\mira_jailbreak"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
- LM
- Kiwi
