namespace MiraConnection.Rpc.Debugger
{
    public enum DebuggerCommands : uint
    {
        DbgCmd_None = 0x7AB56E31,
        DbgCmd_ReadMem = 0xF25FEE19,
        DbgCmd_WriteMem = 0x78B3A60C,
        DbgCmd_ProtectMem = 0x73FA541B,
        DbgCmd_ScanMem = 0xEDCCE6D4,
        DbgCmd_GetProcInfo = 0xF3B7D3F1,
        DbgCmd_AllocateProcMem = 0x16FE60FC,
        DbgCmd_FreeProcMem = 0x93E0CC76,
        DbgCmd_GetProcMap = 0x758DC819,
        DbgCmd_Attach = 0xFEFCF9C8,
        DbgCmd_Detach = 0xF3B1D649,
        DbgCmd_Breakpoint = 0xD60E69E4,
        DbgCmd_Watchpoint = 0x23DE0FCE,
        DbgCmd_GetProcThreads = 0x1F5290F2,
        DbgCmd_SignalProc = 0xA2E2610F,
        DbgCmd_GetRegs = 0x449EAA46,
        DbgCmd_SetRegs = 0xD70F129B,
        DbgCmd_GetThreadInfo = 0x51B931C2,
        DbgCmd_ThreadSinglestep = 0x080B3752,
        DbgCmd_ReadKernelMem = 0x844AE491,
        DbgCmd_WriteKernelMem = 0xCFD904E7,
        DbgCmd_GetProcList = 0x7CF61ABE
    }
}
