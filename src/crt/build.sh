as crt1.S -o crt1.o
as crtlib.S -o crtlib.o

mv ./crt1.o ${OO_PS4_TOOLCHAIN}/lib/crt1.o
mv ./crtlib.o ${OO_PS4_TOOLCHAIN}/lib/crtlib.o

