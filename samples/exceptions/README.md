# Sample: Exceptions

[![Version](https://img.shields.io/badge/Version-1.0-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains example code for using C++ exceptions in an OpenOrbis homebrew application.

Since exceptions are not enabled in the compiler by default, they have to be enabled manually in the build file.

See `Makefile` or `build.bat` for more information.


## Directory structure
```
samples/exceptions
|-- exceptions 
    |-- x64
        |-- Debug                  // Object files / intermediate directory
    |-- build.bat                  // Batch file for building on Windows
    |-- exceptions.vcxproj         // Visual studio project files
    |-- exceptions.vcxproj.filters
    |-- main.cpp                   // main source file
|-- eboot.bin                      // final eboot (not present until built)
|-- exceptions.sln                 // Visual studio solution file
|-- Makefile                       // Make rules for building on Linux
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- libc++ (c++abi and unwind implicitly linked together)



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "exceptions" "%OO_PS4_TOOLCHAIN%\\samples\\exceptions"
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
- Nikita Krapivin
