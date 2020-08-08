# Libkernel library
Saying the libkernel library does a lot would be an understatement. It's one of the largest libraries on the system. Among many of the important things it contains is the following:

- System call wrappers for both BSD and Sony syscalls
- Event queue stuff
- Threading via Sony's wrapped "scePthread" API
- Userland dynamic linking / dlsym
- Direct memory allocation and mapping
- Scheduling and signals
- Thread synchronization / mutexes

While many of the function names are known, their prototypes have not been fully reversed. This document will only include known prototypes, and will grow over time.

### Known Macros
Kqueue filter types.

```c
#define ORBIS_KERNEL_EVFILT_TIMER    	EVFILT_TIMER
#define ORBIS_KERNEL_EVFILT_READ     	EVFILT_READ
#define ORBIS_KERNEL_EVFILT_WRITE    	EVFILT_WRITE
#define ORBIS_KERNEL_EVFILT_USER     	EVFILT_USER
#define ORBIS_KERNEL_EVFILT_FILE     	EVFILT_VNODE
#define ORBIS_KERNEL_EVFILT_GNM      	EVFILT_GRAPHICS_CORE
#define ORBIS_KERNEL_EVFILT_VIDEO_OUT	EVFILT_DISPLAY
#define ORBIS_KERNEL_EVFILT_HRTIMER 	EVFILT_HRTIMER
```

Knote attributes.

```c
#define ORBIS_KERNEL_EVNOTE_DELETE   NOTE_DELETE
#define ORBIS_KERNEL_EVNOTE_WRITE    NOTE_WRITE
#define ORBIS_KERNEL_EVNOTE_EXTEND   NOTE_EXTEND
#define ORBIS_KERNEL_EVNOTE_ATTRIB   NOTE_ATTRIB
#define ORBIS_KERNEL_EVNOTE_RENAME   NOTE_RENAME
#define ORBIS_KERNEL_EVNOTE_REVOKE   NOTE_REVOKE
```

Event flag types.

```c
#define ORBIS_KERNEL_EVFLAG_EOF       		EV_EOF
#define ORBIS_KERNEL_EVFLAG_ERROR     		EV_ERROR
#define ORBIS_KERNEL_EVF_ATTR_TH_FIFO   	0x01
#define ORBIS_KERNEL_EVF_ATTR_TH_PRIO   	0x02
#define ORBIS_KERNEL_EVF_ATTR_SINGLE    	0x10
#define ORBIS_KERNEL_EVF_ATTR_MULTI     	0x20
#define ORBIS_KERNEL_EVF_WAITMODE_AND       0x01
#define ORBIS_KERNEL_EVF_WAITMODE_OR        0x02
#define ORBIS_KERNEL_EVF_WAITMODE_CLEAR_ALL 0x10
#define ORBIS_KERNEL_EVF_WAITMODE_CLEAR_PAT 0x20
```

Semaphore attributes.

```c
#define ORBIS_KERNEL_SEMA_ATTR_TH_FIFO   0x01
#define ORBIS_KERNEL_SEMA_ATTR_TH_PRIO   0x02
```

Direct memory attributes.

```c
#define ORBIS_KERNEL_MAIN_DMEM_SIZE 0x180000000u
```

Memory types.

```c
#define ORBIS_KERNEL_WB_ONION  0x0
#define ORBIS_KERNEL_WC_GARLIC 0x3 // Garlic+?
#define ORBIS_KERNEL_WB_GARLIC 0xA
```

Memory protections.

```c
// CPU
#define ORBIS_KERNEL_PROT_CPU_READ  0x01
#define ORBIS_KERNEL_PROT_CPU_WRITE 0x02
#define ORBIS_KERNEL_PROT_CPU_RW    (ORBIS_KERNEL_PROT_CPU_READ | ORBIS_KERNEL_PROT_CPU_WRITE)
#define ORBIS_KERNEL_PROT_CPU_EXEC  0x04
#define ORBIS_KERNEL_PROT_CPU_ALL   (ORBIS_KERNEL_PROT_CPU_RW | ORBIS_KERNEL_PROT_CPU_EXEC)

// GPU
#define ORBIS_KERNEL_PROT_GPU_READ  0x10
#define ORBIS_KERNEL_PROT_GPU_WRITE 0x20
#define ORBIS_KERNEL_PROT_GPU_RW    (ORBIS_KERNEL_PROT_GPU_READ | ORBIS_KERNEL_PROT_GPU_WRITE)
#define ORBIS_KERNEL_PROT_GPU_ALL   ORBIS_KERNEL_PROT_GPU_RW
```

### Known Globals

Libkernel also contains globals, among which is heap settings for libc. ~~These are usually initialized by the CRT and are often used in homebrew because by default the PS4 heap is extremely limited (14mb or so cap).~~ This is no longer the case since MUSL has been ported; these globals are ignored.

**uint64_t sceLibcHeapSize**: Maximum heap size libc can use
**uint32_t sce_libc_heap_delayed_alloc**: Unknown?
**uint32_t sce_libc_extended_alloc**: Unknown?

### Known Structures

#### kevent
The kernel event entry structure for kqueues. Identical to FreeBSD kevent structures.

**uintptr_t ident**: Event identifier / tag
**short filter**: Filter type
**u_short flags**: Action flags for kqueue
**u_int fflags**: Filter flags
**intptr_t data**: Filter data
**void \*udata**: User data

#### OrbisKernelModuleSegmentInfo
The kernel module segment info structure contains information about a module segment, including it's virtual address, size, and protections.

**void \*addr**: Virtual address
**uint32_t size**: Size of the segment
**int32_t prot**: Protections (Read, Write, Execute bits)

#### OrbisKernelModuleInfo
The kernel module info structure contains information from the `.sce_module_param` segment of the Orbis ELF. This includes the name, segment information, and fingerprint.

**size_t size**: Size of the module
**char name[256]**: Name of the module
**OrbisKernelModuleSegmentInfo segmentInfo[4]**: Segment information array
**uint32_t segmentCount**: Number of segments
**char fingerprint[0x14]**: Module fingerprint

### Known Functions

**sceKernelCreateEqueue(\*OrbisKernelEqueue, name)**

```c
int sceKernelCreateEqueue(OrbisKernelEqueue *outEq, char *name)
```

Creates an event queue and assigns it the given `name`. Returns 0 on success, non-zero on failure.

**sceKernelWaitEqueue(OrbisKernelEqueue, event, num, \*out, usecs)**

```c
int sceKernelWaitEqueue(OrbisKernelEqueue eq, kevent *evt, int num, int *out, int usecs)
```

Waits on a given event queue `eq` for kevent `evt` and writes the result to `out`.

**sceKernelAddFileEvent(OrbisKernelEqueue, fd, watch, \*udata)

```c
int sceKernelAddFileEvent(OrbisKernelEqueue eq, int fd, int watch, void *udata)
```

Adds a file event to event queue `eq` for the given `fd`.

**sceKernelAllocateDirectMemory(searchStart, searchEnd, length, align, type, \*physicalAddrDest)**

```c
int sceKernelAllocateDirectMemory(off_t searchStart, off_t searchEnd, size_t length, size_t align, int type, off_t *physicalAddrDest)
```

Allocates direct memory between `searchStart` and `searchEnd` consisting of `length` bytes, aligned to `align` and given `type` page protections. The final physical address is then written to `physicalAddrDest` to later be mapped to virtual memory. Returns 0 on success, non-zero on failure.

**sceKernelMapDirectMemory(\*virtualAddrDest, length, protections, flags, off_t physicalAddr, align)

```c
int sceKernelMapDirectMemory(off_t *virtualAddrDest, size_t length, int protections, int flags, off_t physicalAddr, size_t align)
```

Maps `physicalAddr` of `length` bytes with `protections` protections into virtual memory with `align` alignment, and writes the final virtual address into `virtualAddrDest`. Returns 0 on success, non-zero on failure.

**sceKernelReleaseDirectMemory(physicalAddr, length)**

```c
int sceKernelReleaseDirectMemory(off_t physicalAddr, size_t length)
```

Releases physical memory previously allocated with `sceKernelAllocateDirectMemory` of `length` bytes.

**sceKernelGetDirectMemorySize()**

```c
int sceKernelGetDirectMemorySize()
```

Gets the amount of direct memory available for allocation and returns it.

**scePthreadCreate(\*OrbisPthread, \*pthread_attr_t, entry, args, name)**

```c
int scePthreadCreate(OrbisPthread *destThread, pthread_attr_t *attr, void *entry, void *args, char *name)
```

Creates an scePthread with `attr` attributes, `entry` entry point, `args` arguments, with a given `name`. Writes the thread handle to `destThread`.

**sceKernelUsleep(usecs)**

```c
int sceKernelUsleep(unsigned int usecs)
```

Sleeps the calling thread for `usecs` microseconds.

### Reversing Credits
- Various scene developers + BSD documentation
- alexaltea