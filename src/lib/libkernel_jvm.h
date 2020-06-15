#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void dup2();
void getrlimit();
void ioctl();
void kill();
void poll();
void pthread_kill();
void sceKernelGetExecutableModuleHandle();
void sceKernelJitCreateAliasOfSharedMemory();
void sceKernelJitCreateSharedMemory();
void sceKernelJitGetSharedMemoryInfo();
void sceKernelJitMapSharedMemory();
void setrlimit();
void sigaction();
void sigaddset();
void sigdelset();
void sigemptyset();
void sigfillset();
void sigismember();
void sigprocmask();
void sigsuspend();
void socketpair();
void sysconf();
void sysctl();
