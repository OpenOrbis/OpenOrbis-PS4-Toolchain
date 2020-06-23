#  Sysmodule library
The sysmodule library is used for loading and unloading system modules tied to static identifiers. For a list of these identifiers, see the [psdevwiki page](https://www.psdevwiki.com/ps4/Libraries#Sysmodule_libraries).

### Known Functions

**sceSysmoduleIsLoaded(id)**

```c
int sceSysmoduleIsLoaded(uint16_t id)
```

Checks if the given `id` is already loaded. Returns 0 if this is the case, non-zero otherwise.

**sceSysmoduleLoadModule(id)**

```c
int sceSysmoduleLoadModule(uint16_t id)
```

Attempts to load the module at `id`. Returns 0 if it could be loaded, non-zero on failure.

**sceSysmoduleUnloadModule(id)**

```c
int sceSysmoduleUnloadModule(uint16_t id)
```

Attempts to unload the module at `id`. Returns 0 if it could be unloaded, non-zero on failure.

### Reversing Credits
- CTurt
- VitaSDK developers
