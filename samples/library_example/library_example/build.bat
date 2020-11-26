SETLOCAL EnableDelayedExpansion

Rem Libraries to link in
set libraries=-lSceLibcInternal -lkernel

Rem Read the script arguments into local vars
set intdir=%1
set targetname=%~2
set outputPath=%~3

set outputElf=%intdir%\%targetname%.elf
set outputOelf=%intdir%\%targetname%.oelf
set outputPrx=%intdir%\%targetname%.prx
set outputStub=%intdir%\%targetname%_stub.so

@mkdir %intdir%

Rem Compile object files for all the source files
for %%f in (*.cpp) do (
    clang++ -c -target x86_64-scei-ps4-elf -funwind-tables -fPIC -I"%OO_PS4_TOOLCHAIN%\include" -emit-obj -o %intdir%\%%~nf.o %%~nf.cpp
)

Rem Get a list of object files for linking
set obj_files=
for %%f in (%intdir%\\*.o) do set obj_files=!obj_files! .\%%f

Rem Link the input ELF
ld.lld -m elf_x86_64 -pie --script "%OO_PS4_TOOLCHAIN%\link.x" --eh-frame-hdr -o "%outputElf%" "-L%OO_PS4_TOOLCHAIN%\lib" -lSceLibcInternal -lkernel --verbose "%OO_PS4_TOOLCHAIN%\lib\crtlib.o" %obj_files%

Rem Create stub shared libraries
for %%f in (*.cpp) do (
    clang++ -c -target x86_64-pc-linux-gnu -ffreestanding -nostdlib -fno-builtin -fPIC -c -I"%OO_PS4_TOOLCHAIN%\include" -o %intdir%\%%~nf.o.stub %%~nf.cpp
)

set stub_obj_files=
for %%f in (%intdir%\\*.o.stub) do set stub_obj_files=!stub_obj_files! .\%%f

clang++ -c -target x86_64-pc-linux-gnu -shared -fuse-ld=lld -ffreestanding -nostdlib -fno-builtin "-L%OO_PS4_TOOLCHAIN%\lib" %libraries% %stub_obj_files% -o "%outputStub%"

Rem Create the prx
%OO_PS4_TOOLCHAIN%\bin\windows\create-lib.exe -in "%outputElf%" --out "%outputOelf%"

Rem Cleanup
copy "%outputPrx%" "%outputPath%\%targetname%.prx"
del "%outputPrx%"
