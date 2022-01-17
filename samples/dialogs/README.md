# Sample: dialogs

[![Version](https://img.shields.io/badge/Version-1.00-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for showing a user-defined message dialog on the screen.

- **Title ID**: BREW00052
- **Content ID**: IV0000-BREW00052_00-MSGDIALOGS000000



## Directory structure
```
samples/dialogs
|-- assets                             // Empty assets directory
|-- dialogs 
    |-- x64
        |-- Debug                      // Object files / intermediate directory
    |-- build.bat                      // Batch file for building on Windows
    |-- dialogs.vcxproj                // Visual studio project files
    |-- dialogs.vcxproj.filters
    |-- dialogs.cvxproj.user
    |-- main.c                         // main source file
|-- sce_module                         // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                            // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                          // final eboot (not present until built)
|-- dialogs.sln                        // Visual studio solution file
|-- Makefile                           // Make rules for building on Linux
|-- pkg.gp4                            // Package project file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libSceCommonDialog
- libSceMsgDialog
- libSceSysmodule


## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "dialogs" "%OO_PS4_TOOLCHAIN%\\samples\\dialogs"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- [Bucanero](https://github.com/bucanero)
