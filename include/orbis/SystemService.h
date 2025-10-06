#ifndef _SCE_SYSTEM_SERVICE_H_
#define _SCE_SYSTEM_SERVICE_H_

#include <stddef.h>
#include <stdint.h>
#include <orbis/_types/sys_service.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceSystemServiceHideSplashScreen(void);
int32_t sceSystemServiceParamGetInt(int32_t paramId, int32_t *value);
int32_t sceSystemServiceParamGetString(int32_t paramId, char *buf, size_t bufSize);
int32_t sceSystemServiceGetAppIdOfBigApp(void);
int32_t sceSystemServiceGetAppIdOfMiniApp(void);
int32_t sceLncUtilLaunchApp(const char* title_id, const char* argv[], LncAppParam* param);
int32_t sceSystemServiceKillApp(uint32_t appid, int32_t opt, int32_t method, int32_t reason);
void sceSystemServiceAcquireFb0();
int32_t sceSystemServiceAddLocalProcess(int app_id, const char* eboot_path, int param_size, const char* args[]);
void sceSystemServiceAddLocalProcessForPsmKit();
void sceSystemServiceChangeAcpClock();
void sceSystemServiceChangeCpuClock();
void sceSystemServiceChangeGpuClock();
void sceSystemServiceChangeMemoryClock();
void sceSystemServiceChangeMemoryClockToBaseMode();
void sceSystemServiceChangeMemoryClockToDefault();
void sceSystemServiceChangeMemoryClockToMultiMediaMode();
void sceSystemServiceChangeNumberOfGpuCu();
void sceSystemServiceChangeSamuClock();
void sceSystemServiceChangeUvdClock();
void sceSystemServiceChangeVceClock();
void sceSystemServiceDisableMusicPlayer();
void sceSystemServiceDisablePersonalEyeToEyeDistanceSetting();
void sceSystemServiceDisableSuspendConfirmationDialog();
void sceSystemServiceEnablePersonalEyeToEyeDistanceSetting();
void sceSystemServiceEnableSuspendConfirmationDialog();
void sceSystemServiceGetAppFocusedAppStatus();
void sceSystemServiceGetAppStatus();
void sceSystemServiceGetAppType();
void sceSystemServiceGetDisplaySafeAreaInfo();
void sceSystemServiceGetEventForDaemon();
void sceSystemServiceGetGpuLoadEmulationMode();
void sceSystemServiceGetLocalProcessStatusList();
void sceSystemServiceGetParentSocket();
void sceSystemServiceGetParentSocketForPsmKit();
void sceSystemServiceGetPSButtonEvent();
void sceSystemServiceGetRenderingMode();
void sceSystemServiceGetStatus();
void sceSystemServiceGetTitleWorkaroundInfo();
void sceSystemServiceGetVersionNumberOfCameraCalibrationData();
void sceSystemServiceIsAppSuspended();
void sceSystemServiceIsBgmPlaying();
void sceSystemServiceIsEyeToEyeDistanceAdjusted();
void sceSystemServiceIsScreenSaverOn();
void sceSystemServiceIsShellUiFgAndGameBgCpuMode();
void sceSystemServiceKillLocalProcess();
void sceSystemServiceKillLocalProcessForPsmKit();
int32_t sceSystemServiceLaunchApp(const char* title_id, const char* argv[], LncAppParam* param);
void sceSystemServiceLaunchEventDetails();
void sceSystemServiceLaunchTournamentsTeamProfile();
void sceSystemServiceLaunchWebBrowser();
int32_t sceSystemServiceLoadExec(const char *path, const char *args[]);
void sceSystemServiceNavigateToAnotherApp();
void sceSystemServiceNavigateToGoBack();
void sceSystemServiceNavigateToGoBackWithValue();
void sceSystemServiceNavigateToGoHome();
void sceSystemServicePowerTick();
void sceSystemServiceRaiseExceptionLocalProcess();
void sceSystemServiceReceiveEvent();
void sceSystemServiceReenableMusicPlayer();
int32_t sceSystemServiceRegisterDaemon();
void sceSystemServiceReleaseFb0();
void sceSystemServiceReportAbnormalTermination();
void sceSystemServiceRequestCameraCalibration();
void sceSystemServiceRequestToChangeRenderingMode();
void sceSystemServiceResumeLocalProcess();
void sceSystemServiceSetControllerFocusPermission();
void sceSystemServiceSetGpuLoadEmulationMode();
void sceSystemServiceSetOutOfVrPlayAreaFlag();
void sceSystemServiceSetOutOfVrPlayZoneWarning();
void sceSystemServiceShowControllerSettings();
void sceSystemServiceShowDisplaySafeAreaSettings();
void sceSystemServiceShowEyeToEyeDistanceSetting();
void sceSystemServiceSuspendBackgroundApp();
void sceSystemServiceSuspendLocalProcess();
void sceSystemServiceTickVideoPlayback();
void sceSystemServiceTurnOffScreenSaver();

bool sceSystemStateMgrIsStandbyModeEnabled(); 
int sceSystemStateMgrGetTriggerCode();
int sceSystemStateMgrWakeUp(enum TriggerCode trigger);
int sceSystemStateMgrReboot();
int sceSystemStateMgrTurnOff();
int sceSystemStateMgrEnterStandby();
int sceSystemStateMgrGetCurrentState(); 

#ifdef __cplusplus
}
#endif

#endif
