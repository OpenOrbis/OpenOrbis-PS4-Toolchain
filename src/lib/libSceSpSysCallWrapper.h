#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceSpGetPid();
void sceSpKernelGettimeofday();
void sceSpKernelNanosleep();
void sceSpNetConnect();
void sceSpNetEpollAbort();
void sceSpNetEpollControl();
void sceSpNetEpollCreate();
void sceSpNetEpollDestroy();
void sceSpNetEpollWait();
void sceSpNetErrnoLoc();
void sceSpNetPoolCreate();
void sceSpNetPoolDestroy();
void sceSpNetRecv();
void sceSpNetResolverAbort();
void sceSpNetResolverCreate();
void sceSpNetResolverDestroy();
void sceSpNetResolverGetError();
void sceSpNetResolverStartNtoa();
void sceSpNetSend();
void sceSpNetSetsockopt();
void sceSpNetSocket();
void sceSpNetSocketClose();
void sceSpPthreadAttrDestroy();
void sceSpPthreadAttrInit();
void sceSpPthreadAttrSetinheritsched();
void sceSpPthreadAttrSetschedparam();
void sceSpPthreadAttrSetstacksize();
void sceSpPthreadCondattrDestroy();
void sceSpPthreadCondattrInit();
void sceSpPthreadCondDestroy();
void sceSpPthreadCondInit();
void sceSpPthreadCondSignal();
void sceSpPthreadCondWait();
void sceSpPthreadCreate();
void sceSpPthreadDetach();
void sceSpPthreadExit();
void sceSpPthreadJoin();
void sceSpPthreadMutexattrDestroy();
void sceSpPthreadMutexattrInit();
void sceSpPthreadMutexattrSetprioceiling();
void sceSpPthreadMutexattrSetprotocol();
void sceSpPthreadMutexattrSettype();
void sceSpPthreadMutexDestroy();
void sceSpPthreadMutexInit();
void sceSpPthreadMutexLock();
void sceSpPthreadMutexUnlock();
void sceSpPthreadSetprio();
void sceSpSelect();
