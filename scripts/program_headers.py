# Script: ./dynamic_entries [input file (elf)]
# -
# Takes the given input ELF and gives you a list of entries from the dynamic table.

#!/usr/bin/python3

import argparse
import struct
import os
from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser(description="Takes the given input ELF and gives you a list of entries from the dynamic table.")
parser.add_argument("infile", help="Input ELF file path", type=str)

args = parser.parse_args()

# Sony program header types
ENUM_PT = dict(
    PT_SCE_RELA         = 0x60000000,  # SCE-specific RELA entries
    PT_SCE_DYNLIBDATA   = 0x61000000,  # SCE-specific dynamic linking data
    PT_SCE_PROC_PARAM   = 0x61000001,  # SCE-specific process parameters
    PT_SCE_MODULE_PARAM = 0x61000002,  # SCE-specific module parameters
    PT_SCE_RELRO        = 0x61000010,  # SCE-specific relro data (currently unused)
    PT_SCE_COMMENT      = 0x6FFFFF00,  # SCE-specific comment
    PT_SCE_VERSION      = 0x6FFFFF01,  # SCE-specific version

    PT_GNU_EH_FRAME     = 0x6474E550,  # Not SCE-specific, but is rather for EH frames
)

# Program header flags
ENUM_PF = dict(
    PF_X    = 0x1, # Executable
    PF_W    = 0x2, # Writable
    PF_R    = 0x4, # Readable
)

with open(args.infile, "rb") as f:
    # Leverage PyElfTools for handling some of the parsing
    elf = ELFFile(f)

    headerIndex = 0

    print("Index\tType" + ("\t").expandtabs(21) + ("Offset\tVirtual Address\tPhysical Address\tFile Size\tMemory Size\tPermissions").expandtabs(25))

    # Find the dynamic segment
    for segment in elf.iter_segments():
        sectionType = segment.header.p_type
        permissions = ''

        if type(sectionType) is int:
            # Do a lookup against Sony types, and fallback on printing the hex version
            found = False
            for pt in ENUM_PT:
                if ENUM_PT[pt] == sectionType:
                    found = True
                    sectionType = pt

            if not found:
                sectionType = "0x" + str(hex(sectionType)[2:]).zfill(8)

        if segment.header.p_flags & ENUM_PF['PF_R']:
            permissions += "R"
        else:
            permissions += "-"

        if segment.header.p_flags & ENUM_PF['PF_W']:
            permissions += "W"
        else:
            permissions += "-"

        if segment.header.p_flags & ENUM_PF['PF_X']:
            permissions += "X"
        else:
            permissions += "-"

        #print("#" + str(headerIndex) + "\t" + hex(segment.header.p_offset))
        print("#" + str(headerIndex) + "\t" + (sectionType + "\t0x" + str(hex(segment.header.p_offset)[2:]).zfill(16) + "\t0x" + str(hex(segment.header.p_vaddr)[2:]).zfill(16) + "\t0x" + str(hex(segment.header.p_paddr)[2:]).zfill(16) + "\t0x" + str(hex(segment.header.p_filesz)[2:]).zfill(16) + "\t0x" + str(hex(segment.header.p_memsz)[2:]).zfill(16) + "\t" + permissions).expandtabs(25))
        headerIndex += 1
