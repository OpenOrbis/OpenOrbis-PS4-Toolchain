#!/bin/bash

# Define global vars
export CC="clang"
export CXX="clang++"
export AR="llvm-ar"
export LLVM_PATH="/llvm-project/llvm"
export OO_PS4_TOOLCHAIN="/OpenOrbis-PS4-Toolchain"
export OO_SYSROOT="$OO_PS4_TOOLCHAIN"
# These flags are used everywhere, so let's reuse them.
export CFLAGS="-fPIC -DPS4 -D_LIBUNWIND_IS_BAREMETAL=1"
# Nothing here yet.
export CXXFLAGS=""

rm -rf OpenOrbis-PS4-Toolchain
rm -rf musl
rm -rf ps4
rm -rf llvm-project
mkdir ps4

# Pull source code
git clone --depth=1 https://github.com/nekohaku/OpenOrbis-PS4-Toolchain && rm -rf /OpenOrbis-PS4-Toolchain/.git
git clone --depth=1 https://github.com/OpenOrbis/musl
git clone --depth=1 https://github.com/OpenOrbis/llvm-project

# Build musl
cd /musl
./configure --target=x86_64-scei-ps4 --disable-shared CC="$CC" CFLAGS="$CFLAGS" --prefix=/ps4
make && make install

# Build compiler-rt
mkdir /llvm-project/compiler-rt/build && cd /llvm-project/compiler-rt/build
cmake -DCMAKE_C_COMPILER="$CC" -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_C_FLAGS="$CFLAGS" -DCMAKE_CXX_FLAGS="$CFLAGS $CXXFLAGS" -DLLVM_PATH="$LLVM_PATH" -DCOMPILER_RT_DEFAULT_TARGET_TRIPLE="x86_64-scei-ps4" -DCOMPILER_RT_BAREMETAL_BUILD=YES -DCOMPILER_RT_BUILD_BUILTINS=ON -DCOMPILER_RT_BUILD_CRT=OFF -DCOMPILER_RT_BUILD_SANITIZERS=OFF -DCOMPILER_RT_BUILD_XRAY=OFF -DCOMPILER_RT_BUILD_LIBFUZZER=OFF -DCOMPILER_RT_BUILD_PROFILE=OFF .. && make

# Build libunwind
mkdir /llvm-project/libunwind/build && cd /llvm-project/libunwind/build
cmake -DCMAKE_C_COMPILER="$CC" -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_C_FLAGS="$CFLAGS" -DCMAKE_CXX_FLAGS="$CFLAGS $CXXFLAGS" -DLLVM_PATH="$LLVM_PATH" -DLIBUNWIND_USE_COMPILER_RT=YES -DLIBUNWIND_BUILD_32_BITS=NO -DLIBUNWIND_ENABLE_STATIC=ON -DLIBUNWIND_USE_COMPILER_RT=YES -DLIBUNWIND_ENABLE_SHARED=OFF .. && make

# Build libcxxabi
mkdir /llvm-project/libcxxabi/build && cd /llvm-project/libcxxabi/build
cmake -DCMAKE_C_COMPILER="$CC" -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_C_FLAGS="$CFLAGS -I$OO_PS4_TOOLCHAIN/include" -DCMAKE_CXX_FLAGS="$CFLAGS $CXXFLAGS -I$OO_PS4_TOOLCHAIN/include" -DLLVM_PATH="$LLVM_PATH" -DLIBCXXABI_ENABLE_SHARED=NO -DLIBCXXABI_ENABLE_STATIC=YES -DLIBCXXABI_ENABLE_EXCEPTIONS=YES -DLIBCXXABI_USE_COMPILER_RT=YES -DLIBCXXABI_USE_LLVM_UNWINDER=YES -DLIBCXXABI_LIBUNWIND_PATH="/llvm-project/libunwind" -DLIBCXXABI_LIBCXX_INCLUDES="/llvm-project/libcxx/include" -DLIBCXXABI_ENABLE_PIC=YES .. && make

# Build libcxx
mkdir /llvm-project/libcxx/build && cd /llvm-project/libcxx/build
cmake -DCMAKE_C_COMPILER="$CC" -DCMAKE_CXX_COMPILER="$CXX" -DCMAKE_C_FLAGS="$CFLAGS -I$OO_PS4_TOOLCHAIN/include" -DCMAKE_CXX_FLAGS="$CFLAGS $CXXFLAGS -I$OO_PS4_TOOLCHAIN/include" -DLLVM_PATH="$LLVM_PATH" -DLIBCXX_ENABLE_RTTI=YES -DLIBCXX_HAS_MUSL_LIBC=YES -DLIBCXX_ENABLE_SHARED=NO -DLIBCXX_CXX_ABI=libcxxabi -DLIBCXX_CXX_ABI_INCLUDE_PATHS="/llvm-project/libcxxabi/include" -DLIBCXX_CXX_ABI_LIBRARY_PATH="/llvm-project/libcxxabi/build/lib" .. && make

# Build create-eboot and create-lib
cd /OpenOrbis-PS4-Toolchain/src/tools/create-eboot

GOOS=windows GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot.exe && mv ./create-eboot.exe /OpenOrbis-PS4-Toolchain/bin/windows/create-eboot.exe
GOOS=windows GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib.exe   && mv ./create-lib.exe   /OpenOrbis-PS4-Toolchain/bin/windows/create-lib.exe

GOOS=linux   GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot     && mv ./create-eboot     /OpenOrbis-PS4-Toolchain/bin/linux/create-eboot
GOOS=linux   GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib       && mv ./create-lib       /OpenOrbis-PS4-Toolchain/bin/linux/create-lib

GOOS=darwin  GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot     && mv ./create-eboot     /OpenOrbis-PS4-Toolchain/bin/macos/create-eboot
GOOS=darwin  GOARCH=amd64 go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib       && mv ./create-lib       /OpenOrbis-PS4-Toolchain/bin/macos/create-lib

# Build create-gp4
cd /OpenOrbis-PS4-Toolchain/src/tools/create-gp4

GOOS=windows GOARCH=amd64 go build -o create-gp4.exe && mv ./create-gp4.exe /OpenOrbis-PS4-Toolchain/bin/windows/create-gp4.exe
GOOS=linux   GOARCH=amd64 go build -o create-gp4     && mv ./create-gp4     /OpenOrbis-PS4-Toolchain/bin/linux/create-gp4
GOOS=darwin  GOARCH=amd64 go build -o create-gp4     && mv ./create-gp4     /OpenOrbis-PS4-Toolchain/bin/macos/create-gp4

# Build readelf
cd /OpenOrbis-PS4-Toolchain/src/tools/readelf

GOOS=windows GOARCH=amd64 go build -o readelf.exe && mv ./readelf.exe /OpenOrbis-PS4-Toolchain/bin/windows/readelf.exe
GOOS=linux   GOARCH=amd64 go build -o readelf     && mv ./readelf     /OpenOrbis-PS4-Toolchain/bin/linux/readelf
GOOS=darwin  GOARCH=amd64 go build -o readelf     && mv ./readelf     /OpenOrbis-PS4-Toolchain/bin/macos/readelf

# Pull maxton's publishing tools (<3)
# Sadly maxton has passed on, we have forked the repository and will continue to update it in the future. RIP <3
cd /OpenOrbis-PS4-Toolchain/bin/windows && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgEditor-0.2.231.zip              && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgTool.Core-0.2.231.zip && unzip PkgEditor-0.2.231.zip && unzip PkgTool.Core-0.2.231.zip && rm PkgEditor-0.2.231.zip && rm PkgTool.Core-0.2.231.zip
cd /OpenOrbis-PS4-Toolchain/bin/linux   && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgTool.Core-linux-x64-0.2.231.zip && unzip PkgTool.Core-linux-x64-0.2.231.zip && rm PkgTool.Core-linux-x64-0.2.231.zip && chmod +x PkgTool.Core
cd /OpenOrbis-PS4-Toolchain/bin/macos   && wget https://github.com/maxton/LibOrbisPkg/releases/download/v0.2/PkgTool.Core-osx-x64-0.2.231.zip   && unzip PkgTool.Core-osx-x64-0.2.231.zip && rm PkgTool.Core-osx-x64-0.2.231.zip && chmod +x PkgTool.Core

# Copy crtlib
cd /OpenOrbis-PS4-Toolchain/src/crt && as crtlib.S -o crtlib.o && mv crtlib.o /OpenOrbis-PS4-Toolchain/lib

# Copy musl built libs
cd /ps4 && cp -r lib /OpenOrbis-PS4-Toolchain

# Build library stubs
cd /OpenOrbis-PS4-Toolchain/src/lib && make && cp /OpenOrbis-PS4-Toolchain/src/lib/build/lib/* /OpenOrbis-PS4-Toolchain/lib
rm -r /OpenOrbis-PS4-Toolchain/src/lib/build/lib/*.so && rm -r /OpenOrbis-PS4-Toolchain/src/lib/build/*.o

# Build example stub
cd /OpenOrbis-PS4-Toolchain/samples/library_example && make

# Copy the libc++ libraries
cp /llvm-project/compiler-rt/build/lib/linux/* /OpenOrbis-PS4-Toolchain/lib
cp /llvm-project/libcxx/build/lib/* /OpenOrbis-PS4-Toolchain/lib
cp /llvm-project/libcxxabi/build/lib/* /OpenOrbis-PS4-Toolchain/lib
cp /llvm-project/libunwind/build/lib/* /OpenOrbis-PS4-Toolchain/lib

# Combine libc++, libc++abi and libunwind into a single archive
touch /mri.txt
echo "CREATE libc++M.a"   >> /mri.txt
echo "ADDLIB libunwind.a" >> /mri.txt
echo "ADDLIB libc++abi.a" >> /mri.txt
echo "ADDLIB libc++.a"    >> /mri.txt
echo "SAVE"               >> /mri.txt
echo "END"                >> /mri.txt
cd /OpenOrbis-PS4-Toolchain/lib && $AR -M < /mri.txt && rm /mri.txt && rm libc++.a && mv libc++M.a libc++.a

# Merge compiler-rt into libc
touch /mri.txt
echo "CREATE libcM.a"                       >> /mri.txt
echo "ADDLIB libc.a"                        >> /mri.txt
echo "ADDLIB libclang_rt.builtins-x86_64.a" >> /mri.txt
echo "SAVE"                                 >> /mri.txt
echo "END"                                  >> /mri.txt
cd /OpenOrbis-PS4-Toolchain/lib && $AR -M < /mri.txt && rm /mri.txt && rm libc.a && mv libcM.a libc.a

# Cleanup
rm -rf /ps4 && rm -rf /musl && rm -rf /llvm-project

# Create a tarball
mkdir /out && cd /out
tar -cvzf OpenOrbis-PS4-Toolchain.tar.gz /OpenOrbis-PS4-Toolchain
