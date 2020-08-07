TOOLCHAIN   := $(OO_PS4_TOOLCHAIN)
PROJDIR     := $(shell basename $(CURDIR))
INTDIR      := $(PROJDIR)/x64/Debug

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
ODIR        := $(INTDIR)
SDIR        := $(PROJDIR)
IDIRS       := -I$(TOOLCHAIN)/include -I$(TOOLCHAIN)/include/c++/v1
LDIRS       := -L$(TOOLCHAIN)/lib
CFLAGS      := -cc1 -triple x86_64-pc-freebsd-elf -munwind-tables $(IDIRS) -fuse-init-array -debug-info-kind=limited -debugger-tuning=gdb -emit-obj
LFLAGS      := -m elf_x86_64 -pie --script $(TOOLCHAIN)/link.x --eh-frame-hdr $(LDIRS) $(LIBS) $(TOOLCHAIN)/lib/crt1.o

CFILES      := $(wildcard $(SDIR)/*.c)
CPPFILES    := $(wildcard $(SDIR)/*.cpp)
OBJS        := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CFILES)) $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CPPFILES))

TARGET = eboot.bin

# Create the intermediate directory incase it doesn't already exist.
_unused := $(shell mkdir -p $(INTDIR))

# Make rules
$(TARGET): $(ODIR) $(OBJS)
	$(LD) $(ODIR)/*.o -o $(ODIR)/$(PROJDIR).elf $(LFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-eboot -in=$(ODIR)/$(PROJDIR).elf -out=$(ODIR)/$(PROJDIR).oelf --paid 0x3800000000000011

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR):
	@mkdir $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o
