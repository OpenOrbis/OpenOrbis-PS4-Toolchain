#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void access();
void chdir();
void dup();
void dup2();
void ioctl();
void lstat();
void pipe();
void poll();
void pthread_cond_setname_np();
void pthread_get_user_context_np();
void pthread_kill();
void pthread_mutex_setname_np();
void pthread_resume_user_context_np();
void pthread_suspend_user_context_np();
void sceKernelDebugRaiseException();
void sceKernelDebugRaiseExceptionWithContext();
void sceKernelGetFsSandboxRandomWord();
void sceKernelGetModuleInfoFromAddr();
void sceKernelJitCreateAliasOfSharedMemory();
void sceKernelJitCreateSharedMemory();
void sceKernelJitMapSharedMemory();
void sceKernelOpenSema();
void sceKernelSetProcessProperty();
void sem_setname();
void sigaction();
void sigaddset();
void sigaltstack();
void sigdelset();
void sigemptyset();
void sigfillset();
void sigismember();
void signal();
void sigprocmask();
void sigsuspend();
void socketpair();
void sysconf();
