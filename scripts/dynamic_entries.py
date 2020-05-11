# Script: ./dynamic_entries [input file (elf)]
# -
# Takes the given input ELF and gives you a list of entries from the dynamic table.

#!/usr/bin/python3

import argparse
import struct
import sys

from elftools.elf.elffile import ELFFile

parser = argparse.ArgumentParser(description="Takes the given input ELF and gives you a list of entries from the dynamic table.")
parser.add_argument("infile", help="Input ELF file path", type=str)

args = parser.parse_args()

# Sony program header types
PT_SCE_DYNLIBDATA   = 0x61000000  # SCE-specific dynamic linking data
PT_SCE_PROC_PARAM   = 0x61000001  # SCE-specific process parameters
PT_SCE_MODULE_PARAM = 0x61000002  # SCE-specific module parameters
PT_SCE_RELRO        = 0x61000010  # SCE-specific relro data (currently unused)
PT_SCE_COMMENT      = 0x6FFFFF00  # SCE-specific comment
PT_SCE_VERSION      = 0x6FFFFF01  # SCE-specific version

ENUM_TAGS = dict(
    DT_NULL             = 0x00000000,   # End of dynamic array
    DT_NEEDED           = 0x00000001,   # String table offset of needed library
    DT_PLTRELSZ         = 0x00000002,   # Size of relocation entries in the Procedure Linkage Table (PLT)
    DT_PLTGOT           = 0x00000003,   # Address associated with the linkage table
    DT_HASH             = 0x00000004,   # Address associated with the symbol hash table
    DT_STRTAB           = 0x00000005,   # Address associated with the dynamic string table
    DT_SYMTAB           = 0x00000006,   # Address associated with the dynamic symbol table
    DT_RELA             = 0x00000007,   # Address of relocation table
    DT_RELASZ           = 0x00000008,   # Size of Rela relocation table
    DT_RELAENT          = 0x00000009,   # Size of a Rela relocation entry
    DT_STRSZ            = 0x0000000A,   # Total size of the string table
    DT_SYMENT           = 0x0000000B,   # Size of a symbol table entry
    DT_INIT             = 0x0000000C,   # Address of initialization function
    DT_FINI             = 0x0000000D,   # Address of termination function
    DT_SONAME           = 0x0000000E,   # String table offset of a shared objects name
    DT_RPATH            = 0x0000000F,   # String table offset of library search path
    DT_SYMBOLIC         = 0x00000010,   # Changes symbol resolution algorithm
    DT_REL              = 0x00000011,   # Address of relocation table (Rel entries)
    DT_RELSZ            = 0x00000012,   # Size of Rel relocation table
    DT_RELENT           = 0x00000013,   # Size of a Rel relocation entry
    DT_PLTREL           = 0x00000014,   # Type of relocation entry used for linking
    DT_DEBUG            = 0x00000015,   # Reserved for debugger
    DT_TEXTREL          = 0x00000016,   # Relocations exist for non-writable segments
    DT_JMPREL           = 0x00000017,   # Address of relocations associated with PLT
    DT_BIND_NOW         = 0x00000018,   # Process all relocations before execution
    DT_INIT_ARRAY       = 0x00000019,   # Pointer to array of initialization functions
    DT_FINI_ARRAY       = 0x0000001A,   # Pointer to array of termination functions
    DT_INIT_ARRAYSZ     = 0x0000001B,   # Size of DT_INIT_ARRAY
    DT_FINI_ARRAYSZ     = 0x0000001C,   # Size of DT_FINI_ARRAY
    DT_RUNPATH          = 0x0000001D,   # String table offset of lib search path
    DT_FLAGS            = 0x0000001E,   # Flags

    DT_PREINIT_ARRAY    = 0x00000020,   # Pointer to array of preinit functions
    DT_PREINIT_ARRAYSZ  = 0x00000021,   # Size of the DT_PREINIT_ARRAY array

    DT_LOOS             = 0x60000000,   # Start of environment specific tags
    DT_HIOS             = 0x6FFFFFFF,   # End of environment specific tags
    DT_LOPROC           = 0x70000000,   # Start of processor specific tags
    DT_HIPROC           = 0x7FFFFFFF,   # End of processor specific tags

    # PS4 tags
    DT_SCE_FINGERPRINT       = 0x61000007,  # Fingerprint data. Not important for homebrew.
    DT_SCE_FILENAME          = 0x61000009,  # Original filename
    DT_SCE_MODULE_INFO       = 0x6100000D,  # Module information
    DT_SCE_NEEDED_MODULE     = 0x6100000F,  # Needed module
    DT_SCE_MODULE_ATTR       = 0x61000011,  # Module attributes
    DT_SCE_EXPORT_LIB        = 0x61000013,  # Library exports
    DT_SCE_IMPORT_LIB        = 0x61000015,  # Library imports
    DT_SCE_EXPORT_LIB_ATTR   = 0x61000017,  # Library attributes
    DT_SCE_IMPORT_LIB_ATTR   = 0x61000019,  # Library attributes
    DT_SCE_STUB_MODULE_NAME  = 0x6100001D,  # Module name for the associated stub
    DT_SCE_STUB_MODULE_VER   = 0x6100001F,  # Module version for the associated stub
    DT_SCE_STUB_LIBRARY_NAME = 0x61000021,  # ???
    DT_SCE_STUB_LIBRARY_VER  = 0x61000023,  # ???
    DT_SCE_HASH              = 0x61000025,  # Symbol hash table (NID's?)
    DT_SCE_PLTGOT            = 0x61000027,  # Address associated with the SCE linkage table
    DT_SCE_JMPREL            = 0x61000029,  # Address of relocations associated with SCE PLT
    DT_SCE_PLTREL            = 0x6100002b,  # Type of relocation entry used for linking (SCE)
    DT_SCE_PLTRELSZ          = 0x6100002d,  # Size of relocation entries in SCE PLT
    DT_SCE_RELA              = 0x6100002f,  # Address of SCE relocation table
    DT_SCE_RELASZ            = 0x61000031,  # Size of SCE Rela relocation table
    DT_SCE_RELAENT           = 0x61000033,  # Size of SCE Rela relocation table entries
    DT_SCE_STRTAB            = 0x61000035,  # Address of SCE dynamic string table
    DT_SCE_STRSZ             = 0x61000037,  # Total size of SCE dynamic string table
    DT_SCE_SYMTAB            = 0x61000039,  # Address of SCE dynamic symbol table
    DT_SCE_SYMENT            = 0x6100003b,  # Total size of SCE dynamic symbol table entry
    DT_SCE_HASHSZ            = 0x6100003d,  # Total size of SCE symbol hash table (NID's?)
    DT_SCE_SYMTABSZ          = 0x6100003f,  # Total size of SCE dynamic symbol table
)

with open(args.infile, "rb") as f:
    # Leverage PyElfTools for handling some of the parsing
    elf = ELFFile(f)

    dynamicPH = None

    # Find the dynamic segment
    for segment in elf.iter_segments():
        if segment.header.p_type == 'PT_DYNAMIC':
            dynamicPH = segment.header

    if dynamicPH == None:
        print("An error occurred, as the ELF is not a valid OELF!")
        sys.exit(1)

    # We can get the number of entries by dividing the segment size by an entry size
    numEntries = int(dynamicPH.p_filesz / struct.calcsize('<QQ'))

    print("[*] Found dynamic table at 0x" + str(hex(dynamicPH.p_offset)[2:]).zfill(8))
    print("[*] Found a total of " + str(numEntries) + " entries...")

    for i in range(0, numEntries):
        f.seek(dynamicPH.p_offset + (i * struct.calcsize('<QQ')))
        d_tag, d_val = struct.unpack('<QQ', f.read(struct.calcsize('<QQ')))

        for tag in ENUM_TAGS:
            if ENUM_TAGS[tag] == d_tag:
                d_tag = tag

        if type(d_tag) is int:
            d_tag = "0x" + str(hex(d_tag)[2:]).zfill(8)

        print(("[+] Tag: " + d_tag + "\t= 0x" + str(hex(d_val)[2:]).zfill(16)).expandtabs(40))
