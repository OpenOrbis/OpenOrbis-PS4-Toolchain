#include <stdint.h>
#include <sys/types.h>
#include <orbis/_types/kernel.h>
#include <orbis/_types/pthread.h>

#ifndef _SCE_KERNEL_H_
#define _SCE_KERNEL_H_

#ifdef __cplusplus 
extern "C" {
#endif

#define ORBIS_KERNEL_EVFILT_TIMER    EVFILT_TIMER
#define ORBIS_KERNEL_EVFILT_READ     EVFILT_READ
#define ORBIS_KERNEL_EVFILT_WRITE    EVFILT_WRITE
#define ORBIS_KERNEL_EVFILT_USER     EVFILT_USER
#define ORBIS_KERNEL_EVFILT_FILE     EVFILT_VNODE
#define ORBIS_KERNEL_EVFILT_GNM      EVFILT_GRAPHICS_CORE
#define ORBIS_KERNEL_EVFILT_VIDEO_OUT      EVFILT_DISPLAY
#define ORBIS_KERNEL_EVFILT_HRTIMER  EVFILT_HRTIMER
#define ORBIS_KERNEL_EVNOTE_DELETE   NOTE_DELETE
#define ORBIS_KERNEL_EVNOTE_WRITE    NOTE_WRITE
#define ORBIS_KERNEL_EVNOTE_EXTEND   NOTE_EXTEND
#define ORBIS_KERNEL_EVNOTE_ATTRIB   NOTE_ATTRIB
#define ORBIS_KERNEL_EVNOTE_RENAME   NOTE_RENAME
#define ORBIS_KERNEL_EVNOTE_REVOKE   NOTE_REVOKE
#define ORBIS_KERNEL_EVFLAG_EOF       EV_EOF
#define ORBIS_KERNEL_EVFLAG_ERROR     EV_ERROR
#define ORBIS_KERNEL_EVF_ATTR_TH_FIFO   0x01
#define ORBIS_KERNEL_EVF_ATTR_TH_PRIO   0x02
#define ORBIS_KERNEL_EVF_ATTR_SINGLE    0x10
#define ORBIS_KERNEL_EVF_ATTR_MULTI     0x20
#define ORBIS_KERNEL_EVF_WAITMODE_AND        0x01
#define ORBIS_KERNEL_EVF_WAITMODE_OR         0x02
#define ORBIS_KERNEL_EVF_WAITMODE_CLEAR_ALL  0x10
#define ORBIS_KERNEL_EVF_WAITMODE_CLEAR_PAT  0x20
//#define SCE_KERNEL_EVF_ID_INVALID     ((OrbisKernelEventFlag)-1)
#define ORBIS_KERNEL_SEMA_ATTR_TH_FIFO   0x01
#define ORBIS_KERNEL_SEMA_ATTR_TH_PRIO   0x02

extern uint64_t sceLibcHeapSize;
extern uint32_t sce_libc_heap_delayed_alloc;
extern uint32_t sce_libc_heap_extended_alloc;

// Empty Comment
int sceKernelAddFileEvent(OrbisKernelEqueue, int, int, void*);
// Empty Comment - need to port OrbisKernelTimespec
//int sceKernelAddHRTimerEvent(OrbisKernelEqueue, int, OrbisKernelTimespec*, void*);
// Empty Comment
int sceKernelAddReadEvent(OrbisKernelEqueue, int, size_t, void*);
// Empty Comment
int sceKernelAddTimerEvent(OrbisKernelEqueue, int, OrbisKernelUseconds, void*);
// Empty Comment
int sceKernelAddUserEvent(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelAddUserEventEdge(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelAddWriteEvent(OrbisKernelEqueue, int, size_t, void*);
// Empty Comment
int sceKernelAllocateDirectMemory(off_t, off_t, size_t, size_t, int, off_t*);
// Empty Comment
int32_t sceKernelAllocateMainDirectMemory(size_t, size_t, int, off_t);
// Empty Comment
int32_t sceKernelAvailableDirectMemorySize(off_t, off_t, size_t, off_t, size_t);
// Empty Comment
int32_t sceKernelAvailableFlexibleMemorySize(size_t);
// Empty Comment
void sceKernelBacktraceSelf();
// Empty Comment
void sceKernelBatchMap();
// Empty Comment
void sceKernelBatchMap2();
// Empty Comment
int sceKernelCancelEventFlag(OrbisKernelEventFlag, uint64_t, int*);
// Empty Comment
int sceKernelCancelSema(OrbisKernelSema, int, int*);
// Empty Comment
void sceKernelCheckedReleaseDirectMemory();
// Empty Comment
void sceKernelCheckReachability();
// Empty Comment
int sceKernelChmod(const char *path, OrbisKernelMode mode);
// Empty Comment
int sceKernelClearEventFlag(OrbisKernelEventFlag, uint64_t);
// Empty Comment
void sceKernelClearGameDirectMemory();
// Empty Comment
void sceKernelClockGetres();
// Empty Comment
void sceKernelClockGettime();
// Empty Comment
int sceKernelClose(int);
// Empty Comment
void sceKernelCloseEventFlag();
// Empty Comment
void sceKernelCloseSema();
// Empty Comment
void sceKernelConvertLocaltimeToUtc();
// Empty Comment
void sceKernelConvertUtcToLocaltime();
// Empty Comment
int sceKernelCreateEqueue(OrbisKernelEqueue*, const char*);
// Empty Comment
int sceKernelCreateEventFlag(OrbisKernelEventFlag*, const char*, uint32_t, uint64_t, const OrbisKernelEventFlagOptParam*);
// Empty Comment
int sceKernelCreateSema(OrbisKernelSema*, const char*, uint32_t, int, int, const OrbisKernelSemaOptParam*);
// Empty Comment
void sceKernelDebugGetAppStatus();
// Empty Comment
void sceKernelDebugGpuPaDebugIsInProgress();
// Empty Comment
void sceKernelDebugRaiseException();
// Empty Comment
void sceKernelDebugRaiseExceptionOnReleaseMode();
// Empty Comment
int sceKernelDeleteEqueue(OrbisKernelEqueue); 
// Empty Comment
int sceKernelDeleteEventFlag(OrbisKernelEventFlag);
// Empty Comment
int sceKernelDeleteFileEvent(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelDeleteHRTimerEvent(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelDeleteReadEvent(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelDeleteSema(OrbisKernelSema);
// Empty Comment
int sceKernelDeleteTimerEvent(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelDeleteUserEvent(OrbisKernelEqueue, int);
// Empty Comment
int sceKernelDeleteWriteEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDirectMemoryQuery(off_t, int, void *, size_t);
// Empty Comment
int sceKernelDlsym(int handle, const char *symbol, void **address);
// Empty Comment
void sceKernelError();
// Empty Comment
void sceKernelEventLogInit();
// Empty Comment
void sceKernelEventLogPread();
// Empty Comment
void sceKernelEventLogWrite();
// Empty Comment
int sceKernelFchmod(int, OrbisKernelMode);
// Empty Comment
int sceKernelFcntl(int, int, ...);
// Empty Comment
void sceKernelFlock();
// Empty Comment
int sceKernelFstat(int, OrbisKernelStat);
// Empty Comment
int sceKernelFsync(int);
// Empty Comment
int sceKernelFtruncate(int, off_t);
// Empty Comment
int sceKernelFutimes(int, const OrbisKernelTimeval *);
// Empty Comment
void sceKernelGetAllowedSdkVersionOnSystem();
// Empty Comment
void sceKernelGetAppInfo();
// Empty Comment
void sceKernelGetBackupRestoreMode();
// Empty Comment
void sceKernelGetCompiledSdkVersion();
// Empty Comment
void sceKernelGetCompiledSdkVersionByPid();
// Empty Comment
int sceKernelGetCpumode(void);
// Empty Comment
int sceKernelGetCurrentCpu(void);
// Empty Comment
void sceKernelGetDataTransferMode();
// Empty Comment
int sceKernelGetdents(int, char *, int);
// Empty Comment
size_t sceKernelGetDirectMemorySize();
// Empty Comment
int32_t sceKernelGetDirectMemoryType(off_t, int *, off_t *, off_t *);
// Empty Comment
int sceKernelGetdirentries(int, char *, int, long *);
// Empty Comment
intptr_t sceKernelGetEventData(const OrbisKernelEvent*);
// Empty Comment
int sceKernelGetEventError(const OrbisKernelEvent*);
// Empty Comment
unsigned int sceKernelGetEventFflags(const OrbisKernelEvent*);
// Empty Comment
int sceKernelGetEventFilter(const OrbisKernelEvent*);
// Empty Comment
uintptr_t sceKernelGetEventId(const OrbisKernelEvent*);
// Empty Comment
void* sceKernelGetEventUserData(const OrbisKernelEvent*);
// returns sandbox random word - used to load system modules by filepath.
const char * sceKernelGetFsSandboxRandomWord(void);
// Empty Comment
uint64_t sceKernelGetGPI(void);
// Empty Comment
void sceKernelGetGPO();
// Empty Comment
void sceKernelGetIdPs();
// Empty Comment
void sceKernelGetIpcPath();
// Empty Comment
void sceKernelGetModuleInfo();
// Empty Comment
void sceKernelGetModuleInfoForUnwind();
// Empty Comment
void sceKernelGetModuleInfoFromAddr();
// Empty Comment
void sceKernelGetModuleInfoInternal();
// Empty Comment
void sceKernelGetModuleList();
// Empty Comment
void sceKernelGetOpenPsIdForSystem();
// Empty Comment
int32_t sceKernelGetPageTableStats(int *, int*, int*, int*);
// Empty Comment
uint64_t sceKernelGetProcessTime(void);
// Empty Comment
uint64_t sceKernelGetProcessTimeCounter(void);
// Empty Comment
uint64_t sceKernelGetProcessTimeCounterFrequency(void);
// Empty Comment
void sceKernelGetProcParam();
// Empty Comment
int32_t sceKernelGetPrtAperture(int, void **, size_t *);
// Empty Comment
void sceKernelGetSubsysId();
// Empty Comment
void sceKernelGetSystemSwBeta();
// Empty Comment
void sceKernelGetSystemSwVersion();
// Empty Comment
int sceKernelGettimeofday(OrbisKernelTimeval *timeValue);
// Empty Comment
void sceKernelGettimezone();
// Empty Comment
uint64_t sceKernelGetTscFrequency(void);
// Empty Comment - needs reversed (only guessed, compared to other functions like it)
int sceKernelHasNeoMode(void);
// Empty Comment - needs reversed (only guessed, compared to other functions like it)
int sceKernelHwHasOpticalOut(void);
// Empty Comment
void sceKernelIccControlBDPowerState();
// Empty Comment
void sceKernelIccGetCpuInfoBit();
// Empty Comment
void sceKernelIccGetPowerNumberOfBootShutdown();
// Empty Comment
void sceKernelIccGetPowerOperatingTime();
// Empty Comment
void sceKernelIccGetPowerUpCause();
// Empty Comment
void sceKernelIccGetThermalAlert();
// Empty Comment
void sceKernelIccIndicatorBootDone();
// Empty Comment
void sceKernelIccIndicatorShutdown();
// Empty Comment
void sceKernelIccNotifyBootStatus();
// sceKernelIccNvsFlush = (DANGER / DO NOT USE THIS UNLESS YOU KNOW EXACTLY WHAT YOUR DOING, COULD RESULT IN A PERMA BRICK)
void sceKernelIccNvsFlush();
// Empty Comment
void sceKernelIccReadPowerBootMessage();
// Empty Comment
void sceKernelIccSetBuzzer();
// Empty Comment
void sceKernelIccSetCpuInfoBit();
// Empty Comment
void sceKernelInternalHeapPrintBacktraceWithModuleInfo();
// Empty Comment
void sceKernelInternalMemoryGetModuleSegmentInfo();
// Empty Comment
int sceKernelIsAuthenticNeo(void);
// Empty Comment
int sceKernelIsCEX(void);
// Empty Comment
int sceKernelIsDevKit(void);
// Empty Comment
int sceKernelIsGenuineN(void);
// Empty Comment
int sceKernelIsInSandbox(void);
// Empty Comment
int sceKernelIsKratos(void);
// Empty Comment
int sceKernelIsNeoMode(void);
// Empty Comment
int sceKernelIsStack(void *, void **, void **);
// Empty Comment
int sceKernelIsTestKit(void);
// Empty Comment
void sceKernelJitCreateAliasOfSharedMemory();
// Empty Comment
void sceKernelJitCreateSharedMemory();
// Empty Comment
void sceKernelJitGetSharedMemoryInfo();
// Empty Comment
void sceKernelJitMapSharedMemory();
// Empty Comment
uint32_t sceKernelLoadStartModule(const char *, size_t, const void *, uint32_t, void *, void *);
// Empty Comment
off_t sceKernelLseek(int, off_t, int);
// Empty Comment
int sceKernelLwfsAllocateBlock(int, off_t);
// Empty Comment
off_t sceKernelLwfsLseek(int, off_t, int);
// Empty Comment
int sceKernelLwfsSetAttribute(int, int);
// Empty Comment
ssize_t sceKernelLwfsWrite(int, const void *, size_t);
// Empty Comment
int32_t sceKernelMapDirectMemory(void**, size_t, int, int, off_t, size_t);
// Empty Comment
int32_t sceKernelMapDirectMemory2(void **, size_t, int, int, int, off_t, size_t);
// Empty Comment
int32_t sceKernelMapFlexibleMemory(void **, size_t, int, int);
// Empty Comment
int32_t sceKernelMapNamedDirectMemory(void **, size_t, int, int, off_t, size_t, const char *);
// Empty Comment
int32_t sceKernelMapNamedFlexibleMemory(void **, size_t, int, int, const char *);
// Empty Comment
void sceKernelMapNamedSystemFlexibleMemory();
// Empty Comment
int sceKernelMkdir(const char *path, OrbisKernelMode mode);
// Empty Comment
void sceKernelMlock();
// Empty Comment
void sceKernelMlockall();
// Empty Comment
int sceKernelMmap(void *, size_t, int, int, int, off_t, void **);
// Empty Comment
int sceKernelMprotect(const void *, size_t, int);
// Empty Comment
int sceKernelMsync(void *, size_t, int);
// Empty Comment
int32_t sceKernelMtypeprotect(const void *, size_t, int, int);
// Empty Comment
void sceKernelMunlock();
// Empty Comment
void sceKernelMunlockall();
// Empty Comment
int sceKernelMunmap(void *, size_t);
// Empty Comment
int sceKernelNanosleep(const OrbisKernelTimespec *, OrbisKernelTimespec *);
// Empty Comment
int sceKernelOpen(const char *, int, OrbisKernelMode);
// Empty Comment
void sceKernelOpenEventFlag();
// Empty Comment
void sceKernelOpenSema();
// Empty Comment
int sceKernelPollEventFlag(OrbisKernelEventFlag, uint64_t, uint32_t, uint64_t*);
// Empty Comment
int sceKernelPollSema(OrbisKernelSema, int);
// Empty Comment
size_t sceKernelPread(int, void *, size_t, off_t);
// Empty Comment
size_t sceKernelPreadv(int, const OrbisKernelIovec *, int, off_t);
// Empty Comment
void sceKernelPrintBacktraceWithModuleInfo();
// Empty Comment
size_t sceKernelPwrite(int, const void *, size_t, off_t);
// Empty Comment
size_t sceKernelPwritev(int, const OrbisKernelIovec *, int, off_t);
// Empty Comment
int32_t sceKernelQueryMemoryProtection(void *, void **, void **, int *);
// Empty Comment
void sceKernelRdup();
// Empty Comment
size_t sceKernelRead(int, void *, size_t);
// Empty Comment
uint64_t sceKernelReadTsc(void);
// Empty Comment
size_t sceKernelReadv(int, const OrbisKernelIovec *, int);
// Empty Comment
void sceKernelReboot();
// Empty Comment
int32_t sceKernelReleaseDirectMemory(off_t, size_t);
// Empty Comment
int32_t sceKernelReleaseFlexibleMemory(void *, size_t);
// Empty Comment
int sceKernelRename(const char *oldfilename, const char *newfilename);
// Empty Comment
void sceKernelReportUnpatchedFunctionCall();
// Empty Comment
int sceKernelReserveVirtualRange(void **, size_t, int, size_t);
// Empty Comment
int sceKernelRmdir(const char *folder);
// Empty Comment
void sceKernelSendNotificationRequest();
// Empty Comment
void sceKernelSetAppInfo();
// Empty Comment
void sceKernelSetBackupRestoreMode();
// Empty Comment
int sceKernelSetCompressionAttribute(int, int);
// Empty Comment
int sceKernelSetEventFlag(OrbisKernelEventFlag, uint64_t);
// Empty Comment - 2nd arg is OrbisKernelCpumask (needs reversed)
int sceKernelSetFsstParam(int, void *);
// Empty Comment
void sceKernelSetGPI();
// Empty Comment
void sceKernelSetGPO();
// Empty Comment
void sceKernelSetProcessName();
// Empty Comment
int32_t sceKernelSetPrtAperture(int, void *, size_t);
// Empty Comment
void sceKernelSetSafemode();
// Empty Comment
void sceKernelSettimeofday();
// Empty Comment
int32_t sceKernelSetVirtualRangeName(const void *, size_t, const char *);
// Empty Comment
void sceKernelSetVmContainer();
// Empty Comment
int sceKernelSignalSema(OrbisKernelSema, int);
// Empty Comment
int sceKernelSleep(unsigned int);
// Empty Comment
int sceKernelStat(const char *, OrbisKernelStat *);
// Empty Comment
int sceKernelStopUnloadModule(OrbisKernelModule, size_t, const void *, uint32_t, void *, int *);
// Empty Comment
void sceKernelSwitchToBaseMode();
// Empty Comment
void sceKernelSwitchToNeoMode();
// Empty Comment
void sceKernelSync(void);
// Empty Comment
void sceKernelTerminateSysCore();
// Empty Comment
void sceKernelTitleWorkaroundIsEnabled();
// Empty Comment
void sceKernelTitleWorkdaroundIsEnabled();
// Empty Comment
int sceKernelTriggerUserEvent(OrbisKernelEqueue, int, void*);
// Empty Comment
int sceKernelTruncate(const char *, off_t);
// Empty Comment
int sceKernelUnlink(const char *);
// Empty Comment
int sceKernelUsleep(unsigned int);
// Empty Comment
int sceKernelUtimes(const char *, const OrbisKernelTimeval *);
// Empty Comment
int sceKernelUuidCreate(OrbisKernelUuid*);
// Empty Comment
int32_t sceKernelVirtualQuery(const void *, int, OrbisKernelVirtualQueryInfo *, size_t);
// Empty Comment
int sceKernelWaitEqueue(OrbisKernelEqueue, OrbisKernelEvent*, int, int*, OrbisKernelUseconds*);
// Empty Comment
int sceKernelWaitEventFlag(OrbisKernelEventFlag, uint64_t, uint32_t, uint64_t*, OrbisKernelUseconds*);
// Empty Comment
int sceKernelWaitSema(OrbisKernelSema, int, OrbisKernelUseconds*);
// Empty Comment
size_t sceKernelWrite(int, const void *, size_t);
// Empty Comment
size_t sceKernelWritev(int, const OrbisKernelIovec *);
// Empty Comment
void sceLibcMspaceCreateForMonoMutex();
// Empty Comment
void scePthreadAtfork();
// Empty Comment
int scePthreadAttrDestroy(OrbisPthreadAttr*);
// Empty Comment
int scePthreadAttrGet(OrbisPthread, OrbisPthreadAttr*);
// Empty Comment
int scePthreadAttrGetaffinity(const OrbisPthreadAttr*, void*);
// void* is OrbisKernelCpumask, need to port OrbisKernelCpumask for above.. -cv
// Empty Comment
int scePthreadAttrGetdetachstate(const OrbisPthreadAttr*, int*);
// Empty Comment
int scePthreadAttrGetguardsize(const OrbisPthreadAttr*, size_t*);
// Empty Comment
void scePthreadAttrGetinheritsched();
// Empty Comment
void scePthreadAttrGetschedparam();
// Empty Comment
void scePthreadAttrGetschedpolicy();
// Empty Comment
void scePthreadAttrGetscope();
// Empty Comment
int scePthreadAttrGetstack(const OrbisPthreadAttr* __restrict, void** __restrict, size_t* __restrict);
// Empty Comment
int scePthreadAttrGetstackaddr(const OrbisPthreadAttr*, void**);
// Empty Comment
int scePthreadAttrGetstacksize(const OrbisPthreadAttr*, size_t*);
// Empty Comment
int scePthreadAttrInit(OrbisPthreadAttr*);
// Empty Comment
int scePthreadAttrSetaffinity(OrbisPthreadAttr*, const void *);
// void (2nd arg) is OrbisKernelCpumask, need to por OrbisKernelCpumask -cv
// Empty Comment
void scePthreadAttrSetcreatesuspend();
// Empty Comment
int scePthreadAttrSetdetachstate(OrbisPthreadAttr*, int);
// Empty Comment
int scePthreadAttrSetguardsize(OrbisPthreadAttr*, size_t);
// Empty Comment
void scePthreadAttrSetinheritsched();
// Empty Comment
void scePthreadAttrSetschedparam();
// Empty Comment
void scePthreadAttrSetschedpolicy();
// Empty Comment
void scePthreadAttrSetscope();
// Empty Comment
int scePthreadAttrSetstack(OrbisPthreadAttr*, void*, size_t);
// Empty Comment
int scePthreadAttrSetstackaddr(OrbisPthreadAttr*, void*);
// Empty Comment
int scePthreadAttrSetstacksize(OrbisPthreadAttr*, size_t);
// Empty Comment
int scePthreadBarrierattrDestroy(OrbisPthreadBarrierattr*);
// Empty Comment
void scePthreadBarrierattrGetpshared();
// Empty Comment
int scePthreadBarrierattrInit(OrbisPthreadBarrierattr*);
// Empty Comment
void scePthreadBarrierattrSetpshared();
// Empty Comment
int scePthreadBarrierDestroy(OrbisPthreadBarrier*);
// Empty Comment
int scePthreadBarrierInit(OrbisPthreadBarrier*, const OrbisPthreadBarrierattr*, unsigned, const char*);
// Empty Comment
int scePthreadBarrierWait(OrbisPthreadBarrier*);
// Empty Comment
int scePthreadCancel(OrbisPthread);
// Empty Comment
int scePthreadCondattrDestroy(OrbisPthreadCondattr*);
// Empty Comment
void scePthreadCondattrGetclock();
// Empty Comment
void scePthreadCondattrGetpshared();
// Empty Comment
int scePthreadCondattrInit(OrbisPthreadCondattr*);
// Empty Comment
void scePthreadCondattrSetclock();
// Empty Comment
void scePthreadCondattrSetpshared();
// Empty Comment
int scePthreadCondBroadcast(OrbisPthreadCond*);
// Empty Comment
int scePthreadCondDestroy(OrbisPthreadCond*);
// Empty Comment
int scePthreadCondInit(OrbisPthreadCond*, const OrbisPthreadCondattr*, const char*);
// Empty Comment
int scePthreadCondSignal(OrbisPthreadCond*);
// Empty Comment
int scePthreadCondSignalto(OrbisPthreadCond*, OrbisPthread);
// Empty Comment
int scePthreadCondTimedwait(OrbisPthreadCond*, OrbisPthreadMutex*, OrbisKernelUseconds);
// Empty Comment
int scePthreadCondWait(OrbisPthreadCond*, OrbisPthreadMutex*);
// Empty Comment
int scePthreadCreate(OrbisPthread *, const OrbisPthreadAttr *, void *, void *, const char *);
// Empty Comment
int scePthreadDetach(OrbisPthread);
// Empty Comment
int scePthreadEqual(OrbisPthread, OrbisPthread);
// Empty Comment
void scePthreadExit(void*);
// Empty Comment
void scePthreadGetaffinity();
// Empty Comment
void scePthreadGetconcurrency();
// Empty Comment
int scePthreadGetcpuclockid(OrbisPthread, clockid_t*);
// Empty Comment
int scePthreadGetname(OrbisPthread, char*);
// Empty Comment
int scePthreadGetprio(OrbisPthread, int*);
// Empty Comment
void scePthreadGetschedparam();
// Empty Comment
void* scePthreadGetspecific(OrbisPthreadKey);
// Empty Comment
int scePthreadGetthreadid(void);
// Empty Comment
int scePthreadJoin(OrbisPthread, void**);
// Empty Comment
int scePthreadKeyCreate(OrbisPthreadKey*, void(*destructor)(void*));
// Empty Comment
int scePthreadKeyDelete(OrbisPthreadKey);
// Empty Comment
void scePthreadMain();
// Empty Comment
void scePthreadMulti();
// Empty Comment
int scePthreadMutexattrDestroy(OrbisPthreadMutexattr*);
// Empty Comment
void scePthreadMutexattrGetkind();
// Empty Comment
int scePthreadMutexattrGetprioceiling(OrbisPthreadMutexattr*, int*);
// Empty Comment
int scePthreadMutexattrGetprotocol(OrbisPthreadMutexattr*, int*);
// Empty Comment
void scePthreadMutexattrGetpshared();
// Empty Comment
int scePthreadMutexattrGettype(OrbisPthreadMutexattr*, int*);
// Empty Comment
int scePthreadMutexattrInit(OrbisPthreadMutexattr*);
// Empty Comment
void scePthreadMutexattrSetkind();
// Empty Comment
int scePthreadMutexattrSetprioceiling(OrbisPthreadMutexattr*, int);
// Empty Comment
int scePthreadMutexattrSetprotocol(OrbisPthreadMutexattr*, int);
// Empty Comment
void scePthreadMutexattrSetpshared();
// Empty Comment
int scePthreadMutexattrSettype(OrbisPthreadMutexattr*, int);
// Empty Comment
int scePthreadMutexDestroy(OrbisPthreadMutex*);
// Empty Comment
int scePthreadMutexGetprioceiling(OrbisPthreadMutex*, int*);
// Empty Comment
void scePthreadMutexGetspinloops();
// Empty Comment
void scePthreadMutexGetyieldloops();
// Empty Comment
int scePthreadMutexInit(OrbisPthreadMutex*, const OrbisPthreadMutexattr*, const char*);
// Empty Comment
void scePthreadMutexIsowned();
// Empty Comment
int scePthreadMutexLock(OrbisPthreadMutex*);
// Empty Comment
int scePthreadMutexSetprioceiling(OrbisPthreadMutex*, int, int*);
// Empty Comment
void scePthreadMutexSetspinloops();
// Empty Comment
void scePthreadMutexSetyieldloops();
// Empty Comment
int scePthreadMutexTimedlock(OrbisPthreadMutex*, OrbisKernelUseconds);
// Empty Comment
int scePthreadMutexTrylock(OrbisPthreadMutex*);
// Empty Comment
int scePthreadMutexUnlock(OrbisPthreadMutex*);
// Empty Comment
int scePthreadOnce(OrbisPthreadOnce*, void(*init)(void));
// Empty Comment
int scePthreadRename(OrbisPthread, const char*);
// Empty Comment
void scePthreadResume();
// Empty Comment
void scePthreadResumeAll();
// Empty Comment
int scePthreadRwlockattrDestroy(OrbisPthreadRwlockattr*);
// Empty Comment
void scePthreadRwlockattrGetpshared();
// Empty Comment
int scePthreadRwlockattrInit(OrbisPthreadRwlockattr*);
// Empty Comment
void scePthreadRwlockattrSetpshared();
// Empty Comment
int scePthreadRwlockDestroy(OrbisPthreadRwlock*);
// Empty Comment
int scePthreadRwlockInit(OrbisPthreadRwlock*, const OrbisPthreadRwlockattr*, const char*);
// Empty Comment
int scePthreadRwlockRdlock(OrbisPthreadRwlock*);
// Empty Comment
int scePthreadRwlockTimedrdlock(OrbisPthreadRwlock*, OrbisKernelUseconds);
// Empty Comment
int scePthreadRwlockTimedwrlock(OrbisPthreadRwlock*, OrbisKernelUseconds);
// Empty Comment
int scePthreadRwlockTryrdlock(OrbisPthreadRwlock*);
// Empty Comment
int scePthreadRwlockTrywrlock(OrbisPthreadRwlock*);
// Empty Comment
int scePthreadRwlockUnlock(OrbisPthreadRwlock*);
// Empty Comment
int scePthreadRwlockWrlock(OrbisPthreadRwlock*);
// Empty Comment
void scePthreadSelf();
// Empty Comment
void scePthreadSetaffinity();
// Empty Comment
void scePthreadSetBesteffort();
// Empty Comment
int scePthreadSetcancelstate(int, int*);
// Empty Comment
int scePthreadSetcanceltype(int, int*);
// Empty Comment
void scePthreadSetconcurrency();
// Empty Comment
void scePthreadSetName();
// Empty Comment
int scePthreadSetprio(OrbisPthread, int);
// Empty Comment
void scePthreadSetschedparam();
// Empty Comment
int scePthreadSetspecific(OrbisPthreadKey, const void*);
// Empty Comment
void scePthreadSingle();
// Empty Comment
void scePthreadSuspend();
// Empty Comment
void scePthreadSuspendAll();
// Empty Comment
void scePthreadTestcancel(void);
// Empty Comment
void scePthreadTimedjoin();
// Empty Comment
void scePthreadYield(void);

#ifdef __cplusplus
}
#endif

#endif