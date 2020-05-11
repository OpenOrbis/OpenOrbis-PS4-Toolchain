# Windows
# create-eboot
GOOS=windows go build -o readelf.exe
mv ./readelf.exe ${OO_PS4_TOOLCHAIN}/bin/windows/readelf.exe

## Linux
# create-eboot
go build -o readelf
mv ./readelf ${OO_PS4_TOOLCHAIN}/bin/linux/readelf
