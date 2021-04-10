# Sample: keyboard

[![Version](https://img.shields.io/badge/Version-1.0-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for getting input from a USB keyboard attached to the PlayStation 4. If a button or multiple buttons are pressed, their keycodes and the corresponding characters are displayed on the screen.


## Directory structure
```
samples/input
|-- keyboard
    |-- x64
        |-- Debug               // Object files / intermediate directory
    |-- build.bat               // Batch file for building on Windows
    |-- keyboard.cpp            // Keyboard class and helper methods
    |-- keyboard.h              // Keyboard class header
    |-- keyboard.vcxproj        // Visual studio project files
    |-- keyboard.vcxproj.filters
    |-- main.cpp                // main source file
|-- eboot.bin                   // final eboot (not present until built)
|-- keyboard.sln                // Visual studio solution file
|-- Makefile                    // Make rules for building on Linux
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceVideoOut
- libSceSysmodule
- libSceKeyboard
- libSceFreeType
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

- sleirsgoevy
- Specter
