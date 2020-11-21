# Sample: hello_world

[![Version](https://img.shields.io/badge/Version-1.00-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for calling printf to print a hello world string to the console, as well as calling SCE's usleep from libkernel. This project is mostly meant as an example for what the build scripts and what not look like for using the toolchain.

- **Title ID**: BREW00083
- **Content ID**: IV0000-BREW00083_00-HELLOWORLD000000



## Directory structure
```
samples/hello_world
|-- assets                             // Empty assets directory
|-- hello_world 
    |-- x64
        |-- Debug                      // Object files / intermediate directory
    |-- build.bat                      // Batch file for building on Windows
    |-- hello_world.vcxproj            // Visual studio project files
    |-- hello_world.vcxproj.filters
    |-- hello_world.cvxproj.user
    |-- main.cpp                       // main source file
|-- sce_module                         // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                            // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                          // final eboot (not present until built)
|-- hello_world.sln                    // Visual studio solution file
|-- Makefile                           // Make rules for building on Linux
|-- pkg.gp4                            // Package project file
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
.\build.bat .\x64\Debug "hello_world" "%OO_PS4_TOOLCHAIN%\\samples\\hello_world"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
