# Sample: graphics

[![Version](https://img.shields.io/badge/Version-1.00-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for initializing the SceVideoOut library, and for CPU rendering graphics on the screen via writing to the frame buffer. As a test, it will draw a pretty fractal to the screen via the Mandelbrot set. A screenshot from the running application can be seen below.

- **Title ID**: BREW00082
- **Content ID**: IV0000-BREW00082_00-GRAPHICSEX000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/graphics
|-- assets                      // Empty assets directory
|-- graphics    
    |-- x64
        |-- Debug               // Object files / intermediate directory
    |-- build.bat               // Batch file for building on Windows
    |-- graphics.vcxproj        // Visual studio project files
    |-- graphics.vcxproj.filters
    |-- graphics.cvxproj.user
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
|-- graphics.sln                // Visual studio solution file
|-- Makefile                    // Make rules for building on Linux
|-- pkg.gp4                     // Package project file
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

- [Oleksii](https://github.com/lialkaas) for the base of the [Mandelbrot set implementation](https://github.com/lialkaas/ican-c/blob/master/math/mandelbrot.c).