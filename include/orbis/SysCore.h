#ifndef _SCE_SYS_CORE_H_
#define _SCE_SYS_CORE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void _sceApplicationGetAppId();
// Empty Comment
void sceApplicationAddProcess2();
// Empty Comment
void sceApplicationBlockingKill2();
// Empty Comment
void sceApplicationContinue();
// Empty Comment
void sceApplicationCrashSyscore();
// Empty Comment
void sceApplicationExitSpawn();
// Empty Comment
void sceApplicationExitSpawn2();
// Empty Comment
void sceApplicationFinalize();
// Empty Comment
void sceApplicationGetAppInfoByAppId();
// Empty Comment
void sceApplicationGetCoredumpDirAndFileName();
// Empty Comment
void sceApplicationGetCoredumpState();
// Empty Comment
void sceApplicationGetProcs();
// Empty Comment
void sceApplicationGetShellCoreAppId();
// Empty Comment
void sceApplicationInitialize();
// Empty Comment
void sceApplicationInitializeForShellCore();
// Empty Comment
void sceApplicationIsPrimaryProcess();
// Empty Comment
void sceApplicationIsResumable();
// Empty Comment
void sceApplicationKickCoredump();
// Empty Comment
void sceApplicationKickCoredump2();
// Empty Comment
void sceApplicationLocalProcessKill();
// Empty Comment
void sceApplicationLocalProcessKill2();
// Empty Comment
void sceApplicationLocalProcessResume();
// Empty Comment
void sceApplicationLocalProcessSuspend();
// Empty Comment
void sceApplicationNotifyCoredumpRequestEnd();
// Empty Comment
void sceApplicationNotifyCoredumpRequestProgress();
// Empty Comment
void sceApplicationNotifyVshMainOnStandby();
// Empty Comment
void sceApplicationNotifyVshReady();
// Empty Comment
void sceApplicationRaiseException();
// Empty Comment
void sceApplicationRaiseExceptionToLocalPid();
// Empty Comment
void sceApplicationResume();
// Empty Comment
void sceApplicationSendDebugSpawnResult2();
// Empty Comment
void sceApplicationSendResultOfDebuggerKillRequest();
// Empty Comment
void sceApplicationSendResultOfDebuggerResumeRequest();
// Empty Comment
void sceApplicationSendResultOfDebuggerSuspendRequest();
// Empty Comment
void sceApplicationSendResultOfDebuggerTitleIdLaunchRequest();
// Empty Comment
void sceApplicationSetApplicationFocus();
// Empty Comment
void sceApplicationSetControllerFocus();
// Empty Comment
void sceApplicationSetControllerFocusPermissionToSubProcess();
// Empty Comment
void sceApplicationSetMemoryPstate();
// Empty Comment
void sceApplicationSignalShellCoreHeartBeat();
// Empty Comment
void sceApplicationSuspend();
// Empty Comment
void sceApplicationSwitchToBaseMode();
// Empty Comment
void sceApplicationSwitchToNeoMode();
// Empty Comment
void sceApplicationSwitchToNeoMode2();
// Empty Comment
void sceApplicationSystemReboot();
// Empty Comment
void sceApplicationSystemShutdown2();
// Empty Comment
void sceApplicationSystemSuspend();
// Empty Comment
void sceSysCoreReceiveEvent();


#endif

#ifdef __cplusplus
}
#endif