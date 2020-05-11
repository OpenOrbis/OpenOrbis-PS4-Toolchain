# PS4 ELF Specification

## Summary
The PS4 uses a modified Executable and Linkable Format (ELF) for games and applications. This document will outline the specifications of the PS4 ELF format. This file focuses on segments contained in PS4 ELFs. More information is available on the *PS4 ELF Specification - Dynlib Data* page, as this is a massive segment that is exclusive to the PS4 and is essential for dynamic linking. This file contains more general / surface level information on the other segments.

## ELF Header
The following fields in the ELF header are different in PS4 ELFs from normal ELFs.

### Identifier
- `E_IDENT[EI_OSABI]` is set to ` FreeBSD` / 0x9
- ` E_TYPE` is set to `ET_SCE_EXEC_ASLR`



## Segments
PS4 ELFs use a mixture of program headers that are common in all ELFs as well as ones that are specific to the PS4. There are other PS4-unique program header types that games/apps have that are built from the official Sony SDK which are not used by the custom toolchain, most notably `PT_SCE_COMMENT` and `PT_SCE_VERSION`. Since these headers / segments are not used in the custom toolchain, there is currently no other information on them in this documentation, as they're not essential.

Program headers typically follow a set order in PS4 applications. The program headers necessary for all PS4 ELFs, their order, as well as the contents of each segment are detailed as follows.

### PT_LOAD (.text)
| Identifier                | Permissions (RWX) | Alignment |
| ------------------------- | ----------------- | --------- |
| PT_LOAD                   | R-X               | 0x4000    |

The first program header is always a `PT_LOAD` header. Within this segment is the `.text` section as well as `.plt`, `.rodata`, `.eh_frame`, and `.eh_frame_hdr`. It's usually at file offset 0x4000 and address 0x0.

### PT_SCE_RELRO (.data.rel.ro)
| Identifier   | Permissions (RWX) | Alignment |
| ------------ | ----------------- | --------- |
| PT_SCE_RELRO | R--               | 0x4000    |

The `PT_SCE_RELRO` segment contains `.data.rel.ro`, as well as Global Offset Table (GOT) `.got.plt`. For more on what is typically linked in to `.data.rel.ro` from the C Run-Time (CRT) stubs, see the Read-Only Relocations section.

### PT_LOAD (.data)
| Identifier | Permissions (RWX) | Alignment |
| ---------- | ----------------- | --------- |
| PT_LOAD    | RW-               | 0x4000    |

The third program header is another `PT_LOAD` header, but for `.data` instead of `.text`. This section not only contains `.data`, but `.sce_process_param` as well, which will precede `.data`. More information on `.sce_process_param` is provided in the description for the `PT_SCE_PROC_PARAM` program header.

### PT_SCE_PROC_PARAM (.sce_process_param)
| Identifier        | Permissions (RWX) | Alignment |
| ----------------- | ----------------- | --------- |
| PT_SCE_PROC_PARAM | R--               | 0x8       |

The `.sce_process_param` segment contains a structure as defined below. Some of the data it holds includes meta-data information (SDK version, magic) as well as entries for SCE data structures in read-only relocations (relro). The structure  is defined as follows:

```c
struct Sce_Proc_Param {
        uint64_t p_size;  			// Size of segment

        union {
            uint32_t p_magic;		// Always 'ORBI'
            char p_magic_bytes[4] = {'O', 'R', 'B', 'I'};
        };

        uint32_t p_ent_count;		// Number of proc param entries
        uint32_t p_sdk_ver; 		// Eg. 4508101 (4.50.8101)
        uint64_t p_unknown[4]; 	    // 36 NULL bytes, unknown but usually not set anyway
    	
    	void *entries[p_ent_count];
};
```

Common entries include `sceLibcParam`, `sceKernelMemParam`, and `sceKernelFsParam`. The size of this structure in many cases is 0x50.

### PT_DYNAMIC (.dynamic)
| Identifier | Permissions (RWX) | Alignment |
| ---------- | ----------------- | --------- |
| PT_DYNAMIC | RW-               | 0x8       |

The dynamic table is similar in structure to normal ELF's, however Sony has defined their own dynamic tag types, which are very important for the PS4's dynamic linker. The following dynamic tags are (as far as we can tell), necessary for ELF's to load.

- `DT_SCE_HASH`: Offset of the hash table. Similar to ELF hash tables, just has a custom tag.
- `DT_SCE_HASHSZ`: Size of the hash table.
- `DT_SCE_STRTAB`: Offset of the string table. More information can be found on the *PS4 ELF Specification - Dynlib Data* page.
- `DT_SCE_STRSZ`: Size of the string table.
- `DT_SCE_SYMTAB`: Offset of the symbol table. More information can be found on the *PS4 ELF Specification - Dynlib Data* page.
- `DT_SCE_SYMTABSZ`: Size of the symbol table.
- `DT_SCE_SYMENT`: The size of symbol table entries. This will always be 0x18.
- `DT_SCE_RELA`: Offset of the relocation table. More information can be found on the *PS4 ELF Specification - Dynlib Data* page.
- `DT_SCE_RELASZ`: Size of the relocation table.
- `DT_SCE_RELAENT`: The size of relocation table entries. This will always be 0x18.
- `DT_SCE_PLTGOT`: Offset of the global offset table.
- `DT_SCE_PLTRELSZ`: Size of the global offset table.
- `DT_SCE_PLTREL`: The type of relocations in the relocation table. This should be set to `DT_RELA`.
- `DT_SCE_JMPREL`: Offset of the table containing jump slots.
- `DT_DEBUG`: Should be set to NULL.
- `DT_TEXTREL`: Should be set to NULL.
- `DT_FLAGS`: Should be set to `DF_TEXTREL`.

Additionally, `DT_NEEDED` tags are created for each dynamic library used by the application. The value is set to the offset of the library's name in the string table. Each `DT_NEEDED` tag should also have a corresponding `DT_SCE_IMPORT_LIB` and `DT_SCE_IMPORT_LIB_ATTR` tag.

- `DT_NEEDED`: Offset of the library string in the string table to be linked in.
- `DT_SCE_IMPORT_LIB`: The upper 32-bits should contain the module index multiplied by 0x10000 with 0x1 added. The lower 32-bits should contain the offset of the module string in the string table that corresponds to the library.
- `DT_SCE_IMPORT_LIB_ATTR`: The upper 32-bits should contain the module index multiplied by 0x10000. The lower 32-bits should be a constant 0x9.

Finally, there are some metadata related SCE-specific tags.

- `DT_SCE_FINGERPRINT`: Usually set to NULL, as it's usually at offset 0x0 in the string table.
- `DT_SCE_FILENAME`: Offset of the filename in the string table.
- `DT_SCE_MODULE_INFO`: The upper 32-bits should contain 0x101. The lower 32-bits should contain the offset of the project name in the string table.
- `DT_SCE_MODULE_ATTR`: Usually set to NULL.

### PT_INTERP (.interp)
| Identifier | Permissions (RWX) | Alignment |
| ---------- | ----------------- | --------- |
| PT_INTERP  | R--               | 0x1       |

The `.interp` section will usually overlap with `.text`. It's always 0x15 bytes in size, and contains the string `/libexec/ld-elf.so.1` padded to 0x15 with null bytes.

### PT_TLS 
| Identifier | Permissions (RWX) | Alignment |
| ---------- | ----------------- | --------- |
| PT_TLS     | R--               | 0x1       |

The TLS segment is empty, and points to 0x0. It's unknown if this program header is even needed, however the toolchain includes it because it's very easy to generate anyway.

### PT_GNU_EH_FRAME
| Identifier      | Permissions (RWX) | Alignment |
| --------------- | ----------------- | --------- |
| PT_GNU_EH_FRAME | R--               | 0x4       |

The `.eh_frame` and `.eh_frame_hdr` are copied over straight from the input ELF and are left untouched.

### PT_SCE_DYNLIBDATA
| Identifier        | Permissions (RWX) | Alignment |
| ----------------- | ----------------- | --------- |
| PT_SCE_DYNLIBDATA | R--               | 0x10      |

This segment is so important it has it's own documentation file that digs deeper into it. Here's a surface level overview of what this segment contains:

**Fingerprint (first 32 bytes)**

Unique identifier for the application. This can be set to anything, however if it's not set to a value the PS4 recognized, a warning is logged in the kernel log (/dev/klog), though execution will continue without being halted.

**String Table**

The string table contains the module list, meta-data info (filename, project name), and the NID hash table.

**Symbol Table**

The symbol table contains symbol entries for external symbols that are needed from libraries, as well as other miscellaneous entries that are explained in further detail in the separate documentation file.

**Relocation Table**

The relocation table contains relocation with addend (RELA) entries.

**Hash Table**

The hash table is very similar to those of standard ELFs. To keep things simple, output ELFs from the toolchain will have all the symbols in one hash chain. This may change in a future update.

**Dynamic Table**

The dynamic table links everything together and is referenced heavily by the ELF loader. The entries it contains are explained above in the `PT_DYNAMIC` section.



## PS4 unique ELF-related constants
### ELF Types
| Type                       | Value  |
| -------------------------- | ------ |
| ET_SCE_EXEC                | 0xFE00 |
| ET_SCE_EXEC_ASLR (default) | 0xFE10 |
| ET_SCE_DYNAMIC             | 0xFE18 |

### Program Header Types
| Type              | Value      |
| ----------------- | ---------- |
| PT_SCE_DYNLIBDATA | 0x61000000 |
| PT_SCE_PROC_PARAM | 0x61000001 |
| PT_SCE_RELRO      | 0x61000010 |

### Dynamic Header Tag Types
| Type                     | Value      |
| ------------------------ | ---------- |
| DT_SCE_FINGERPRINT       | 0x61000007 |
| DT_SCE_FILENAME          | 0x61000009 |
| DT_SCE_MODULE_INFO       | 0x6100000D |
| DT_SCE_NEEDED_MODULE     | 0x6100000F |
| DT_SCE_MODULE_ATTR       | 0x61000011 |
| DT_SCE_EXPORT_LIB        | 0x61000013 |
| DT_SCE_IMPORT_LIB        | 0x61000015 |
| DT_SCE_EXPORT_LIB_ATTR   | 0x61000017 |
| DT_SCE_IMPORT_LIB_ATTR   | 0x61000019 |
| DT_SCE_STUB_MODULE_NAME  | 0x6100001D |
| DT_SCE_STUB_MODULE_VER   | 0x6100001F |
| DT_SCE_STUB_LIBRARY_NAME | 0x61000021 |
| DT_SCE_STUB_LIBRARY_VER  | 0x61000023 |
| DT_SCE_HASH              | 0x61000025 |
| DT_SCE_PLTGOT            | 0x61000027 |
| DT_SCE_JMPREL            | 0x61000029 |
| DT_SCE_PLTREL            | 0x6100002B |
| DT_SCE_PLTRELSZ          | 0x6100002D |
| DT_SCE_RELA              | 0x6100002F |
| DT_SCE_RELASZ            | 0x61000031 |
| DT_SCE_RELAENT           | 0x61000033 |
| DT_SCE_STRTAB            | 0x61000035 |
| DT_SCE_STRSZ             | 0x61000037 |
| DT_SCE_SYMTAB            | 0x61000039 |
| DT_SCE_SYMENT            | 0x6100003B |
| DT_SCE_HASHSZ            | 0x6100003D |
| DT_SCE_SYMTABSZ          | 0x6100003F |