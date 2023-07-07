# OpenOrbis PS4 Toolchain

[![Release State](https://img.shields.io/badge/release%20state-beta-yellow.svg)](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain)
[![Release](https://img.shields.io/github/v/release/OpenOrbis/OpenOrbis-PS4-Toolchain)](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/releases/latest)
[![Build OpenOrbis Toolchain](../../actions/workflows/toolchain.yml/badge.svg)](../../actions/workflows/toolchain.yml)
[![Platforms](https://img.shields.io/badge/platform-linux%20%7C%20windows%20%7C%20macos-blue)](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/releases/latest)

**Note: Use the release zip or an installer, or you'll have to build the libraries and binaries yourself. It's setup this way to prevent the repo from getting bloated with binaries.**

This repository contains the source code and documentation for the OpenOrbis PS4 toolchain, which enables developers to build homebrew without the need of Sony's official Software Development Kit (SDK). It contains the header files, library stubs, and tools to build applications and libraries for the PS4.

The header files as well as the library stubs may need updating to support yet undiscovered functions, so feel free to fork the repository and make pull requests to update support.

<p align="center">
	<img src="logo.png" width="200px" height="200px">
</p>

## Roadmap

The following is planned to be added in future updates:

**v0.6** - Debugging tools (debugger, VS integration).

**v0.7** - Finalize GPU rendering support.

**v1.0** - Stable release that works smoothly and has header discrepancies mostly resolved.

## Documentation

Tool-specific documentation can be found alongside it's source code. The `docs` sub-directory also contains additional materials and documentation. Below is an overview of the purpose of each sub-directory:

| Directory | Contents |
|--|--|
| `/bin` | Executables for tools for each platform (Windows in `/bin/windows`, Linux in `/bin/linux` and macOS in `/bin/macos`) |
| `/docs` | Documentation for PS4 format specifications (reverse engineered) and the toolchain itself |
| `/extra` | Extra / miscellaneous files. Currently, this includes project templates for Visual Studio |
| `/include` | Contains PS4-specific + EGL/GLES and freetype headers |
| `/lib` | Placeholder for built library files |
| `/samples` | Example programs to get you started and for reference |
| `/scripts` | Helpful scripts to view Orbis ELF (OELF) information as well as other various tools |
| `/src` | Contains source code for CRT, modules, and VS templates |



## Setup & Installation

The clang toolchain as well as the llvm linker (lld) is needed to compile and link using this SDK. For Windows, these can be downloaded using the [Pre-Built Binaries](https://releases.llvm.org/download.html) provided by LLVM. For Linux and macOS, the same page contains pre-built binaries, however you can also use the following commands (Debian/Ubuntu):

```bash
sudo apt update
sudo apt install clang
sudo apt install lld
```
In case you're using any Arch derivative:

```bash
sudo pacman -S clang
sudo pacman -S lld
```

macOS users can use [Homebrew](https://brew.sh/) to install a pure copy of LLVM (the Apple version would not work with the toolchain!)

```bash
brew install llvm
```

In the future, we may include pre-built binaries for clang/lld, however for the present, it is required for you to install these separately.

The `OO_PS4_TOOLCHAIN` environment variable also needs to be set. On Windows, this can be done using the environment variables control panel. On linux and macOS, the following command can be added to `~/.bashrc` (Debian/Ubuntu), `~/.bash_profile` (macOS Mojave and lower) or `~/.zshrc` (macOS Catalina):

```bash
export OO_PS4_TOOLCHAIN=[directory of installation]
```

If you don't wish to restart your shell, remember to `source` your updated profile for it to take effect.

This is needed so the build scripts and the converter tool know where to look for certain files. It is also recommended you add the root SDK directory + `/bin` to your path variable.

### Windows Installer
For Windows, a Nullsoft scriptable installer is provided, which will automate the process of extracting the toolchain files and setting the `OO_PS4_TOOLCHAIN` environment variable.

Dependency [.NET Core 3.0 Runtime](https://dotnet.microsoft.com/en-us/download/dotnet/thank-you/runtime-3.0.3-windows-x64-installer) is required to run LibOrbisPkg tools as part of build process.

### Linux
For Linux, after installing the required dependencies and setting up the environment variable as noted above, you should be good to go.

### macOS
For macOS, a PKG installer is provided, which will automate the process of extracting the toolchain files and setting the `OO_PS4_TOOLCHAIN` environment variable in both bash and zsh shells.

## Creating Homebrew Projects

For Windows, `/extra` provides Visual Studio templates which can be added into your VS installation's templates directory to allow easy creation of homebrew projects. You can also copy and modify the solutions from the provided samples.

For Linux and macOS, `/extra` contains a `setup-project.sh` script which will create a project directory based on the `hello_world` sample.

## Contribution

Contribution is welcome, the OpenOrbis toolchain is open source after all. For those eager to contribute, we have an actively maintained list of issues on [CONTRIBUTING.md](/CONTRIBUTING.md) that are accessible and would be awesome to get closed. We appreciate anyone who contributes and acknowledgements will be maintained in this README.

## Dependencies

There are various dependencies that need to be pulled in and compiled if you wish to build the toolchain from source. This includes musl libc, libcxx, library stubs, and other tools.

### musl
https://github.com/OpenOrbis/musl

Samples all link against a statically-compiled musl libc fork for PS4.

### libcxx
https://github.com/OpenOrbis/llvm-project

Samples that use C++ and use the stdlib link against a statically-compiled libcxx from an llvm-project fork for PS4.

### SDL-PS4
https://github.com/OpenOrbis/SDL-PS4

The SDL2 sample uses a port of the SDL library done by znullptr.

### orbis-lib-gen
https://github.com/OpenOrbis/orbis-lib-gen

The `orbis-lib-gen` tool is used to generate library stubs, which are needed for linking against PS4-exclusive libraries.

### create-fself
https://github.com/OpenOrbis/create-fself

The `create-fself` tool is used to generate the final eboot.bin (for games/apps) or library PRX files that are compatible with PS4.

### create-gp4

The `create-gp4` tool is used to programmatically create .PKG project files for use with maxton's publishing tools.

### readoelf

The `readoelf` tool is a custom-rolled variant of `readelf` for parsing Sony's modified ELF format.

### LibOrbisPkg

Maxton's publishing tools are used to create param.sfo and the final .PKG file to install on the PS4.

## Scripts

All scripts in the `/scripts` directory are Python 3 scripts, specifically targeting Python 3.7.0, with the exception of `/scripts/make_fself.py`. You will need Python installed on your system to run these scripts. Usage of these scripts can be found in [/scripts/README.md](/scripts/README.md).

**autobuild.py** - is an automated pkg generating script based on project dir content (may be unstable, wait for release build)

**dynamic_entries.py** - Gets a list of dynamic entries from the dynamic table of Orbis ELFs.

**make_fself.py** - Copy of flatz' script to generate fake SELF files. This functionality has now been integrated as a part of `create-eboot` and `create-lib`.

**program_headers.py** - Gets a list of program headers from the program header table of Orbis ELFs.

**rela_entries.py** - Gets a list of relocation with addend (RELA) entries from the relocation table of Orbis ELFs.

**symbol_entries.py** - Gets a list of symbols from the symbol table of Orbis ELFs.

## License

[OpenOrbis](https://github.com/OpenOrbis).

This project is licensed under the GPLv3 license - see the [LICENSE](LICENSE) file for details.

The accompanying LLVM binaries are licensed under the Apache 2.0 license and is owned by LLVM. Under that license, redistribution is allowed.

## Credits + Special Thanks

- Specter: Create-eboot/lib relinker, miralib, assistant suite, readelf, samples and documentation
- CrazyVoid: Stub generator, headers, samples and documentation
- maxton: Create-pkg pkg and SFO generation tools
- Kiwidog: Mira, assistance, documentation
- IDC: Lots of help with libraries and other bug fixes
- flatz: Homebrew research and writeups, SELF reversing and documentation
- m0rph3us1987: Help with debugging stuff
- bigboss / psxdev: Library research and reverse engineering, used for reference by various samples
- John Tormblom: Build system prototyping
- LightningMods / LM: Testing via APP_HOME and lib loading help on the Mira side
- Lord Friky: Proper macOS support
- sleirsgoevy: Bug fixes and support, various samples
- ChendoChap: Bug fixes and support
- astrelsky: Bug fixes and support
- Nikita Krapivin: C++ exception support, openGL/piglet work
- MrSlick: Awesome logo <3
- OpenOrbis Team
- Other anonymous contributors
