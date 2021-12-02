# Sample: SDL2

[![Version](https://img.shields.io/badge/Version-1.03-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains an example asteroids clone which builds against SDL 2.0.

- **Title ID**: BREW00090
- **Content ID**: IV0000-BREW00090_00-SDLEXAMPLE000000

![screenshot](screenshot.jpg)



## Directory structure
```
samples/SDL2
|-- assets
    |-- fonts
        |-- Bebas-Regular.ttf     // Score font truetype file
        |-- VeraMono.ttf          // Debug font truetype file
    |-- images
        |-- enemy.tga             // Enemy asteroid texture
        |-- player.tga            // Player spaceship texture
        |-- projectile.tga        // Laser projectile texture
|-- sce_module                    // Dependency modules for the pkg
    |-- libSceFios2.prx
    |-- libc.prx
|-- sce_sys                       // Package materials (metadata)
    |-- about
        |-- right.prx
    |-- icon0.png
    |-- param.sfo
|-- SDL2
    |-- x64
        |-- Debug                 // Object files / intermediate directory
    |-- build.bat                 // Batch file for building on Windows
    |-- Color.h                   // Contains Color structure definition
    |-- Enemy.cpp                 // Contains Enemy class definitions
    |-- Enemy.h                   // Contains Enemy class declarations
    |-- Game.cpp                  // Contains game loop update/render routines and dispatching
    |-- Game.h                    // Contains globals shared with main.cpp
    |-- HUD.cpp                   // Contains HUD class definitions
    |-- HUD.h                     // Contains HUD class declarations
    |-- main.cpp                  // main source file
    |-- Player.cpp                // Contains Player class definitions
    |-- Player.h                  // Contains Player class declarations
    |-- Projectile.cpp            // Contains Projectile class definitions
    |-- Projectile.h              // Contains Projectile class declarations
    |-- SDL2.vcxproj              // Visual studio project files
    |-- SDL2.vcxproj.filters
    |-- SDL2.cvxproj.user
    |-- TTF.cpp                   // Contains text rendering function implementation
    |-- TTF.h                     // Contains text rendering function declarations
|-- eboot.bin                     // final eboot (not present until built)
|-- Makefile                      // Make rules for building on Linux
|-- pkg.gp4                       // Package project file
|-- SDL2.sln                      // Visual studio solution file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++
- libSceUserService
- libSceVideoOut
- libSceAudioOut
- libScePad
- libSceSysmodule
- libSceFreeType
- libSDL2
- libSDL2_image



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "system" "%OO_PS4_TOOLCHAIN%\\samples\\SDL2"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- Specter
- znullptr (SDL2 port)
