# Sample: net_http

[![Version](https://img.shields.io/badge/Version-1.00-brightgreen.svg)](https://github.com/Cryptogenic/OpenOrbis-PS4-Toolchain)

This project contains an example that connects to an HTTPS URL (`https://www.google.com/robots.txt`), and saves the file content to `/data/net_http.txt`.

- **Title ID**: BREW00051
- **Content ID**: IV0000-BREW00051_00-NETHTTPS00000000



## Directory structure
```
samples/net_http
|-- assets                             // Empty assets directory
|-- net_http 
    |-- x64
        |-- Debug                      // Object files / intermediate directory
    |-- build.bat                      // Batch file for building on Windows
    |-- net_http.vcxproj               // Visual studio project files
    |-- net_http.vcxproj.filters
    |-- net_http.cvxproj.user
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
|-- net_http.sln                       // Visual studio solution file
|-- Makefile                           // Make rules for building on Linux
|-- pkg.gp4                            // Package project file
```
The ELF, Orbis ELF (OELF), and object files will all be stored in the intermediate directory `x64/Debug`. The final eboot.bin file will be found in the root directory.



## Libraries used

- libc
- libkernel
- SceNet
- SceSsl
- SceHttp
- SceSysmodule



## Building

A visual studio project has been included for building on Windows. On Linux, a makefile has been included.

To build this project, the developer will need clang, which is provided in the toolchain. The `OO_PS4_TOOLCHAIN` environment variable will also need to be set to the root directory of the SDK installation.

__Windows__
Open the Visual Studio project and build, or run the batch file from command prompt or powershell with the following command:
```
.\build.bat .\x64\Debug "net_http" "%OO_PS4_TOOLCHAIN%\\samples\\net_http"
```

__Linux__
Run the makefile.
```
make
```



## Author(s)

- [Bucanero](https://github.com/bucanero)
