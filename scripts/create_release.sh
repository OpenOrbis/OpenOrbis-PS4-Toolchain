#!/bin/sh
set -x

# Build the create-eboot and create-lib tools
cd ${OO_PS4_TOOLCHAIN}/src/tools/create-eboot
sh build.sh

# Build readelf
cd ${OO_PS4_TOOLCHAIN}/src/tools/readelf
sh build.sh

# Copy maxton's package editor binaries to /bin
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/LIBORBIS-LICENSE.txt ${OO_PS4_TOOLCHAIN}/bin/windows/LIBORBIS-LICENSE.txt
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/LIBORBIS-LICENSE.txt ${OO_PS4_TOOLCHAIN}/bin/linux/LIBORBIS-LICENSE.txt
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/LIBORBIS-LICENSE.txt ${OO_PS4_TOOLCHAIN}/bin/macos/LIBORBIS-LICENSE.txt
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/windows/LibOrbisPkg.dll ${OO_PS4_TOOLCHAIN}/bin/windows/LibOrbisPkg.dll
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/windows/PkgEditor.exe ${OO_PS4_TOOLCHAIN}/bin/windows/PkgEditor.exe
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/linux/PkgTool.Core ${OO_PS4_TOOLCHAIN}/bin/linux/PkgTool.Core
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/macos/PkgTool.Core ${OO_PS4_TOOLCHAIN}/bin/macos/PkgTool.Core

# Build libraries and copy them to /lib
cd ${OO_PS4_TOOLCHAIN}/src/lib
make

cp ${OO_PS4_TOOLCHAIN}/src/lib/build/* ${OO_PS4_TOOLCHAIN}/lib

# Copy libc and libc++ libraries to /lib
cp ${OO_PS4_TOOLCHAIN_PREBUILT}/libs/* ${OO_PS4_TOOLCHAIN}/lib
