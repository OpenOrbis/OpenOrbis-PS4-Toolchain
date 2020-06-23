## Windows
GOOS=windows go build -o readelf.exe
mv ./readelf.exe ${OO_PS4_TOOLCHAIN}/bin/windows/readelf.exe

## Linux
go build -o readelf
mv ./readelf ${OO_PS4_TOOLCHAIN}/bin/linux/readelf

## MacOS
GOOS=darwin GOARCH=amd64 go build -o readelfosx
mv ./readelfosx ${OO_PS4_TOOLCHAIN}/bin/macos/readelf
