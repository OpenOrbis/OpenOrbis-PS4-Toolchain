# VideoOut library
The VideoOut library is used for sending events to video output to display on the screen.

### Known Macros
The video library seems to need a service user to perform actions on behalf of. The best one to use is the system ID, which is `0xFF`.

```c
#define ORBIS_VIDEO_USER_MAIN		0xFF
```

There are also various buses used to determine where the output ultimately goes. We know of 3; the main bus, the social bus, and the live bus.

```c
#define ORBIS_VIDEO_OUT_BUS_MAIN	0
#define ORBIS_VIDEO_OUT_BUS_SOCIAL	5
#define ORBIS_VIDEO_OUT_BUS_LIVE	6
```

The flip subsystem also takes a mode. The common one used is vsync.

```c
#define ORBIS_VIDEO_OUT_FLIP_VSYNC  1
```



### Known Structures

#### OrbisVideoOutFlipStatus
The flip status structure is an output structure used for when the flip queue is polled.

- **uint64_t num**: Number of flip events in the queue
- **uint64_t ptime**: Time
- **uint64_t stime**: Time
- **int64_t flipArg**: Flip arguments
- **uint64_t reserved[2]**: N/A
- **int32_t numGpuFlipPending**: Number of pending flips for the GPU
- **int32_t numFlipPending**: Number of pending flips
- **int32_t currentBuffer**: Buffer index
- **uint32_t unknown**: N/A

### Known Functions
**sceVideoOutOpen(userID, busType, int, void \*)**

```c
int sceVideoOutOpen(int userID, int busType, int, const void *)
```

Opens a handle to video out under the given `userID` on the given `busType`. Other two parameters not known. Returns a handle on success, negative value on failure.

**sceVideoOutClose(handle)**

```c
int sceVideoOutClose(int handle)
```

Closes the given handle. Returns 0 on success, non-zero on failure.

**sceVideoOutRegisterBuffers(handle, index, \*addr, num, OrbisVideoOutBufferAttribute)**

```c
int sceVideoOutRegisterBuffers(int handle, int index, void *addr, int num, OrbisVideoOutBufferAttribute *attr)
```

Registers `num` buffers at `index` from `addr` with the given `attr` attributes. Returns 0 on success, non-zero otherwise.

**sceVideoOutUnregisterBuffers(handle, int)**

```c
int sceVideoOutUnregisterBuffers(int handle, int index)
```

Unregisters buffers at `index` from `handle`. Returns 0 on success, non-zero otherwise.

**sceVideoOutSubmitFlip(handle, index, mode, arg)**

```c
int sceVideoOutSubmitFlip(int handle, int index, int mode, int arg)
```

Submits a flip event to `handle` at buffer `index` with a mode of `mode` with the given `arg`. Returns 0 on success, non-zero otherwise.

**sceVideoOutSetFlipRate(handle, flipRate)**

```c
int sceVideoOutSetFlipRate(int handle, int flipRate)
```

Sets the `flipRate` on a given `handle`. Returns 0 on success, non-zero otherwise.

**sceVideoOutAddFlipEvent(eventQueue, handle, \*data)**

```c
int sceVideoOutAddFlipEvent(OrbisKernelEqueue eq, int handle, void *data)
```

Adds a flip event to the event queue `eq` on a given `handle` with the given `data`. Returns 0 on success, non-zero otherwise.

**sceVideoOutGetFlipStatus(handle, OrbisVideoOutFlipStatus \*outStatus)**

```c
int sceVideoOutGetFlipStatus(int handle, OrbisVideoOutFlipStatus *status)
```

Gets the flip status on the given `handle` and writes it to `outStatus`.

### Reversing Credits
- bigboss (psxdev)