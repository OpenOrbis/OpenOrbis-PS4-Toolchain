SETLOCAL EnableDelayedExpansion

Rem Libraries to link in
<<<<<<< HEAD
set libraries=-lc -lkernel -lc++

Rem set extra_flags=
=======
set libraries=-lc -c++ -lkernel
>>>>>>> eb303117c7de43cd59453a3801872ab46c13195f

Rem Read the script arguments into local vars
set intdir=%1
set targetname=%~2
set outputPath=%3

<<<<<<< HEAD
set outputElf=%intdir%\%targetname%.elf
set outputOelf=%intdir%\%targetname%.oelf
set outputPrx=%targetname%.prx
set outputStub=%targetname%_stub.so

@mkdir %intdir%
=======
set outputElf=%intdir%%targetname%.elf
set outputOelf=%intdir%%targetname%.oelf
set outputPrx=%intdir%%targetname%.prx
set outputStub=%intdir%%targetname%_stub.so
>>>>>>> eb303117c7de43cd59453a3801872ab46c13195f

Rem Compile object files for all the source files
for %%f in (*.c) do (
    clang --target=x86_64-pc-freebsd12-elf -fPIC -funwind-tables -I"%OO_PS4_TOOLCHAIN%\\include" %extra_flags% -c -o %intdir%\%%~nf.o %%~nf.c
)

for %%f in (*.cpp) do (
    clang++ --target=x86_64-pc-freebsd12-elf -fPIC -funwind-tables -I"%OO_PS4_TOOLCHAIN%\\include" -I"%OO_PS4_TOOLCHAIN%\\include\\c++\\v1" %extra_flags% -c -o %intdir%\%%~nf.o %%~nf.cpp
)

Rem Get a list of object files for linking
set obj_files=
for %%f in (%intdir%\\*.o) do set obj_files=!obj_files! .\%%f

Rem Link the input ELF
ld.lld -m elf_x86_64 -pie --script "%OO_PS4_TOOLCHAIN%\link.x" --eh-frame-hdr -o "%outputElf%" "-L%OO_PS4_TOOLCHAIN%\lib" %libraries% --verbose "%OO_PS4_TOOLCHAIN%\lib\crtlib.o" %obj_files%

Rem Create stub shared libraries
for %%f in (*.c) do (
    clang -target x86_64-pc-linux-gnu -ffreestanding -nostdlib -fno-builtin -fPIC -c -I"%OO_PS4_TOOLCHAIN%\include" -o %intdir%\%%~nf.o.stub %%~nf.cpp
)

for %%f in (*.cpp) do (
    clang++ -target x86_64-pc-linux-gnu -ffreestanding -nostdlib -fno-builtin -fPIC -c -I"%OO_PS4_TOOLCHAIN%\include" -I"%OO_PS4_TOOLCHAIN%\\include\\c++\\v1" -o %intdir%\%%~nf.o.stub %%~nf.cpp
)

set stub_obj_files=
for %%f in (%intdir%\\*.o.stub) do set stub_obj_files=!stub_obj_files! .\%%f

clang++ -target x86_64-pc-linux-gnu -shared -fuse-ld=lld -ffreestanding -nostdlib -fno-builtin "-L%OO_PS4_TOOLCHAIN%\lib" %libraries% %stub_obj_files% -o "%outputStub%"

Rem Create the prx
<<<<<<< HEAD
%OO_PS4_TOOLCHAIN%\bin\windows\create-fself.exe -in "%outputElf%" --out "%outputOelf%" --lib "%outputPrx%" --paid 0x3800000000000011

Rem Eboot cleanup
copy %outputPrx% %outputPath%\%outputPrx%
copy %outputStub%%outputPath%\%outputStub%
del %outputPrx%
del %outputStub%
=======
%OO_PS4_TOOLCHAIN%\bin\windows\create-lib.exe -in "%outputElf%" --out "%outputOelf%" --paid 0x3800000000000011
>>>>>>> eb303117c7de43cd59453a3801872ab46c13195f

Rem cleanup...
rd /s /q %intdir%
Rem rd /s /q %intdir%\..\
