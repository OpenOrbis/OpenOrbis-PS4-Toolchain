## Windows
GOOS=windows go build -o create-gp4.exe
mv ./create-gp4.exe ${OO_PS4_TOOLCHAIN}/bin/windows/create-gp4.exe

## Linux
go build -o create-gp4
mv ./create-gp4 ${OO_PS4_TOOLCHAIN}/bin/linux/create-gp4

## MacOS
GOOS=darwin GOARCH=amd64 go build -o create-gp4osx
mv ./create-gp4osx ${OO_PS4_TOOLCHAIN}/bin/macos/create-gp4
