TITLE      := Forking
VERSION    := 1.00
TITLE_ID   := BREW00005
CONTENT_ID := IV0000-$(TITLE_ID)_00-FORKING000000000
LIBS       := -lkernel -lc -lSceLibcInternal -lSceSysUtil
PKG_FILES  := sce_sys/icon0.png sce_sys/param.sfo \
              sce_module/libc.prx sce_module/libSceFios2.prx \
              eboot.bin


ifndef OO_PS4_TOOLCHAIN
    $(error OO_PS4_TOOLCHAIN is undefined)
endif

CC := clang
LD := ld.lld

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    PATH := $(PATH):$(OO_PS4_TOOLCHAIN)/bin/linux
endif
ifeq ($(UNAME_S),Darwin)
    PATH := $(PATH):$(OO_PS4_TOOLCHAIN)/bin/macos
endif


CFLAGS   := -target x86_64-scei-ps4-elf -funwind-tables -fuse-init-array \
            -isysroot $(OO_PS4_TOOLCHAIN) -isystem $(OO_PS4_TOOLCHAIN)/include

LDFLAGS  := -m elf_x86_64 -pie --script $(OO_PS4_TOOLCHAIN)/link.x \
            --eh-frame-hdr -L$(OO_PS4_TOOLCHAIN)/lib $(OO_PS4_TOOLCHAIN)/lib/crt1.o


all: $(CONTENT_ID).pkg


$(CONTENT_ID).pkg: $(CONTENT_ID).gp4
	PkgTool.Core pkg_build $< .


$(CONTENT_ID).gp4: $(PKG_FILES)
	create-gp4 -content-id=$(CONTENT_ID) -files='$^' -out=$@


sce_sys/param.sfo: Makefile
	PkgTool.Core sfo_new $@
	PkgTool.Core sfo_setentry $@ APP_TYPE --type Integer --maxsize 4 --value 1
	PkgTool.Core sfo_setentry $@ APP_VER --type Utf8 --maxsize 8 --value '$(VERSION)'
	PkgTool.Core sfo_setentry $@ ATTRIBUTE --type Integer --maxsize 4 --value 0
	PkgTool.Core sfo_setentry $@ CATEGORY --type Utf8 --maxsize 4 --value 'gd'
	PkgTool.Core sfo_setentry $@ CONTENT_ID --type Utf8 --maxsize 48 --value '$(CONTENT_ID)'
	PkgTool.Core sfo_setentry $@ DOWNLOAD_DATA_SIZE --type Integer --maxsize 4 --value 0
	PkgTool.Core sfo_setentry $@ SYSTEM_VER --type Integer --maxsize 4 --value 0
	PkgTool.Core sfo_setentry $@ TITLE --type Utf8 --maxsize 128 --value '$(TITLE)'
	PkgTool.Core sfo_setentry $@ TITLE_ID --type Utf8 --maxsize 12 --value '$(TITLE_ID)'
	PkgTool.Core sfo_setentry $@ VERSION --type Utf8 --maxsize 8 --value '$(VERSION)'


sce_sys/icon0.png: sce_sys Makefile
	convert -size 512x512 -gravity center label:'$(TITLE)' $@


sce_sys:
	mkdir $@


sce_module:
	mkdir sce_module


sce_module/%.prx: sce_module
	cp $(OO_PS4_TOOLCHAIN)/bin/data/modules/$(@F) $@


eboot.bin: eboot.elf
	create-eboot -in=$< -out=eboot.oelf


eboot.elf: main.o mira.o
	$(LD) $(LDFLAGS) $(LIBS) -o $@ $^


%.c.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<


clean:
	rm -f eboot.elf eboot.oelf $(PKG_FILES) $(CONTENT_ID).gp4 \
              $(CONTENT_ID).pkg main.o mira.o
	rmdir sce_sys sce_module
