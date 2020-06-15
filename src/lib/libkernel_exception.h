#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceKernelAddGpuExceptionEvent();
void sceKernelBacktraceSelf();
void sceKernelDeleteGpuExceptionEvent();
void sceKernelInstallExceptionHandler();
void sceKernelRemoveExceptionHandler();
