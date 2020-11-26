TOOLCHAIN   := $(OO_PS4_TOOLCHAIN)
PROJDIR     := $(shell basename $(CURDIR))

# Libraries linked into the ELF.
LIBS        := -lc -lkernel -lc++

# Compiler options. You likely won't need to touch these.
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
		CC      := clang++
		LD      := ld.lld
		CDIR    := linux
endif
ifeq ($(UNAME_S),Darwin)
		CC      := /usr/local/opt/llvm/bin/clang++
		LD      := /usr/local/opt/llvm/bin/ld.lld
		CDIR    := macos
endif
ODIR        := obj/
SDIR        := $(PROJDIR)
IDIRS       := -I$(TOOLCHAIN)/include -I$(TOOLCHAIN)/include/c++/v1
LDIRS       := -L$(TOOLCHAIN)/lib
CFLAGS      := -target x86_64-pc-freebsd-elf -funwind-tables -fPIC $(IDIRS) -fuse-init-array -debug-info-kind=limited -debugger-tuning=gdb -emit-obj
LFLAGS      := -m elf_x86_64 -pie --script $(TOOLCHAIN)/link.x --eh-frame-hdr $(LDIRS) $(LIBS) $(TOOLCHAIN)/lib/crt1.o

CFILES      := $(wildcard $(SDIR)/*.c)
CPPFILES    := $(wildcard $(SDIR)/*.cpp)
OBJS        := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CFILES)) $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CPPFILES))

TARGET = eboot.bin

# Create the intermediate directory incase it doesn't already exist.
_unused := $(shell mkdir -p obj)

.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o

fptr:
	$(CC) -c $(CFLAGS) -o $(ODIR)/fptr.o fptr.c
	$(LD) $(ODIR)/fptr.o -o $(ODIR)/fptr.elf $(LFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-eboot -in=$(ODIR)/fptr.elf -out=$(ODIR)/fptr.oelf --paid 0x3800000000000011

malloc_lock_benchmarking:
	$(CC) -c $(CFLAGS) -o $(ODIR)/malloc_lock_benchmarking.o malloc_lock_benchmarking.c
	$(LD) $(ODIR)/malloc_lock_benchmarking.o -o $(ODIR)/malloc_lock_benchmarking.elf $(LFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-eboot -in=$(ODIR)/malloc_lock_benchmarking.elf -out=$(ODIR)/malloc_lock_benchmarking.oelf --paid 0x3800000000000011

tls:
	$(CC) -c $(CFLAGS) -o $(ODIR)/tls.o tls.c
	$(LD) $(ODIR)/tls.o -o $(ODIR)/tls.elf $(LFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-eboot -in=$(ODIR)/tls.elf -out=$(ODIR)/tls.oelf --paid 0x3800000000000011
