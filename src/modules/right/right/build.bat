SETLOCAL EnableDelayedExpansion

Rem Libraries to link in
set libraries=-lkernel

Rem Read the script arguments into local vars
set intdir=%1
set targetname=%~2
set outputPath=%3

set outputElf=%intdir%%targetname%.elf
set outputOelf=%intdir%%targetname%.oelf
set outputStub=%intdir%%targetname%_stub.so

@mkdir %intdir%

Rem Compile object files for all the source files
for %%f in (*.cpp) do (
    clang -cc1 -triple x86_64-scei-ps4-elf -munwind-tables -I"%OO_PS4_TOOLCHAIN%\include" -emit-obj -o %intdir%\%%~nf.o %%~nf.c
)

Rem Get a list of object files for linking
set obj_files=
for %%f in (%intdir%\\*.o) do set obj_files=!obj_files! .\%%f

Rem Link the input ELF
ld.lld -m elf_x86_64 -pie --version-script="right.version" --script "%OO_PS4_TOOLCHAIN%\link.x" --eh-frame-hdr -o "%outputElf%" "-L%OO_PS4_TOOLCHAIN%\lib" %libraries% --verbose "%OO_PS4_TOOLCHAIN%\lib\crtlib.o" %obj_files%

Rem Create the prx
%OO_PS4_TOOLCHAIN%\bin\windows\create-fself.exe -in "%outputElf%" --out "%outputOelf%" --lib "lib.prx" --paid 0x3800000000000011 --libname "sceGameRight"

Rem Cleanup
copy "lib.prx" %outputPath%\%targetname%.sprx"
del "lib.prx"
