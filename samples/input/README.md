# Sample: input

[![Version](https://img.shields.io/badge/Version-1.02-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for getting controller input from the DualShock 4 (DS4) controller. If a button or multiple buttons are pushed, they will be highlighted on the screen over the controller graphic.

- **Title ID**: BREW00084
- **Content ID**: IV0000-BREW00084_00-CONTROLREX000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/input
|-- assets
    |-- images                  // Images for drawing in the application
        |-- circle.png
        |-- controller.png
        |-- dpad-down.png
        |-- dpad-left.png
        |-- dpad-right.png
        |-- dpad-up.png
        |-- l1.png
        |-- l2.png
        |-- r1.png
        |-- r2.png
        |-- square.png
        |-- start.png
        |-- thumbstick.png
        |-- touchpad.png
        |-- triangle.png
        |-- x.png
|-- input
    |-- x64
        |-- Debug               // Object files / intermediate directory
    |-- build.bat               // Batch file for building on Windows
    |-- controller.cpp          // Controller class and helper methods
    |-- controller.h            // Controller class header
    |-- input.vcxproj           // Visual studio project files
    |-- input.vcxproj.filters
    |-- input.cvxproj.user
    |-- main.cpp                // main source file
|-- sce_module                  // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                     // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                   // final eboot (not present until built)
|-- input.sln                   // Visual studio solution file
|-- Makefile                    // Make rules for building on Linux
|-- pkg.gp4                     // Package project file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceVideoOut
- libScePad
- libSceUserService



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "input" "%OO_PS4_TOOLCHAIN%\\samples\\input"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
