## Windows
# create-eboot
GOOS=windows go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot.exe
mv ./create-eboot.exe ${OO_PS4_TOOLCHAIN}/bin/windows/create-eboot.exe

GOOS=windows go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib.exe
mv ./create-lib.exe ${OO_PS4_TOOLCHAIN}/bin/windows/create-lib.exe

## Linux and macOS
uname_s=`uname -s`

if [ "$uname_s" = "Linux" ] ; then
  cdir="linux"
elif [ "$uname_s" = "Darwin" ] ; then
  cdir="macos"
fi

# create-eboot
go build -ldflags='-X main.TOOL_MODE=SELF' -o create-eboot
mv ./create-eboot ${OO_PS4_TOOLCHAIN}/bin/${cdir}/create-eboot

# create-lib
go build -ldflags='-X main.TOOL_MODE=SPRX' -o create-lib
mv ./create-lib ${OO_PS4_TOOLCHAIN}/bin/${cdir}/create-lib
