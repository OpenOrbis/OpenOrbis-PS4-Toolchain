@ECHO OFF

IF NOT EXIST "build" MKDIR "build"

REM Windows
SET GOOS=windows

IF NOT EXIST "%OO_PS4_TOOLCHAIN%\bin\windows" MKDIR %OO_PS4_TOOLCHAIN%\bin\windows

REM create-eboot
go.exe build -o build\readelf.exe
COPY /Y build\readelf.exe %OO_PS4_TOOLCHAIN%\bin\windows\readelf.exe

REM Linux
SET GOOS=linux

IF NOT EXIST "%OO_PS4_TOOLCHAIN%\bin\linux" MKDIR %OO_PS4_TOOLCHAIN%\bin\linux

REM create-eboot
go.exe build -o build\readelf
COPY /Y build\readelf %OO_PS4_TOOLCHAIN%\bin\linux\readelf

REM MacOS
SET GOOS=darwin

IF NOT EXIST "%OO_PS4_TOOLCHAIN%\bin\macos" MKDIR %OO_PS4_TOOLCHAIN%\bin\macos

REM create-eboot
go.exe build -o build\readelfosx
COPY /Y build\readelfosx %OO_PS4_TOOLCHAIN%\bin\macos\readelf