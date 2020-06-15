#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceSysmoduleGetModuleHandleInternal();
void sceSysmoduleIsCalledFromSysModule();
void sceSysmoduleIsCameraPreloaded();
void sceSysmoduleIsLoaded();
void sceSysmoduleIsLoadedInternal();
void sceSysmoduleLoadModule();
void sceSysmoduleLoadModuleByNameInternal();
void sceSysmoduleLoadModuleInternal();
void sceSysmoduleLoadModuleInternalWithArg();
void sceSysmoduleMapLibcForLibkernel();
void sceSysmodulePreloadModuleForLibkernel();
void sceSysmoduleUnloadModule();
void sceSysmoduleUnloadModuleByNameInternal();
void sceSysmoduleUnloadModuleInternal();
void sceSysmoduleUnloadModuleInternalWithArg();
