## Windows
# create-eboot
GOOS=windows go build -o readelf.exe
mv ./readelf.exe ${OO_PS4_TOOLCHAIN}/bin/windows/readelf.exe

## Linux and macOS

if [ "$uname_s" = "Linux" ] ; then
  cdir="linux"
elif [ "$uname_s" = "Darwin" ] ; then
  cdir="macos"
fi

# create-eboot
go build -o readelf
mv ./readelf ${OO_PS4_TOOLCHAIN}/bin/${cdir}/readelf
