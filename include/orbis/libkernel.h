#include <stdint.h>
#include <sys/types.h>
#include <orbis/_types/kernel.h>
#include <orbis/_types/pthread.h>
#include <orbis/_types/errors.h>

#ifndef _SCE_KERNEL_H_
#define _SCE_KERNEL_H_

#ifdef __cplusplus 
extern "C" {
#endif

extern uint64_t sceLibcHeapSize;
extern uint32_t sce_libc_heap_delayed_alloc;
extern uint32_t sce_libc_heap_extended_alloc;

struct Proc_Stats
{
	int32_t lo_data;								//0x00
	uint32_t td_tid;						//0x04
	OrbisKernelTimespec user_cpu_usage_time;	//0x08
	OrbisKernelTimespec system_cpu_usage_time;  //0x18
}; //0x28

// Empty Comment
int32_t sceKernelDebugOutText(int32_t dbg_channel, const char* text, ...);
// Empty Comment
int32_t sceKernelGetThreadName(uint32_t id, char* out);
// Empty Comment
int32_t sceKernelGetCpuUsage(struct Proc_Stats* out, int32_t* size);
// Empty Comment
int32_t sceKernelGetCpuFrequency();
// Empty Comment
int32_t sceKernelAddFileEvent(OrbisKernelEqueue, int32_t, int32_t, void*);
// Empty Comment - need to port OrbisKernelTimespec
//int32_t sceKernelAddHRTimerEvent(OrbisKernelEqueue, int32_t, OrbisKernelTimespec*, void*);
// Empty Comment
int32_t sceKernelAddReadEvent(OrbisKernelEqueue, int32_t, size_t, void*);
// Empty Comment
int32_t sceKernelAddTimerEvent(OrbisKernelEqueue, int32_t, OrbisKernelUseconds, void*);
// Empty Comment
int32_t sceKernelAddUserEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelAddUserEventEdge(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelAddWriteEvent(OrbisKernelEqueue, int32_t, size_t, void*);
// Empty Comment
int32_t sceKernelAllocateDirectMemory(off_t, off_t, size_t, size_t, int32_t, off_t*);
// Empty Comment
int32_t sceKernelAllocateMainDirectMemory(size_t, size_t, int32_t, off_t*);
// Empty Comment
int32_t sceKernelAvailableDirectMemorySize(off_t, off_t, size_t, off_t, size_t);
// Empty Comment
int32_t sceKernelAvailableFlexibleMemorySize(size_t*);
// Empty Comment
void sceKernelBacktraceSelf();
// Empty Comment
int32_t sceKernelBatchMap(void*, int, int*);
// Empty Comment
int32_t sceKernelBatchMap2(void*, int, int*, int);
// Empty Comment
int32_t sceKernelCancelEventFlag(OrbisKernelEventFlag, uint64_t, int32_t*);
// Empty Comment
int32_t sceKernelCancelSema(OrbisKernelSema, int32_t, int32_t*);
// Empty Comment
void sceKernelCheckedReleaseDirectMemory(off_t memstart, size_t memlen);
// Empty Comment
int sceKernelCheckReachability(char*);
// Empty Comment
int32_t sceKernelChmod(const char *path, OrbisKernelMode mode);
// Empty Comment
int32_t sceKernelClearEventFlag(OrbisKernelEventFlag, uint64_t);
// Empty Comment
void sceKernelClearGameDirectMemory();
// Empty Comment
void sceKernelClockGetres();
// Empty Comment
void sceKernelClockGettime();
// Empty Comment
int32_t sceKernelClose(int32_t);
// Empty Comment
int32_t sceKernelCloseEventFlag(void* event);
// Empty Comment
void sceKernelCloseSema();
// Empty Comment
void sceKernelConvertLocaltimeToUtc();
// Empty Comment
void sceKernelConvertUtcToLocaltime();
// Empty Comment
int32_t sceKernelCreateEqueue(OrbisKernelEqueue*, const char*);
// Empty Comment
int32_t sceKernelCreateEventFlag(OrbisKernelEventFlag*, const char*, uint32_t, uint64_t, const OrbisKernelEventFlagOptParam*);
// Empty Comment
int32_t sceKernelCreateSema(OrbisKernelSema*, const char*, uint32_t, int32_t, int32_t, const OrbisKernelSemaOptParam*);
// Empty Comment
void sceKernelDebugGetAppStatus();
// Empty Comment
void sceKernelDebugGpuPaDebugIsInProgress();
// Empty Comment
void sceKernelDebugRaiseException();
// Empty Comment
void sceKernelDebugRaiseExceptionOnReleaseMode();
// Empty Comment
int32_t sceKernelDeleteEqueue(OrbisKernelEqueue); 
// Empty Comment
int32_t sceKernelDeleteEventFlag(OrbisKernelEventFlag);
// Empty Comment
int32_t sceKernelDeleteFileEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDeleteHRTimerEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDeleteReadEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDeleteSema(OrbisKernelSema);
// Empty Comment
int32_t sceKernelDeleteTimerEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDeleteUserEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDeleteWriteEvent(OrbisKernelEqueue, int);
// Empty Comment
int32_t sceKernelDirectMemoryQuery(off_t, int32_t, void *, size_t);
// Empty Comment
int32_t sceKernelDlsym(int32_t handle, const char *symbol, void **address);
// Empty Comment
void sceKernelError();
// Empty Comment
void sceKernelEventLogInit();
// Empty Comment
void sceKernelEventLogPread();
// Empty Comment
void sceKernelEventLogWrite();
// Empty Comment
int32_t sceKernelFchmod(int32_t, OrbisKernelMode);
// Empty Comment
int32_t sceKernelFcntl(int32_t, int32_t, ...);
// Empty Comment
void sceKernelFlock();
// Get stats from a descriptor
int32_t sceKernelFstat(int32_t, OrbisKernelStat*);
// Empty Comment
int32_t sceKernelFsync(int32_t);
// Empty Comment
int32_t sceKernelFtruncate(int32_t, off_t);
// Empty Comment
int32_t sceKernelFutimes(int32_t, const OrbisKernelTimeval *);
// Empty Comment
void sceKernelGetAllowedSdkVersionOnSystem();
// Empty Comment
int32_t sceKernelGetAppInfo(pid_t pid, OrbisAppInfo* info);
// Empty Comment
void sceKernelGetBackupRestoreMode();
// Empty Comment
void sceKernelGetCompiledSdkVersion();
// Empty Comment
void sceKernelGetCompiledSdkVersionByPid();
// Empty Comment
int32_t sceKernelGetCpumode(void);
// Empty Comment
int32_t sceKernelGetCurrentCpu(void);
// Empty Comment
void sceKernelGetDataTransferMode();
// Empty Comment
int32_t sceKernelGetdents(int32_t, char *, int);
// Empty Comment
size_t sceKernelGetDirectMemorySize();
// Empty Comment
int32_t sceKernelGetDirectMemoryType(off_t, int32_t *, off_t *, off_t *);
// Empty Comment
int32_t sceKernelGetdirentries(int32_t, char *, int32_t, int64_t *);
// Empty Comment
intptr_t sceKernelGetEventData(const OrbisKernelEvent*);
// Empty Comment
int32_t sceKernelGetEventError(const OrbisKernelEvent*);
// Empty Comment
uint32_t sceKernelGetEventFflags(const OrbisKernelEvent*);
// Empty Comment
int32_t sceKernelGetEventFilter(const OrbisKernelEvent*);
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
int32_t sceKernelGetModuleInfo(OrbisKernelModule handle, OrbisKernelModuleInfo* info);
// Empty Comment
int32_t sceKernelGetModuleInfoForUnwind(void* addr, uint32_t flags, OrbisKernelModuleInfoForUnwind* info);
// Empty Comment
int32_t sceKernelGetModuleInfoFromAddr(void* addr, uint32_t flags, OrbisKernelModuleInfoEx* info);
// Empty Comment
int32_t sceKernelGetModuleInfoInternal(OrbisKernelModule handle, OrbisKernelModuleInfoEx* info);
// Empty Comment
int32_t sceKernelGetModuleList(OrbisKernelModule *array, size_t size, size_t *available);
// Empty Comment
int32_t sceKernelGetOpenPsIdForSystem(void* ret);
// Empty Comment
int32_t sceKernelGetPageTableStats(int32_t *, int32_t*, int32_t*, int32_t*);
// Empty Comment
uint64_t sceKernelGetProcessTime(void);
// Empty Comment
uint64_t sceKernelGetProcessTimeCounter(void);
// Empty Comment
uint64_t sceKernelGetProcessTimeCounterFrequency(void);
// Empty Comment
void sceKernelGetProcParam();
// Empty Comment
int32_t sceKernelGetPrtAperture(int32_t, void **, size_t *);
// Empty Comment
void sceKernelGetSubsysId();
// Empty Comment
void sceKernelGetSystemSwBeta();
// Empty Comment
int32_t sceKernelGetSystemSwVersion(OrbisKernelSwVersion *version);
// Empty Comment
int32_t sceKernelGettimeofday(OrbisKernelTimeval *timeValue);
// Empty Comment
void sceKernelGettimezone();
// Empty Comment
uint64_t sceKernelGetTscFrequency(void);
// Empty Comment - needs reversed (only guessed, compared to other functions like it)
int32_t sceKernelHasNeoMode(void);
// Empty Comment - needs reversed (only guessed, compared to other functions like it)
int32_t sceKernelHwHasOpticalOut(void);
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
void sceKernelIccIndicatorShutdown();
void sceKernelIccIndicatorStandby();
void sceKernelIccIndicatorStandbyBoot();
void sceKernelIccIndicatorStandbyShutdown();
// Empty Comment
void sceKernelIccNotifyBootStatus();
// sceKernelIccNvsFlush = (DANGER / DO NOT USE THIS UNLESS YOU KNOW EXACTLY WHAT YOUR DOING, COULD RESULT IN A PERMA BRICK)
void sceKernelIccNvsFlush();
// Empty Comment
void sceKernelIccReadPowerBootMessage();
// Empty Comment
void sceKernelIccSetBuzzer(int32_t mode);
// Empty Comment
void sceKernelIccSetCpuInfoBit();
// Empty Comment
void sceKernelInternalHeapPrintBacktraceWithModuleInfo();
// Empty Comment
void sceKernelInternalMemoryGetModuleSegmentInfo();
// Empty Comment
int32_t sceKernelIsAuthenticNeo(void);
// Empty Comment
int32_t sceKernelIsCEX(void);
// Empty Comment
int32_t sceKernelIsDevKit(void);
// Empty Comment
int32_t sceKernelIsGenuineN(void);
// Empty Comment
int32_t sceKernelIsInSandbox(void);
// Empty Comment
int32_t sceKernelIsKratos(void);
// Empty Comment
int32_t sceKernelIsNeoMode(void);
// Empty Comment
int32_t sceKernelIsStack(void *, void **, void **);
// Empty Comment
int32_t sceKernelIsTestKit(void);
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
off_t sceKernelLseek(int32_t, off_t, int);
// Empty Comment
int32_t sceKernelLwfsAllocateBlock(int32_t, off_t);
// Empty Comment
off_t sceKernelLwfsLseek(int32_t, off_t, int);
// Empty Comment
int32_t sceKernelLwfsSetAttribute(int32_t, int);
// Empty Comment
ssize_t sceKernelLwfsWrite(int32_t, const void *, size_t);
// Empty Comment
int32_t sceKernelMapDirectMemory(void**, size_t, int32_t, int32_t, off_t, size_t);
// Empty Comment
int32_t sceKernelMapDirectMemory2(void **, size_t, int32_t, int32_t, int32_t, off_t, size_t);
// Empty Comment
int32_t sceKernelMapFlexibleMemory(void **, size_t, int32_t, int);
// Empty Comment
int32_t sceKernelMapNamedDirectMemory(void **, size_t, int32_t, int32_t, off_t, size_t, const char *);
// Empty Comment
int32_t sceKernelMapNamedFlexibleMemory(void **, size_t, int32_t, int32_t, const char *);
// Empty Comment
void sceKernelMapNamedSystemFlexibleMemory();
// Empty Comment
int32_t sceKernelMkdir(const char *path, OrbisKernelMode mode);
// Empty Comment
void sceKernelMlock();
// Empty Comment
void sceKernelMlockall();
// Empty Comment
int32_t sceKernelMmap(void *, size_t, int32_t, int32_t, int32_t, off_t, void **);
// Empty Comment
int32_t sceKernelMprotect(const void *, size_t, int);
// Empty Comment
int32_t sceKernelMsync(void *, size_t, int);
// Empty Comment
int32_t sceKernelMtypeprotect(const void *, size_t, int32_t, int);
// Empty Comment
void sceKernelMunlock();
// Empty Comment
void sceKernelMunlockall();
// Empty Comment
int32_t sceKernelMunmap(void *, size_t);
// Empty Comment
int32_t sceKernelNanosleep(const OrbisKernelTimespec *, OrbisKernelTimespec *);
// Empty Comment
int32_t sceKernelOpen(const char *, int32_t, OrbisKernelMode);
// Empty Comment
int32_t sceKernelOpenEventFlag(void* event, const char* name);
// Empty Comment
void sceKernelOpenSema();
// Empty Comment
int32_t sceKernelPollEventFlag(OrbisKernelEventFlag, uint64_t, uint32_t, uint64_t*);
// Empty Comment
int32_t sceKernelPollSema(OrbisKernelSema, int);
// Empty Comment
size_t sceKernelPread(int32_t, void *, size_t, off_t);
// Empty Comment
size_t sceKernelPreadv(int32_t, const OrbisKernelIovec *, int32_t, off_t);
// Empty Comment
void sceKernelPrintBacktraceWithModuleInfo();
// Empty Comment
size_t sceKernelPwrite(int32_t, const void *, size_t, off_t);
// Empty Comment
size_t sceKernelPwritev(int32_t, const OrbisKernelIovec *, int32_t, off_t);
// Empty Comment
int32_t sceKernelQueryMemoryProtection(void *, void **, void **, int32_t *);
// Empty Comment
void sceKernelRdup();
// Empty Comment
size_t sceKernelRead(int32_t, void *, size_t);
// Empty Comment
uint64_t sceKernelReadTsc(void);
// Empty Comment
size_t sceKernelReadv(int32_t, const OrbisKernelIovec *, int);
// Empty Comment
void sceKernelReboot();
// Empty Comment
int32_t sceKernelReleaseDirectMemory(off_t, size_t);
// Empty Comment
int32_t sceKernelReleaseFlexibleMemory(void *, size_t);
// Empty Comment
int32_t sceKernelRename(const char *oldfilename, const char *newfilename);
// Empty Comment
void sceKernelReportUnpatchedFunctionCall();
// Empty Comment
int32_t sceKernelReserveVirtualRange(void **, size_t, int32_t, size_t);
// Empty Comment
int32_t sceKernelRmdir(const char *folder);
// reverse engineered by flatz and OSM
int32_t sceKernelSendNotificationRequest(int32_t device, OrbisNotificationRequest* req, size_t size, int32_t blocking);
// Empty Comment
void sceKernelSetAppInfo();
// Empty Comment
void sceKernelSetBackupRestoreMode();
// Empty Comment
int32_t sceKernelSetCompressionAttribute(int32_t, int);
// Empty Comment
int32_t sceKernelSetEventFlag(OrbisKernelEventFlag, uint64_t);
// Empty Comment - 2nd arg is OrbisKernelCpumask (needs reversed)
int32_t sceKernelSetFsstParam(int32_t, void *);
// Empty Comment
void sceKernelSetGPI();
// Empty Comment
void sceKernelSetGPO();
// Empty Comment
void sceKernelSetProcessName();
// Empty Comment
int32_t sceKernelSetPrtAperture(int32_t, void *, size_t);
// Empty Comment
void sceKernelSetSafemode();
// Empty Comment
void sceKernelSettimeofday();
// Empty Comment
int32_t sceKernelSetVirtualRangeName(const void *, size_t, const char *);
// Empty Comment
void sceKernelSetVmContainer();
// Empty Comment
int32_t sceKernelSignalSema(OrbisKernelSema, int);
// Empty Comment
int32_t sceKernelSleep(uint32_t);
// Empty Comment
int32_t sceKernelStat(const char *, OrbisKernelStat *);
// Empty Comment
int32_t sceKernelStopUnloadModule(OrbisKernelModule, size_t, const void *, uint32_t, void *, int32_t *);
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
int32_t sceKernelTriggerUserEvent(OrbisKernelEqueue, int32_t, void*);
// Empty Comment
int32_t sceKernelTruncate(const char *, off_t);
// Empty Comment
int32_t sceKernelUnlink(const char *);
// Empty Comment
int32_t sceKernelUsleep(uint32_t);
// Empty Comment
int32_t sceKernelUtimes(const char *, const OrbisKernelTimeval *);
// Empty Comment
int32_t sceKernelUuidCreate(OrbisKernelUuid*);
// Empty Comment
int32_t sceKernelVirtualQuery(const void *, int32_t, OrbisKernelVirtualQueryInfo *, size_t);
// Empty Comment
int32_t sceKernelWaitEqueue(OrbisKernelEqueue, OrbisKernelEvent*, int32_t, int32_t*, OrbisKernelUseconds*);
// Empty Comment
int32_t sceKernelWaitEventFlag(OrbisKernelEventFlag, uint64_t, uint32_t, uint64_t*, OrbisKernelUseconds*);
// Empty Comment
int32_t sceKernelWaitSema(OrbisKernelSema, int32_t, OrbisKernelUseconds*);
// Empty Comment
size_t sceKernelWrite(int32_t, const void *, size_t);
// Empty Comment
size_t sceKernelWritev(int32_t, const OrbisKernelIovec *);
// Empty Comment
void sceLibcMspaceCreateForMonoMutex();
// Empty Comment
void scePthreadAtfork();
// Empty Comment
int32_t scePthreadAttrDestroy(OrbisPthreadAttr*);
// Empty Comment
int32_t scePthreadAttrGet(OrbisPthread, OrbisPthreadAttr*);
// Empty Comment
int32_t scePthreadAttrGetaffinity(const OrbisPthreadAttr*, void*);
// void* is OrbisKernelCpumask, need to port OrbisKernelCpumask for above.. -cv
// Empty Comment
int32_t scePthreadAttrGetdetachstate(const OrbisPthreadAttr*, int32_t*);
// Empty Comment
int32_t scePthreadAttrGetguardsize(const OrbisPthreadAttr*, size_t*);
// Empty Comment
void scePthreadAttrGetinheritsched();
// Empty Comment
void scePthreadAttrGetschedparam();
// Empty Comment
void scePthreadAttrGetschedpolicy();
// Empty Comment
void scePthreadAttrGetscope();
// Empty Comment
int32_t scePthreadAttrGetstack(const OrbisPthreadAttr* __restrict, void** __restrict, size_t* __restrict);
// Empty Comment
int32_t scePthreadAttrGetstackaddr(const OrbisPthreadAttr*, void**);
// Empty Comment
int32_t scePthreadAttrGetstacksize(const OrbisPthreadAttr*, size_t*);
// Empty Comment
int32_t scePthreadAttrInit(OrbisPthreadAttr*);
// Empty Comment
int32_t scePthreadAttrSetaffinity(OrbisPthreadAttr*, uint64_t);
// void (2nd arg) is OrbisKernelCpumask, need to por OrbisKernelCpumask -cv
// Empty Comment
void scePthreadAttrSetcreatesuspend();
// Empty Comment
int32_t scePthreadAttrSetdetachstate(OrbisPthreadAttr*, int);
// Empty Comment
int32_t scePthreadAttrSetguardsize(OrbisPthreadAttr*, size_t);
// Empty Comment
void scePthreadAttrSetinheritsched(OrbisPthreadAttr*, int);
// Empty Comment
void scePthreadAttrSetschedparam(OrbisPthreadAttr*, struct sched_param*);
// Empty Comment
void scePthreadAttrSetschedpolicy();
// Empty Comment
void scePthreadAttrSetscope();
// Empty Comment
int32_t scePthreadAttrSetstack(OrbisPthreadAttr*, void*, size_t);
// Empty Comment
int32_t scePthreadAttrSetstackaddr(OrbisPthreadAttr*, void*);
// Empty Comment
int32_t scePthreadAttrSetstacksize(OrbisPthreadAttr*, size_t);
// Empty Comment
int32_t scePthreadBarrierattrDestroy(OrbisPthreadBarrierattr*);
// Empty Comment
void scePthreadBarrierattrGetpshared();
// Empty Comment
int32_t scePthreadBarrierattrInit(OrbisPthreadBarrierattr*);
// Empty Comment
void scePthreadBarrierattrSetpshared();
// Empty Comment
int32_t scePthreadBarrierDestroy(OrbisPthreadBarrier*);
// Empty Comment
int32_t scePthreadBarrierInit(OrbisPthreadBarrier*, const OrbisPthreadBarrierattr*, unsigned, const char*);
// Empty Comment
int32_t scePthreadBarrierWait(OrbisPthreadBarrier*);
// Empty Comment
int32_t scePthreadCancel(OrbisPthread);
// Empty Comment
int32_t scePthreadCondattrDestroy(OrbisPthreadCondattr*);
// Empty Comment
void scePthreadCondattrGetclock();
// Empty Comment
void scePthreadCondattrGetpshared();
// Empty Comment
int32_t scePthreadCondattrInit(OrbisPthreadCondattr*);
// Empty Comment
void scePthreadCondattrSetclock();
// Empty Comment
void scePthreadCondattrSetpshared();
// Empty Comment
int32_t scePthreadCondBroadcast(OrbisPthreadCond*);
// Empty Comment
int32_t scePthreadCondDestroy(OrbisPthreadCond*);
// Empty Comment
int32_t scePthreadCondInit(OrbisPthreadCond*, const OrbisPthreadCondattr*, const char*);
// Empty Comment
int32_t scePthreadCondSignal(OrbisPthreadCond*);
// Empty Comment
int32_t scePthreadCondSignalto(OrbisPthreadCond*, OrbisPthread);
// Empty Comment
int32_t scePthreadCondTimedwait(OrbisPthreadCond*, OrbisPthreadMutex*, OrbisKernelUseconds);
// Empty Comment
int32_t scePthreadCondWait(OrbisPthreadCond*, OrbisPthreadMutex*);
// Empty Comment
int32_t scePthreadCreate(OrbisPthread *, const OrbisPthreadAttr *, void*(*F)(void*), void *, const char *);
// Empty Comment
int32_t scePthreadDetach(OrbisPthread);
// Empty Comment
int32_t scePthreadEqual(OrbisPthread, OrbisPthread);
// Empty Comment
void scePthreadExit(void*);
// Empty Comment
void scePthreadGetaffinity(OrbisPthread, uint64_t*);
// Empty Comment
void scePthreadGetconcurrency();
// Empty Comment
int32_t scePthreadGetcpuclockid(OrbisPthread, clockid_t*);
// Empty Comment
int32_t scePthreadGetname(OrbisPthread, char*);
// Empty Comment
int32_t scePthreadGetprio(OrbisPthread, int32_t*);
// Empty Comment
void scePthreadGetschedparam();
// Empty Comment
void* scePthreadGetspecific(OrbisPthreadKey);
// Empty Comment
int32_t scePthreadGetthreadid(void);
// Empty Comment
int32_t scePthreadJoin(OrbisPthread, void**);
// Empty Comment
int32_t scePthreadKeyCreate(OrbisPthreadKey*, void(*destructor)(void*));
// Empty Comment
int32_t scePthreadKeyDelete(OrbisPthreadKey);
// Empty Comment
void scePthreadMain();
// Empty Comment
void scePthreadMulti();
// Empty Comment
int32_t scePthreadMutexattrDestroy(OrbisPthreadMutexattr*);
// Empty Comment
void scePthreadMutexattrGetkind();
// Empty Comment
int32_t scePthreadMutexattrGetprioceiling(OrbisPthreadMutexattr*, int32_t*);
// Empty Comment
int32_t scePthreadMutexattrGetprotocol(OrbisPthreadMutexattr*, int32_t*);
// Empty Comment
void scePthreadMutexattrGetpshared();
// Empty Comment
int32_t scePthreadMutexattrGettype(OrbisPthreadMutexattr*, int32_t*);
// Empty Comment
int32_t scePthreadMutexattrInit(OrbisPthreadMutexattr*);
// Empty Comment
void scePthreadMutexattrSetkind();
// Empty Comment
int32_t scePthreadMutexattrSetprioceiling(OrbisPthreadMutexattr*, int);
// Empty Comment
int32_t scePthreadMutexattrSetprotocol(OrbisPthreadMutexattr*, int);
// Empty Comment
void scePthreadMutexattrSetpshared();
// Empty Comment
int32_t scePthreadMutexattrSettype(OrbisPthreadMutexattr*, int);
// Empty Comment
int32_t scePthreadMutexDestroy(OrbisPthreadMutex*);
// Empty Comment
int32_t scePthreadMutexGetprioceiling(OrbisPthreadMutex*, int32_t*);
// Empty Comment
void scePthreadMutexGetspinloops();
// Empty Comment
void scePthreadMutexGetyieldloops();
// Empty Comment
int32_t scePthreadMutexInit(OrbisPthreadMutex*, const OrbisPthreadMutexattr*, const char*);
// Empty Comment
void scePthreadMutexIsowned();
// Empty Comment
int32_t scePthreadMutexLock(OrbisPthreadMutex*);
// Empty Comment
int32_t scePthreadMutexSetprioceiling(OrbisPthreadMutex*, int32_t, int32_t*);
// Empty Comment
void scePthreadMutexSetspinloops();
// Empty Comment
void scePthreadMutexSetyieldloops();
// Empty Comment
int32_t scePthreadMutexTimedlock(OrbisPthreadMutex*, OrbisKernelUseconds);
// Empty Comment
int32_t scePthreadMutexTrylock(OrbisPthreadMutex*);
// Empty Comment
int32_t scePthreadMutexUnlock(OrbisPthreadMutex*);
// Empty Comment
int32_t scePthreadOnce(OrbisPthreadOnce*, void(*init)(void));
// Empty Comment
int32_t scePthreadRename(OrbisPthread, const char*);
// Empty Comment
void scePthreadResume();
// Empty Comment
void scePthreadResumeAll();
// Empty Comment
int32_t scePthreadRwlockattrDestroy(OrbisPthreadRwlockattr*);
// Empty Comment
void scePthreadRwlockattrGetpshared();
// Empty Comment
int32_t scePthreadRwlockattrInit(OrbisPthreadRwlockattr*);
// Empty Comment
void scePthreadRwlockattrSetpshared();
// Empty Comment
int32_t scePthreadRwlockDestroy(OrbisPthreadRwlock*);
// Empty Comment
int32_t scePthreadRwlockInit(OrbisPthreadRwlock*, const OrbisPthreadRwlockattr*, const char*);
// Empty Comment
int32_t scePthreadRwlockRdlock(OrbisPthreadRwlock*);
// Empty Comment
int32_t scePthreadRwlockTimedrdlock(OrbisPthreadRwlock*, OrbisKernelUseconds);
// Empty Comment
int32_t scePthreadRwlockTimedwrlock(OrbisPthreadRwlock*, OrbisKernelUseconds);
// Empty Comment
int32_t scePthreadRwlockTryrdlock(OrbisPthreadRwlock*);
// Empty Comment
int32_t scePthreadRwlockTrywrlock(OrbisPthreadRwlock*);
// Empty Comment
int32_t scePthreadRwlockUnlock(OrbisPthreadRwlock*);
// Empty Comment
int32_t scePthreadRwlockWrlock(OrbisPthreadRwlock*);
// Empty Comment
OrbisPthread scePthreadSelf();
// Empty Comment
void scePthreadSetaffinity();
// Empty Comment
void scePthreadSetBesteffort();
// Empty Comment
int32_t scePthreadSetcancelstate(int32_t, int32_t*);
// Empty Comment
int32_t scePthreadSetcanceltype(int32_t, int32_t*);
// Empty Comment
void scePthreadSetconcurrency();
// Empty Comment
void scePthreadSetName();
// Empty Comment
int32_t scePthreadSetprio(OrbisPthread, int);
// Empty Comment
void scePthreadSetschedparam();
// Empty Comment
int32_t scePthreadSetspecific(OrbisPthreadKey, const void*);
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
// This is a redeclaration of the one used by FreeBSD, do not change this.
int ioctl(int fd, unsigned long request, ...);

#ifdef __cplusplus
}
#endif

#endif
