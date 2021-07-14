#!/bin/bash

# Pull source code
git clone --depth=1 https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain && rm -rf /OpenOrbis-PS4-Toolchain/.git
git clone --depth=1 https://github.com/OpenOrbis/musl
git clone --depth=1 https://github.com/OpenOrbis/llvm-project

# Build musl
cd /musl
./configure --target=x86_64-scei-ps4 --disable-shared CC=clang CFLAGS="-fPIC -DPS4" --prefix=/ps4
make && make install

# Build libunwind
mkdir /llvm-project/libunwind/build && cd /llvm-project/libunwind/build
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DLIBUNWIND_ENABLE_SHARED=0 -DCMAKE_C_FLAGS="-fPIC" -DCMAKE_CXX_FLAGS="-fPIC" -DLLVM_PATH="/llvm-project/llvm" .. && make

# Build libcxxabi
mkdir /llvm-project/libcxxabi/build && cd /llvm-project/libcxxabi/build
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_SHARED_LINKER_FLAGS="-L/llvm-project/libunwind/build/lib" -DLIBCXXABI_USE_LLVM_UNWINDER=1 -DLIBCXXABI_LIBUNWIND_PATH="/llvm-project/libunwind" -DLIBCXXABI_LIBCXX_INCLUDES="/llvm-project/libcxx/include" -DLIBCXXABI_ENABLE_PIC=1 -DLLVM_PATH=/llvm-project/llvm .. && make

# Build libcxx
mkdir /llvm-project/libcxx/build && cd /llvm-project/libcxx/build
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DLIBCXX_HAS_MUSL_LIBC=1 -DLIBCXX_ENABLE_SHARED=NO -DLIBCXX_ENABLE_STATIC=YES -DLIBCXX_HAS_GCC_S_LIB=0 -DLIBCXX_ENABLE_THREADS=0 -DLIBCXX_CXX_ABI=libcxxabi -DLIBCXX_CXX_ABI_INCLUDE_PATHS="/llvm-project/libcxxabi/include" -DLIBCXX_CXX_ABI_LIBRARY_PATH="/llvm-project/libcxxabi/build/lib" -DLIBCXX_ENABLE_STATIC_ABI_LIBRARY=ON -DLLVM_PATH="/llvm-project/llvm" -DCMAKE_C_FLAGS="-DPS4 -fPIC" -DCMAKE_CXX_FLAGS="-DPS4 -fPIC" .. && cmake -DCMAKE_SYSROOT="/OpenOrbis-PS4-Toolchain" .. && make

# Build create-eboot and create-lib
cd /OpenOrbis-PS4-Toolchain/src/tools/create-eboot

GOOS=windows GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot.exe && mv ./create-eboot.exe /OpenOrbis-PS4-Toolchain/bin/windows/create-eboot.exe
GOOS=windows GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib.exe && mv ./create-lib.exe /OpenOrbis-PS4-Toolchain/bin/windows/create-lib.exe

GOOS=linux GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot && mv ./create-eboot /OpenOrbis-PS4-Toolchain/bin/linux/create-eboot
GOOS=linux GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib && mv ./create-lib /OpenOrbis-PS4-Toolchain/bin/linux/create-lib

GOOS=darwin GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot && mv ./create-eboot /OpenOrbis-PS4-Toolchain/bin/macos/create-eboot
GOOS=darwin GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib && mv ./create-lib /OpenOrbis-PS4-Toolchain/bin/macos/create-lib

# Build readelf
cd /OpenOrbis-PS4-Toolchain/src/tools/readelf

GOOS=windows GOARCH=amd64 go build -o readelf.exe && mv ./readelf.exe /OpenOrbis-PS4-Toolchain/bin/windows/readelf.exe
GOOS=linux GOARCH=amd64 go build -o readelf && mv ./readelf /OpenOrbis-PS4-Toolchain/bin/linux/readelf
GOOS=darwin GOARCH=amd64 go build -o readelf && mv ./readelf /OpenOrbis-PS4-Toolchain/bin/macos/readelf

# Pull maxton's publishing tools (<3)
cd /OpenOrbis-PS4-Toolchain/bin/windows && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgEditor-0.2.231.zip && unzip PkgEditor-0.2.231.zip && rm PkgEditor-0.2.231.zip
cd /OpenOrbis-PS4-Toolchain/bin/linux && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgTool.Core-linux-x64-0.2.231.zip && unzip PkgTool.Core-linux-x64-0.2.231.zip && rm PkgTool.Core-linux-x64-0.2.231.zip && chmod +x PkgTool.Core
cd /OpenOrbis-PS4-Toolchain/bin/macos && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgTool.Core-osx-x64-0.2.231.zip && unzip PkgTool.Core-osx-x64-0.2.231.zip && rm PkgTool.Core-osx-x64-0.2.231.zip && chmod +x PkgTool.Core

# Copy crtlib
cd /OpenOrbis-PS4-Toolchain/src/crt && as crtlib.S -o crtlib.o && mv crtlib.o /OpenOrbis-PS4-Toolchain/lib

# Copy musl built libs
cd /ps4 && cp -r lib /OpenOrbis-PS4-Toolchain

# Combine libc++ and libunwind into a single archive
cd /OpenOrbis-PS4-Toolchain/lib && echo "create libc++.a\naddlib /llvm-project/libunwind/build/lib/libunwind.a\naddlib /llvm-project/libcxx/build/lib/libc++.a\nsave\nend" | llvm-ar -M

# Build library stubs
cd /OpenOrbis-PS4-Toolchain/src/lib && make && cp /OpenOrbis-PS4-Toolchain/src/lib/build/lib/* /OpenOrbis-PS4-Toolchain/lib
rm -r /OpenOrbis-PS4-Toolchain/src/lib/build/lib/*.so && rm -r /OpenOrbis-PS4-Toolchain/src/lib/build/*.o

# Build example stub
cd /OpenOrbis-PS4-Toolchain/samples/library_example && make

# Cleanup
rm -rf /ps4 && rm -rf /musl && rm -rf /llvm-project

# Create a tarball
mkdir /out && cd /out
tar -cvzf OpenOrbis-PS4-Toolchain.tar.gz /OpenOrbis-PS4-Toolchain