# MiraLib C# RPC Listing

The MiraConnection RPC classes are used for interfacing with Mira's plugins. This includes the debugger and file explorer. Each `Console` class will have it's own public instance of the `MiraConnection` class initialized when the console's `Connect()` method is called. Attached to this class are the noted RPC classes. Below is a listing of these classes and their methods. This listing has been pulled into a separate file as it's much larger than the class listings, so it's notable enough for it's own file.

## Debugger
### Enumerations

**Signals**

```csharp
public enum Signals : int
{
      SIGHUP = 1,
      SIGINT = 2,
      SIGQUIT = 3,
      SIGILL = 4,
      SIGTRAP = 5,
      SIGABRT = 6,
      SIGIOT = SIGABRT,
      SIGEMT = 7,
      SIGFPE = 8,
      SIGKILL = 9,
      SIGBUS = 10,
      SIGSEGV = 11,
      SIGSYS = 12,
      SIGPIPE = 13,
      SIGALRM = 14,
      SIGTERM = 15,
      SIGURG = 16,
      SIGSTOP = 17,
      SIGSTP = 18,
      SIGCONT = 19,
      SIGCHLD = 20,
      SIGTTIN = 21,
      SIGTTOU = 22,
      SIGIO = 23,
}
```

**Protections**

```csharp
public enum Protections : int
{
      PROT_READ = 0x01,
      PROT_WRITE = 0x02,
      PROT_EXEC = 0x04
}
```


### Methods

**Attach(p_ProcessId)**

```csharp
public static bool Attach(this MiraLib.MiraConnection p_Connection, int p_ProcessId)
```

Allows the `ptrace` subsystem Mira uses to attach to a given process ID. This function will need to be called for most other endpoints to function, such as read/write memory. *Warning: attaching to critical system processes like syscore may result in crashing or hanging the system*.

**Detach(p_Force = false)**

```csharp
public static bool Detach(this MiraLib.MiraConnection p_Connection, bool p_Force = false)
```

Allows the `ptrace` subsystem Mira uses to detach from an attached process. You should call this function on exit when you no longer need to debug a process. `p_Force` is provided if detach will not gracefully detach and you absolutely need to detach, but in most cases it should be left as `false`.

**GetProcList()**

```csharp
public static List<DbgProcessLimited> GetProcList(this MiraLib.MiraConnection p_Connection)
```

Allows you to get a current list of active processes running on the PS4 in the form of a list of `DbgProcessLimited` objects. This object provides less information than `GetProcessInfo` in the interest of conserving memory, so call that on a given process ID if you need more complete information.

**ReadMemory(p_Address, p_Size)**

```csharp
public static byte[] ReadMemory(this MiraLib.MiraConnection p_Connection, ulong p_Address, uint p_Size)
```

Reads `p_Size` bytes at `p_Address` in the currently attached processes' virtual memory and returns it.

**WriteMemory(p_Address, p_Data)**

```csharp
public static bool WriteMemory(this MiraLib.MiraConnection p_Connection, ulong p_Address, byte[] p_Data)
```

Writes the bytes from `p_Data` into `p_Address` in the currently attached processes' virtual memory. 

**Protect(p_Address, p_Size, p_Protection)**

```csharp
public static bool Protect(this MiraLib.MiraConnection p_Connection, ulong p_Address, uint p_Size, int p_Protection)
```

Provides the capability to set a given memory `p_Protection` on a given `p_Address` for `p_Size` bytes.

**GetProcessInfo(p_ProcessId)**

```csharp
public static DbgProcessFull GetProcessInfo(this MiraLib.MiraConnection p_Connection, int p_ProcessId)
```

Takes a `p_ProcessId` and attempts to get information on the process. The returned information is stored in the `DbgProcessFull` structure.

**Allocate(p_Size)**

```csharp
public static ulong Allocate(this MiraLib.MiraConnection p_Connection, uint p_Size)
```

Exposes the capability to allocate heap memory in the attached processes' virtual memory, and returns a pointer to the new allocation.

**Free(p_Address, p_Size = 0)**

```csharp
public static bool Free(this MiraLib.MiraConnection p_Connection, ulong p_Address, uint p_Size = 0)
```

Exposes the capability to free heap memory in the attached processes' virtual memory, and returns whether or not the free succeeded.

**SignalProcess(p_Signal)**

```csharp
public static bool SignalProcess(this MiraLib.MiraConnection p_Connection, int p_Signal)
```

Sends the given `p_Signal` to the currently attached process. *Warning: sending signals such as SIGKILL seem to cause issues, and sending signals to any critical system process may result in a crash or hang*.


### Objects

**DbgGpRegisters**

```csharp
class DbgGpRegisters
{
    Int64    R_r15;
    Int64    R_r14;
    Int64    R_r13;
    Int64    R_r12;
    Int64    R_r11;
    Int64    R_r10;
    Int64    R_r9;
    Int64    R_r8;
    Int64    R_rdi;
    Int64    R_rsi;
    Int64    R_rbp;
    Int64    R_rbx;
    Int64    R_rdx;
    Int64    R_rcx;
    Int64    R_rax;
    Int32    R_trapno;
    Int32    R_fs;
    Int32    R_gs;
    Int32    R_err;
    Int32    R_es;
    Int32    R_ds;
    Int64    R_rip;
    Int64    R_cs;
    Int64    R_rflags;
    Int64    R_rsp;
    Int64    R_ss;
}
```

**DbgThreadLimited**

```csharp
class DbgThreadLimited
{
    Int64 Proc;
    int32 ThreadId;
    string Name;
    int64 Retval;
    Int64 KernelStack;
    int32 KernelStackPages;
    int32 Err_no;
}
```

**DbgThreadFull**

```csharp
class DbgThreadFull
{
    Int64 Proc;
    int32 ThreadId;
    String Name;
    int64 Retval;
    Int64 KernelStack;
    Int32 KernelStackPages;
    Int32 Err_no;
    DbgGpRegisters GpRegisters;
    DbgFpRegisters FpRegisters;
    DbgDbRegisters DbRegisters;
}
```

**DbgCred**

```csharp
class DbgCred {
    Int32 EffectiveUserId;
    Int32 RealUserId;
    Int32 SavedUserId;
    Int32 NumGroups;
    Int32 RealGroupId;
    Int32 SavedGroupId;
    Int64 Prison;
    Int64 SceAuthId;
    Int64 SceCaps[4];
    Int64 SceAttr[4]; 
}
```

**DbgProcessLimited**

```csharp
class DbgProcessLimited
{
    Int32 ProcessId;
    string Name;
    DbgVmEntry Entries[];
}
```

**DbgProcessFull**

```csharp
class DbgProcessFull
{
    DbgThreadLimited Threads[];
    DbgCred Cred;
    Int32 ProcessId;
    Int64 ParentProc;
    Int32 Oppid;
    Int32 DbgChild;
    Int64 Vmspace;
    Int32 ExitThreads;
    Int32 SigParent;
    Int32 Sig;
    Int32 Code;
    Int32 Stops;
    Int32 Stype;
    Int64 SingleThread;
    Int32 SuspendCount;
    Int64 Dynlib;
    string Name;
    string ElfPath;
    string RandomizedPath;
    Int32 NumThreads;
    DbgVmEntry MapEntries[];
}
```

**DbgVmEntry**

```csharp
class DbgVmEntry
{
    string Name;
    Int64 Start;
    Int64 End;
    Int64 Offset;
    Int32 Protection;
}
```