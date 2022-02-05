as crt1.S -fPIC -o crt1.o
as crtlib.S -fPIC -o crtlib.o

mv ./crt1.o ${OO_PS4_TOOLCHAIN}/lib/crt1.o
mv ./crtlib.o ${OO_PS4_TOOLCHAIN}/lib/crtlib.o

