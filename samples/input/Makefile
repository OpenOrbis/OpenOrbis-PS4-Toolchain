TOOLCHAIN 	:= $(OO_PS4_TOOLCHAIN)
PROJDIR   	:= $(shell basename $(CURDIR))
INTDIR    	:= $(PROJDIR)/x64/Debug

# Libraries linked into the ELF.
LIBS 		:= -lc -lkernel -lScePad -lSceUserService

# Compiler options. You likely won't need to touch these.
CC 			:= clang++
LD 			:= ld.lld
ODIR 		:= $(INTDIR)
SDIR 		:= $(PROJDIR)
IDIRS 		:= -I$(TOOLCHAIN)/include
LDIRS 		:= -L$(TOOLCHAIN)/lib
CFLAGS 		:= -cc1 -triple x86_64-scei-ps4-elf -munwind-tables $(IDIRS) -emit-obj
LFLAGS 		:= -m elf_x86_64 -pie --script $(TOOLCHAIN)/link.x --eh-frame-hdr $(LDIRS) $(LIBS) $(TOOLCHAIN)/lib/crt1.o

CFILES 		:= $(wildcard $(SDIR)/*.c)
CPPFILES 	:= $(wildcard $(SDIR)/*.cpp)
OBJS 		:= $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(CFILES)) $(patsubst $(SDIR)/%.cpp, $(ODIR)/%.o, $(CPPFILES))

TARGET = eboot.bin

# Make rules
$(TARGET): $(ODIR) $(OBJS)
	$(LD) $(ODIR)/*.o -o $(ODIR)/$(PROJDIR).elf $(LFLAGS)
	$(TOOLCHAIN)/bin/linux/create-eboot -in=$(ODIR)/$(PROJDIR).elf -out=$(ODIR)/$(PROJDIR).oelf --paid 0x3800000000000011

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $< 

$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<

$(ODIR):
	@mkdir $@

.PHONY: clean

clean:
	rm -f $(TARGET) $(ODIR)/*.o
