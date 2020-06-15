#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceCoredumpAttachMemoryRegion();
void sceCoredumpAttachMemoryRegionAsUserFile();
void sceCoredumpAttachUserFile();
void sceCoredumpConfigDumpMode();
void sceCoredumpDebugTextOut();
void sceCoredumpGetStopInfoCpu();
void sceCoredumpGetStopInfoGpu();
void sceCoredumpGetThreadContextInfo();
void sceCoredumpInternalGetThreadContextInfo();
void sceCoredumpRegisterCoredumpHandler();
void sceCoredumpSetUserDataType();
void sceCoredumpUnregisterCoredumpHandler();
void sceCoredumpWriteUserData();
