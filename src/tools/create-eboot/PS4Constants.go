// This file contains constants that are specific to SCE types. This includes ELF types, program header types, and
// dynamic table tags.

package main

// SCE-specific ELF types
const ET_SCE_EXEC_ASLR = 0xFE10
const ET_SCE_DYNAMIC = 0xFE18

const PT_GNU_EH_FRAME = 0x6474E550

// SCE-specific program header types
const PT_SCE_DYNLIBDATA = 0x61000000   // Dynamic Linking Data
const PT_SCE_PROC_PARAM = 0x61000001   // Process Parameters
const PT_SCE_MODULE_PARAM = 0x61000002 // Module Parameters
const PT_SCE_RELRO = 0x61000010        // Read-Only Reallocation Data

// SCE-specific dynamic table tags
const DT_SCE_FINGERPRINT = 0x61000007     // Fingerprint data. Not important for homebrew.
const DT_SCE_FILENAME = 0x61000009        // Original filename
const DT_SCE_EXPORT_MODULE = 0x6100000D   // Module exports
const DT_SCE_IMPORT_MODULE = 0x6100000F   // Module imports
const DT_SCE_MODULE_ATTR = 0x61000011     // Module attributes
const DT_SCE_EXPORT_LIB = 0x61000013      // Library exports
const DT_SCE_IMPORT_LIB = 0x61000015      // Library imports
const DT_SCE_EXPORT_LIB_ATTR = 0x61000017 // Library attributes
const DT_SCE_IMPORT_LIB_ATTR = 0x61000019 // Library attributes
//const DT_SCE_STUB_MODULE_NAME = 0x6100001D  // Module name for the associated stub
//const DT_SCE_STUB_MODULE_VER = 0x6100001F   // Module version for the associated stub
//const DT_SCE_STUB_LIBRARY_NAME = 0x61000021 // ???
//const DT_SCE_STUB_LIBRARY_VER = 0x61000023  // ???
const DT_SCE_HASH = 0x61000025     // Symbol hash table (NID's?)
const DT_SCE_PLTGOT = 0x61000027   // Address associated with the SCE linkage table
const DT_SCE_JMPREL = 0x61000029   // Address of relocations associated with SCE PLT
const DT_SCE_PLTREL = 0x6100002b   // Type of relocation entry used for linking (SCE)
const DT_SCE_PLTRELSZ = 0x6100002d // Size of relocation entries in SCE PLT
const DT_SCE_RELA = 0x6100002f     // Address of SCE relocation table
const DT_SCE_RELASZ = 0x61000031   // Size of SCE Rela relocation table
const DT_SCE_RELAENT = 0x61000033  // Size of SCE Rela relocation table entries
const DT_SCE_STRTAB = 0x61000035   // Address of SCE dynamic string table
const DT_SCE_STRSZ = 0x61000037    // Total size of SCE dynamic string table
const DT_SCE_SYMTAB = 0x61000039   // Address of SCE dynamic symbol table
const DT_SCE_SYMENT = 0x6100003b   // Total size of SCE dynamic symbol table entry
const DT_SCE_HASHSZ = 0x6100003d   // Total size of SCE symbol hash table (NID's?)
const DT_SCE_SYMTABSZ = 0x6100003f // Total size of SCE dynamic symbol table

const R_AMD64_64 = 0x00000001

type SceHashTable struct {
	nbucket uint32
	nchain  uint32
}
