@ECHO OFF

IF NOT EXIST "build" MKDIR "build"

REM Windows
SET GOOS=windows

IF NOT EXIST "%OO_PS4_TOOLCHAIN%\bin\windows" MKDIR %OO_PS4_TOOLCHAIN%\bin\windows

REM create-eboot
go.exe build -ldflags "-X main.TOOL_MODE=SELF" -o build\create-eboot.exe
COPY /Y build\create-eboot.exe %OO_PS4_TOOLCHAIN%\bin\windows\create-eboot.exe

go.exe build -ldflags "-X main.TOOL_MODE=SPRX" -o build\create-lib.exe
COPY /Y build\create-lib.exe %OO_PS4_TOOLCHAIN%\bin\windows\create-lib.exe

REM Linux
SET GOOS=linux

IF NOT EXIST "%OO_PS4_TOOLCHAIN%\bin\linux" MKDIR %OO_PS4_TOOLCHAIN%\bin\linux

REM create-eboot
go.exe build -ldflags "-X main.TOOL_MODE=SELF" -o build\create-eboot
COPY /Y build\create-eboot %OO_PS4_TOOLCHAIN%\bin\linux\create-eboot

REM create-lib
go.exe build -ldflags "-X main.TOOL_MODE=SPRX" -o build\create-lib
COPY /Y build\create-lib %OO_PS4_TOOLCHAIN%\bin\linux\create-lib

REM MacOS
SET GOOS=darwin

IF NOT EXIST "%OO_PS4_TOOLCHAIN%\bin\macos" MKDIR %OO_PS4_TOOLCHAIN%\bin\macos

REM create-eboot
go.exe build -ldflags "-X main.TOOL_MODE=SELF" -o build\create-eboot
COPY /Y build\create-eboot %OO_PS4_TOOLCHAIN%\bin\macos\create-eboot

REM create-lib
go.exe build -ldflags "-X main.TOOL_MODE=SPRX" -o build\create-lib
COPY /Y build\create-lib %OO_PS4_TOOLCHAIN%\bin\macos\create-lib
