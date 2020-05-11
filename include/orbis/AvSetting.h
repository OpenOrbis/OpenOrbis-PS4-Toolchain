#ifndef _SCE_AV_SETTING_H_
#define _SCE_AV_SETTING_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceAvSettingAddCallbacksForLnc();
// Empty Comment
void sceAvSettingChangeOutputMode();
// Empty Comment
void sceAvSettingChangeOutputMode2();
// Empty Comment
void sceAvSettingChangeOutputMode3();
// Empty Comment
void sceAvSettingDriverChangeConnectionStatus();
// Empty Comment
void sceAvSettingGetCurrentHdmiDeviceId();
// Empty Comment
void sceAvSettingGetDetailedHdcpStatus();
// Empty Comment
void sceAvSettingGetDeviceInfo();
// Empty Comment
void sceAvSettingGetHdmiMonitorInfo();
// Empty Comment
void sceAvSettingGetMorpheusPuStatus();
// Empty Comment
void sceAvSettingInit();
// Empty Comment
void sceAvSettingIsSupportedVideoOutModeByHdmiMonitorInfo();
// Empty Comment
void sceAvSettingIsSuspendedProcessOutputModeAvailable();
// Empty Comment
void sceAvSettingIsSuspendedProcessOutputModeAvailable2();
// Empty Comment
void sceAvSettingNotifyAudioOutMode();
// Empty Comment
void sceAvSettingNotifyVideoOutMode();
// Empty Comment
void sceAvSettingRemoveProcessOutputMode();
// Empty Comment
void sceAvSettingSetVideoOutputColorEffect();

#endif

#ifdef __cplusplus
}
#endif