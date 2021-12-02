# Sample: pngdec

[![Version](https://img.shields.io/badge/Version-1.02-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for initializing the SceVideoOut library, and for CPU rendering a PNG image on the screen. This sample will also have the capability to render JPEG, JPG, TGA, BMP, and non-animated GIFs as well as PNG files. This was made possible thanks to the awesome STB header library by Sean Barrett.

- **Title ID**: BREW00086
- **Content ID**: IV0000-BREW00086_00-IPNGDRAWEX000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/pngdec
|-- assets
    |-- images
        |-- logo.png            // Image to draw
|-- pngdec
    |-- x64
        |-- Debug               // Object files / intermediate directory
    |-- build.bat               // Batch file for building on Windows
    |-- main.cpp                // main source file
    |-- pngdec.vcxproj          // Visual studio project files
    |-- pngdec.vcxproj.filters
    |-- pngdec.cvxproj.user
|-- sce_module                  // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                     // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- eboot.bin                   // final eboot (not present until built)
|-- logo.png                    // PNG to decode and display
|-- Makefile                    // Make rules for building on Linux
|-- pkg.gp4                     // Package project file
|-- pngdec.sln                  // Visual studio solution file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceVideoOut



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

## Additional credit

- [Sean Barrett](https://github.com/nothings) for the [STB header library](https://github.com/nothings/stb).
