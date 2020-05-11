#ifndef _SCE_SYSTEM_SERVICE_H_
#define _SCE_SYSTEM_SERVICE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceSystemServiceHideSplashScreen();

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
void sceSystemServiceDisableMusicPlayer();
void sceSystemServiceDisablePersonalEyeToEyeDistanceSetting();
void sceSystemServiceDisableSuspendConfirmationDialog();
void sceSystemServiceEnablePersonalEyeToEyeDistanceSetting();
void sceSystemServiceEnableSuspendConfirmationDialog();
void sceSystemServiceGetAppFocusedAppStatus();
void sceSystemServiceGetAppIdOfBigApp();
void sceSystemServiceGetAppIdOfMiniApp();
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
void sceSystemServiceKillApp();
void sceSystemServiceKillLocalProcess();
void sceSystemServiceKillLocalProcessForPsmKit();
void sceSystemServiceLaunchApp();
void sceSystemServiceLaunchEventDetails();
void sceSystemServiceLaunchTournamentsTeamProfile();
void sceSystemServiceLaunchWebBrowser();
void sceSystemServiceLoadExec();
void sceSystemServiceNavigateToAnotherApp();
void sceSystemServiceNavigateToGoBack();
void sceSystemServiceNavigateToGoBackWithValue();
void sceSystemServiceNavigateToGoHome();
void sceSystemServiceParamGetInt();
void sceSystemServiceParamGetString();
void sceSystemServicePowerTick();
void sceSystemServiceRaiseExceptionLocalProcess();
void sceSystemServiceReceiveEvent();
void sceSystemServiceReenableMusicPlayer();
void sceSystemServiceRegisterDaemon();
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



#endif

#ifdef __cplusplus
}
#endif