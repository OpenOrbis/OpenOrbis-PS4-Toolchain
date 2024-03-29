TOOLCHAIN 	:= $(OO_PS4_TOOLCHAIN)
PROJDIR   	:= $(shell basename $(CURDIR))
INTDIR    	:= $(PROJDIR)/x64/Debug

# Libraries linked into the ELF.
LIBS 		:= -lSceLibcInternal -lkernel

# Compiler options. You likely won't need to touch these.
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
		CC      := clang
		CCX     := clang++
		LD      := ld.lld
		CDIR    := linux
endif
ifeq ($(UNAME_S),Darwin)
		CC      := /usr/local/opt/llvm/bin/clang
		CCX     := /usr/local/opt/llvm/bin/clang++
		LD      := /usr/local/opt/llvm/bin/ld.lld
		CDIR    := macos
endif

ODIR 		:= $(INTDIR)
SDIR 		:= $(PROJDIR)
IDIRS 		:= -I$(TOOLCHAIN)/include
LDIRS 		:= -L$(TOOLCHAIN)/lib
CFLAGS 		:= -cc1 -triple x86_64-scei-ps4-elf $(IDIRS) -emit-obj
LFLAGS 		:= -m elf_x86_64 -pie --version-script="right/right.version" --script $(TOOLCHAIN)/link.x --eh-frame-hdr $(LDIRS) $(LIBS) $(TOOLCHAIN)/lib/crtlib.o

CFILES 		:= $(wildcard $(SDIR)/*.c)
CPPFILES 	:= $(wildcard $(SDIR)/*.cpp)
OBJS 		:= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CFILES)) $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CPPFILES))
STUBOBJS 	:= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o.stub, $(CFILES)) $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o.stub, $(CPPFILES))

TARGET = right.sprx

# Create the intermediate directory incase it doesn't already exist.
_unused := $(shell mkdir -p $(INTDIR))

# Make rules
$(TARGET): $(ODIR) $(OBJS)
	$(LD) $(ODIR)/*.o -o $(ODIR)/$(PROJDIR).elf $(LFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-fself -in=$(ODIR)/$(PROJDIR).elf -out=$(ODIR)/$(PROJDIR).oelf --lib=$(TARGET) --paid 0x3800000000000011 --libname "sceGameRight"

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR):
	@mkdir $@

.PHONY: clean
.DEFAULT_GOAL := all

all: $(TARGET)

clean:
	rm -f $(TARGET) $(ODIR)/*.o
