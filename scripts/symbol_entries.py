# Script: ./symbol_entries [input file (elf)]
# -
# Takes the given input ELF and gives you a list of entries from the symbol table.

#!/usr/bin/python3

import argparse
import struct
import sys
from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser(description="Takes the given input ELF and gives you a list of symbol entries.")
parser.add_argument("infile", help="Input ELF file path", type=str)

args = parser.parse_args()

# Sony program header types
PT_SCE_DYNLIBDATA   = 0x61000000  # SCE-specific dynamic linking data
PT_SCE_PROC_PARAM   = 0x61000001  # SCE-specific process parameters
PT_SCE_MODULE_PARAM = 0x61000002  # SCE-specific module parameters
PT_SCE_RELRO        = 0x61000010  # SCE-specific relro data (currently unused)
PT_SCE_COMMENT      = 0x6FFFFF00  # SCE-specific comment
PT_SCE_VERSION      = 0x6FFFFF01  # SCE-specific version

# Tag for SCE string table size
DT_SCE_JMPREL       = 0x61000029
DT_SCE_PLTRELSZ     = 0x6100002D
DT_SCE_RELASZ       = 0x61000031
DT_SCE_SYMTAB       = 0x61000039
DT_SCE_SYMENT       = 0x6100003B
DT_SCE_HASHSZ       = 0x6100003D
DT_SCE_SYMTABSZ     = 0x6100003F

ENUM_SYMTAB_BINDS = dict(
     STB_LOCAL          = 0x00000000,
     STB_GLOBAL         = 0x00000001,
     STB_WEAK           = 0x00000002,
)

ENUM_SYMTAB_TYPES = dict(
    STT_NOTYPE          = 0x00000000,
    STT_OBJECT          = 0x00000001,
    STT_FUNC            = 0x00000002,
    STT_SECTION         = 0x00000003,
    STT_FILE            = 0x00000004,
    STT_COMMON          = 0x00000005,
    STT_TLS             = 0x00000006,
)

with open(args.infile, "rb") as f:
    # Leverage PyElfTools for handling some of the parsing
    elf = ELFFile(f)

    dynamicPH = None
    dynlibDataPH = None

    # Find the dynamic segment
    for segment in elf.iter_segments():
        if segment.header.p_type == 'PT_DYNAMIC':
            dynamicPH = segment.header

        if segment.header.p_type == PT_SCE_DYNLIBDATA:
            dynlibDataPH = segment.header

    if dynamicPH == None:
        print("An error occurred, as the ELF is not a valid OELF!")
        sys.exit(1)

    # We can get the number of entries by dividing the segment size by an entry size
    numEntries      = int(dynamicPH.p_filesz / struct.calcsize('<QQ'))
    addrOfSymTable  = dynlibDataPH.p_offset

    # We can find the RELA table by using the dynamic table. The RELA table starts with jump slots then
    # relative relocations. We'll use the DT_SCE_JMPREL tag and DT_SCE_PLTRELSZ + DT_SCE_RELASZ to get
    # the size of the table / number of entries.
    sizeOfTable = 0

    for i in range(0, numEntries):
        f.seek(dynamicPH.p_offset + (i * struct.calcsize('<QQ')))
        d_tag, d_val = struct.unpack('<QQ', f.read(struct.calcsize('<QQ')))

        if d_tag == DT_SCE_SYMTAB:
            addrOfSymTable += d_val

        if d_tag == DT_SCE_SYMTABSZ:
            sizeOfTable += d_val

    numSymEntries = int(sizeOfTable / struct.calcsize('<IBBHQQ'))

    print("[*] Found Symbol Table 0x" + str(hex(addrOfSymTable)[2:]).zfill(8))
    print("[*] Found a total of " + str(numSymEntries) + " entries...")

    for i in range(0, numSymEntries):
        f.seek(addrOfSymTable + (i * struct.calcsize('<IBBHQQ')))
        st_name, st_info, st_other, st_shndx, st_value, st_size = struct.unpack('<IBBHQQ', f.read(struct.calcsize('<IBBHQQ')))
        
        st_bind = st_info >> 4
        st_type = st_info & 0xF

        for stb in ENUM_SYMTAB_BINDS:
            if ENUM_SYMTAB_BINDS[stb] == st_bind:
                st_bind = stb
                
        for stt in ENUM_SYMTAB_TYPES:
            if ENUM_SYMTAB_TYPES[stt] == st_type:
                st_type = stt

        if type(st_bind) is int:
            st_bind = "0x" + str(hex(st_bind)[2:]).zfill(8)
            
        if type(st_type) is int:
            st_type = "0x" + str(hex(st_type)[2:]).zfill(8)
            
        print(("[+] Type: " + st_type +
            " (Bind: " + st_bind + ")" + 
            "\t Name: 0x" + str(hex(st_name)[2:]).zfill(16)).expandtabs(10))

        i += 1
