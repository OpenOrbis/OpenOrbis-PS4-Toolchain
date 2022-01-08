# Sample: trophies

[![Version](https://img.shields.io/badge/Version-1.00-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for unlocking trophies.
(To run this, you need to make sure you have debug trophy's enabled on your system or the app will not install)
(should this sample fail to work and push a "Failed to register context for 0x80551626" this means the system did **NOT** install the trophy pack internally, to fix this simply create /user/trophy/conf/BREW00080_00-00/ and place the trophy pack with the name "TROPHY.TRP" and TRPPARAM.INI with the contents of TROPSYSVER=1.0\nTROPTITLEID=BREW00080_00-00\nTROPAPPVER=1.0)


- **Title ID**: BREW00080
- **Content ID**: IV0000-BREW00080_00-TROPHIESEX000000



## Directory structure
```
|-- trophies
    |-- x64
        |-- Debug                                 // Object files / intermediate directory
    |-- trophies.vcxproj                          // Visual studio project files
    |-- trophies.vcxproj.filters
    |-- trophies.cvxproj.user
    |-- build.bat                                 // Batch file for building on Windows
    |-- main.cpp                                  // Main source file
    |-- util.h                                    // header to contains a pre-setup Notify and kernel loger
|-- trophy00                                      // Images needed to construct the Trophy pack
        |-- ICON0.PNG                             // Trophy Pack Icon
        |-- TROPXXX.PNG                           // Trophy Icon
|-- sce_module                                    // Dependency modules for the pkg
    |-- libc.prx
|-- sce_sys                                       // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- trophy
        |-- trophy00.trp
    |-- icon0.png
    |-- npbind.dat
    |-- nptitle.dat
    |-- param.sfo
|-- eboot.bin                                     // Final eboot (not present until built)
|-- trophies.sln                                  // Visual studio solution file
|-- pkg.gp4                                       // Package project file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libSceUserService
- libSceNpTrophy
- libSceSysmodule



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

- znullptr
- Specter
- Backporter(aka Kernel Panic)