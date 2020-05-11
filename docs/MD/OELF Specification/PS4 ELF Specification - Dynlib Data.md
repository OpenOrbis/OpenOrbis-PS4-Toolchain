# PS4 ELF Specification - Dynlib Data

## Summary

The `PT_SCE_DYNLIBDATA` segment contains many tables that are necessary for both the initial loading of the ELF as well as dynamic linking at run-time. Due to how important this segment is as well as how much is in it, it has been given it's own file. As an overview, the segment contains the following sections.

- Fingerprint
- String table
- Symbol table
- Jump table
- Relocation table
- Hash table
- Dynamic table

Below the summary, each section is explained in more detail.



## Fingerprint

The fingerprint is a 24 byte (0x18) size buffer that contains a unique identifier for the given app. How exactly this is generated isn't known, however it is not necessary to have a valid fingerprint. While an invalid fingerprint will cause a warning to be printed to the kernel log, the ELF will still load and run.

## String Table

### Library + Module Table

The library and module tables contain library and module names that will be required by the linker during run-time. Two library and module entries are absolutely necessary for every application, these being `libkernel.prx` (module: `libkernel`), and `libc.prx` (`libc`). Below is an example of a library and module table in memory assuming the executable only uses these two libraries:

(note: the actual table starts at `.sce_dynlib_data+0x18`)

```
.sce_dynlib_data+0x10:    ?? ?? ?? ?? ?? ?? ?? ?? 00 6C 69 62 6B 65 72 6E    ????????.libkern
.sce_dynlib_data+0x20:    65 6C 2E 70 72 78 00 6C 69 62 63 2E 70 72 78 00    el.prx.libc.prx.
.sce_dynlib_data+0x30:    6C 69 62 6B 65 72 6E 65 6C 00 6C 69 62 63 00 75    libkernel.libc.?
```

### Project Meta Data

The project meta data buffer contains the filename and the project name respectively as null terminated strings. The toolchain currently just uses the input filename without the `.elf` extension for the project name. Below is an example of the project meta data buffer assuming the input filename is "usleep", which is taken from the usleep sample project.

(note: the actual meta data starts at `.sce_dynlib_data+0x3E`)

```
.sce_dynlib_data+0x30:    ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? 75    ???????????????u
.sce_dynlib_data+0x40:    73 6C 65 65 70 2E 65 6C 66 00 75 73 6C 65 65 70    sleep.elf.usleep
.sce_dynlib_data+0x50:    00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ??    .???????????????
```

### NID Table

The NID (Name Identifier) table contains a list of NID hash strings for all the external symbols used by the application, with a library and module index appended as an encoded character. It is believed the primary purpose of using NIDs was to obfuscate symbol names, though as demonstrated this didn't work out too well for them.

Calculating NID hashes is a fairly trivial task as some work has already been done to reverse the hashing algorithm. Essentially, the plaintext symbol name is taken and a hardcoded suffix (in the tool, defined as `nidSuffixKey`) is appended on the end of it. This concatenated string is then hashed with SHA1, and the first 8 bytes are base64 encoded. Below is a snippet of the function that calculates NIDs for the elf-to-oelf converter tool (golang) to demonstrate:

```golang
func calculateNID(symbolName string) string {
	hashBytes := make([]byte, 8)
	suffix, _ := hex.DecodeString(nidSuffixKey)

	symbol := append([]byte(symbolName), suffix...)
	hash := sha1.Sum(symbol)

	// The order of the bytes has to be reversed. We can hack big endian to do this.
	binary.LittleEndian.PutUint64(hashBytes, binary.BigEndian.Uint64(hash[:8]))

	// The final NID is the hash bytes base64'd with the last '=' character removed
	nidHash := base64.StdEncoding.EncodeToString(hashBytes)
	nidHash = nidHash[0 : len(nidHash)-1]

	//  We also need to replace all forward slashes with dashes for encoding reasons
	nidHash = strings.Replace(nidHash, "/", "-", -1)

	return nidHash
}
```

All entries in the NID table are 0x10 (16) bytes long, and have the following format

```
[12 byte symbol hash] + "#" + [library ID encoded] + "#" + [module ID encoded]
```

The library ID and module ID are indexes into a table that's also in the `.sce_dynlib_data` segment just above the NID table.

The indexes into the library list start at index 0, and the indexes  into the module list start at index 1. Most of the time, the library  list and module list are in the same order, so the module ID is usually  the library ID + 1. This is not always the case however because some  modules contain more than one library.

The indexes are encoded into characters using the following encoding character set:

```
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-
```

Below is an example of the NID table from the usleep example project.

```
.sce_dynlib_data+0x50:    ?? 68 63 75 51 67 44 35 33 55 78 4D 23 42 23 43    ?hcuQgD53UxM#B#C 
.sce_dynlib_data+0x60:    00 31 6A 66 58 4C 52 56 7A 69 73 63 23 41 23 42    .1jfXLRVzisc#A#B 
.sce_dynlib_data+0x70:    00 58 4B 52 65 67 73 46 70 45 70 6B 23 42 23 43    .XKRegsFpEpk#B#C 
.sce_dynlib_data+0x80:    00 75 4D 65 69 31 57 39 75 79 4E 6F 23 42 23 43    .uMei1W9uyNo#B#C 
.sce_dynlib_data+0x90:    00 62 7A 51 45 78 79 31 38 39 5A 49 23 42 23 43    .bzQExy189ZI#B#C 
.sce_dynlib_data+0xA0:    00 38 47 32 4C 42 2B 41 33 72 7A 67 23 42 23 43    .8G2LB+A3rzg#B#C 
.sce_dynlib_data+0xB0:    00 50 33 33 30 50 33 64 46 46 36 38 23 42 23 43    .P330P3dFF68#B#C
.sce_dynlib_data+0xC0:    00 ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ?? ??    .???????????????
```

The plaintext of these symbols in the same order are:

1. `printf()` from libc
2. `sceKernelUsleep()` from libkernel
3. `catchReturnFromMain()` from libc
4. `exit()` from libc
5. `_init_env()` from libc
6. `atexit()` from libc
7. `sce_needLibc` from libc



## Symbol Table

In structure, the symbol table is similar to that of normal ELFs. The following entries are common amongst all applications, and can be found in the symbol table along with entries for dynamic symbols.

- Type: `STT_NOTYPE`. Info: NULL.
- Type: `STT_SECTION`. Info: NULL.
- Type: `STB_GLOBAL | STT_OBJECT`. Info: Index of `need_sceLibc` NID in the string table.



## Jump Table

The jump table contains relocation entries specific to the Procedure Linkage Table (PLT) / Global Offset Table (GOT). These entries are copied from the input ELF, and are of type `R_AMD64_JUMP_SLOT`.



## Relocation Table

The relocation table contains relocation entries that are not related to jump slots. The entries common amongst PS4 ELFs are listed below.

- Type: `R_AMD64_RELATIVE`. Relocation: `_sceLibcParam->sceLibcMallocReplace`
- Type: `R_AMD64_RELATIVE`. Relocation: `_sceLibcParam->sceLibcNewReplace`
- Type: `R_AMD64_64`. Relocation: `_sceLibcParam->Need_sceLibc`
- Type: `R_AMD64_RELATIVE`. Relocation: `_sceLibcParam->sceLibcMallocReplaceForTls`
- Type: `R_AMD64_RELATIVE`. Relocation: `.sce_process_param->sceLibcParam`
- Type: `R_AMD64_RELATIVE`. Relocation: `.sce_process_param->sceKernelMemParam`
- Type: `R_AMD64_RELATIVE`. Relocation: `.sce_process_param->sceKernelFsParam`
- Type: `R_AMD64_64`. Relocation: `.data->Need_sceLibc0`



## Hash Table

The hash table consists of buckets and chains to make accessing the symbol table quicker. Since the exact method used to calculate which symbols end up in which buckets, the converter just uses one bucket and every symbol is put into one chain. Each symbol entry must have an entry in the hash table, or the dynamic linker will fail when trying to resolve dynamic symbols.

The first 32-bit (DWORD) contains the number of buckets, and the second 32-bit (DWORD) contains the number of symbols in a chain.

```c
struct Sce_Hash_Table {
    uint32_t nbucket;
    uint32_t nchain;
}
```

`nbucket` will currently always be 1, and `nchain` will match the number of symbols. After this structure are the chain entries, each entry is 32-bits wide. The chain will always end with a NULL entry. For example, the usleep project has 9 total symbols, so the hash table would look like this:

```
.sce_dynlib_data+0x2F0    01 00 00 00 09 00 00 00 01 00 00 00 02 00 00 00    ................ 
.sce_dynlib_data+0x300    03 00 00 00 04 00 00 00 05 00 00 00 06 00 00 00    ................ 
.sce_dynlib_data+0x310    07 00 00 00 08 00 00 00 00 00 00 00 ?? ?? ?? ??    ............????

```



## Dynamic Table

The dynamic table links everything together, and is used heavily by the ELF loader. It contains information such as which libraries need to be loaded, where all the tables are in the segment, the size of the tables, and other miscellaneous info the loader needs. Below is a list of the required tags for a working ELF (copied from PS4 ELF Specification).

- `DT_SCE_HASH`: Offset of the hash table. Similar to ELF hash tables, just has a custom tag.
- `DT_SCE_HASHSZ`: Size of the hash table.
- `DT_SCE_STRTAB`: Offset of the string table. More information can be found in Dynlib Data MD.
- `DT_SCE_STRSZ`: Size of the string table.
- `DT_SCE_SYMTAB`: Offset of the symbol table. More information can be found in Dynlib Data MD.
- `DT_SCE_SYMTABSZ`: Size of the symbol table.
- `DT_SCE_SYMENT`: The size of symbol table entries. This will always be 0x18.
- `DT_SCE_RELA`: Offset of the relocation table. More information can be found in Dynlib Data MD.
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