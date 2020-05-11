# Script: ./rela_entries [input file (elf)]
# -
# Takes the given input ELF and gives you a list of entries from the dynamic table.

#!/usr/bin/python3

import argparse
import struct
import sys
from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser(description="Takes the given input ELF and gives you a list of rela entries.")
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

ENUM_RELA_TYPES = dict(
    R_AMD64_NONE        = 0x00000000,
    R_AMD64_64          = 0x00000001,
    R_AMD64_PC32        = 0x00000002,
    R_AMD64_GOT32       = 0x00000003,
    R_AMD64_PLT32       = 0x00000004,
    R_AMD64_COPY        = 0x00000005,
    R_AMD64_GLOB_DAT    = 0x00000006,
    R_AMD64_JUMP_SLOT   = 0x00000007,
    R_AMD64_RELATIVE    = 0x00000008,
    R_AMD64_GOTPCREL    = 0x00000009,
    R_AMD64_32          = 0x0000000A,
    R_AMD64_32S         = 0x0000000B,
    R_AMD64_16          = 0x0000000C,
    R_AMD64_PC16        = 0x0000000D,
    R_AMD64_8           = 0x0000000E,
    R_AMD64_PC8         = 0x0000000F,
    R_AMD64_DTPMOD64    = 0x00000010,
    R_AMD64_DTPOFF64    = 0x00000011,
    R_AMD64_TPOFF64     = 0x00000012,
    R_AMD64_TLSGD       = 0x00000013,
    R_AMD64_TLSLD       = 0x00000014,
    R_AMD64_DTPOFF32    = 0x00000015,
    R_AMD64_GOTTPOFF    = 0x00000016,
    R_AMD64_TPOFF32     = 0x00000017,
    R_AMD64_PC64        = 0x00000018,
    R_AMD64_GOTOFF64    = 0x00000019,
    R_AMD64_GOTPC32     = 0x0000001A,
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
    addrOfRelaTable = dynlibDataPH.p_offset

    # We can find the RELA table by using the dynamic table. The RELA table starts with jump slots then
    # relative relocations. We'll use the DT_SCE_JMPREL tag and DT_SCE_PLTRELSZ + DT_SCE_RELASZ to get
    # the size of the table / number of entries.
    sizeOfTable = 0

    for i in range(0, numEntries):
        f.seek(dynamicPH.p_offset + (i * struct.calcsize('<QQ')))
        d_tag, d_val = struct.unpack('<QQ', f.read(struct.calcsize('<QQ')))

        if d_tag == DT_SCE_JMPREL:
            addrOfRelaTable += d_val

        if d_tag == DT_SCE_PLTRELSZ:
            sizeOfTable += d_val

        if d_tag == DT_SCE_RELASZ:
            sizeOfTable += d_val

    numRelaEntries = int(sizeOfTable / struct.calcsize('<QLLq'))

    print("[*] Found RELA Table 0x" + str(hex(addrOfRelaTable)[2:]).zfill(8))
    print("[*] Found a total of " + str(numRelaEntries) + " entries...")

    for i in range(0, numRelaEntries):
        f.seek(addrOfRelaTable + (i * struct.calcsize('<QLLq')))
        r_offset, r_info, r_sym, r_addend = struct.unpack('<QLLq', f.read(struct.calcsize('<QLLq')))

        for relaType in ENUM_RELA_TYPES:
            if ENUM_RELA_TYPES[relaType] == r_info:
                r_info = relaType

        if type(r_info) is int:
            r_info = "0x" + str(hex(r_info)[2:]).zfill(8)

        print(("[+] Type: " + r_info +
            "\t @ offset 0x" + str(hex(r_offset)[2:]).zfill(16) +
            " (addend: 0x" + str(hex(r_addend)[2:]).zfill(16) + ")" +
            " (symbol: 0x" + str(hex(r_sym)[2:]).zfill(8) + ")").expandtabs(10))

        i += 1
