#ifndef _SCE_SYSTEM_SERVICE_H_
#define _SCE_SYSTEM_SERVICE_H_

#include <stddef.h>
#include <stdint.h>
#include "_types/sys_service.h"

#ifdef __cplusplus 
extern "C"
{
#endif

int32_t sceSystemServiceLoadExec(const char *path, const char *args[]);
int32_t sceSystemServiceShowControllerSettings();
int32_t sceSystemServiceParamGetInt(int32_t paramId, int32_t *value);
int32_t sceSystemServiceParamGetString(int32_t paramId, char *buf, size_t bufSize);
int32_t sceSystemServiceHideSplashScreen();
int32_t sceSystemServiceEnablePersonalEyeToEyeDistanceSetting();
int32_t sceSystemServiceDisablePersonalEyeToEyeDistanceSetting();
int32_t sceSystemServiceShowEyeToEyeDistanceSetting();
int32_t sceSystemServiceIsEyeToEyeDistanceAdjusted(int32_t, bool*);
int32_t sceSystemServiceReportAbnormalTermination(void*);
int32_t sceSystemServiceDisableSuspendConfirmationDialog();
int32_t sceSystemServiceEnableSuspendConfirmationDialog();
int32_t sceSystemServicePowerTick();
int32_t sceSystemServiceLaunchTournamentsTeamProfile(int32_t, const char*, const char*, const char*);
int32_t sceSystemServiceLaunchEventDetails(int32_t, const char*);
int32_t sceSystemServiceLaunchWebBrowser(const char*, OrbisSystemServiceLaunchWebBrowserParam*);
int32_t sceSystemServiceShowDisplaySafeAreaSettings();
int32_t sceSystemServiceGetDisplaySafeAreaInfo(OrbisSystemServiceDisplaySafeAreaInfo*);
OrbisSystemServiceGpuLoadEmulationMode sceSystemServiceGetGpuLoadEmulationMode();
int32_t sceSystemServiceSetGpuLoadEmulationMode(OrbisSystemServiceGpuLoadEmulationMode);
int32_t sceSystemServiceReenableMusicPlayer();
int32_t sceSystemServiceDisableMusicPlayer();
int32_t sceSystemServiceGetStatus(OrbisSystemServiceStatus*);
int32_t sceSystemServiceReceiveEvent(OrbisSystemServiceEvent*);
int32_t sceSystemServiceHideSplashScreen(void);
int32_t sceSystemServiceParamGetInt(int32_t paramId, int32_t *value);
int32_t sceSystemServiceParamGetString(int32_t paramId, char *buf, size_t bufSize);
int32_t sceSystemServiceGetAppIdOfBigApp(void);
int32_t sceSystemServiceGetAppIdOfMiniApp(void);
int32_t sceSystemServiceKillApp(uint32_t appid, int opt, int method, int reason);

void sceSystemServiceAcquireFb0();
void sceSystemServiceAddLocalProcess();
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
void sceSystemServiceGetAppFocusedAppStatus();
void sceSystemServiceGetAppStatus();
void sceSystemServiceGetAppType();
void sceSystemServiceGetEventForDaemon();
void sceSystemServiceGetLocalProcessStatusList();
void sceSystemServiceGetParentSocket();
void sceSystemServiceGetParentSocketForPsmKit();
void sceSystemServiceGetPSButtonEvent();
void sceSystemServiceGetRenderingMode();
void sceSystemServiceGetTitleWorkaroundInfo();
void sceSystemServiceGetVersionNumberOfCameraCalibrationData();
void sceSystemServiceIsAppSuspended();
void sceSystemServiceIsBgmPlaying();
void sceSystemServiceIsScreenSaverOn();
void sceSystemServiceIsShellUiFgAndGameBgCpuMode();
void sceSystemServiceKillLocalProcess();
void sceSystemServiceKillLocalProcessForPsmKit();
void sceSystemServiceLaunchApp();
void sceSystemServiceNavigateToAnotherApp();
void sceSystemServiceNavigateToGoBack();
void sceSystemServiceNavigateToGoBackWithValue();
void sceSystemServiceNavigateToGoHome();
void sceSystemServiceRaiseExceptionLocalProcess();
void sceSystemServiceRegisterDaemon();
void sceSystemServiceReleaseFb0();
void sceSystemServiceRequestCameraCalibration();
void sceSystemServiceRequestToChangeRenderingMode();
void sceSystemServiceResumeLocalProcess();
void sceSystemServiceSetControllerFocusPermission();
void sceSystemServiceSetOutOfVrPlayAreaFlag();
void sceSystemServiceSetOutOfVrPlayZoneWarning();
void sceSystemServiceSuspendBackgroundApp();
void sceSystemServiceSuspendLocalProcess();
void sceSystemServiceTickVideoPlayback();
void sceSystemServiceTurnOffScreenSaver();

#ifdef __cplusplus
}
#endif
#endif