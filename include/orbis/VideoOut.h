#ifndef _ORBIS_VIDEO_OUT_H_
#define _ORBIS_VIDEO_OUT_H_

#include <stdint.h>
#include <orbis/_types/kernel.h>
#include <orbis/_types/user.h>
#include <orbis/_types/video.h>
#include <orbis/_types/errors.h>

#ifdef __cplusplus 
extern "C" {
#endif

int sceVideoOutOpen(OrbisUserServiceUserId, int, int, const void *);
int sceVideoOutClose(int);
// need to port sceVideoOutBufferAttribute (last arg)
int sceVideoOutRegisterBuffers(int, int, void * const *, int, const OrbisVideoOutBufferAttribute *);
int sceVideoOutUnregisterBuffers(int, int);
int sceVideoOutSubmitFlip(int, int, unsigned int, int64_t);
void sceVideoOutSetBufferAttribute(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// limits framerate in application
// 0 none
// 1 33ms - 30FPS
// 2 50ms - 20FPS
int sceVideoOutSetFlipRate(int handle, int fliprate);
int sceVideoOutAddFlipEvent(OrbisKernelEqueue, int, void *);
int sceVideoOutGetFlipStatus(int, OrbisVideoOutFlipStatus *);
int sceVideoOutIsFlipPending(int);
int sceVideoOutGetResolutionStatus(int, OrbisVideoOutResolutionStatus *status);

void sceVideoOutAddBuffer();
void sceVideoOutAddBuffer4k2kPrivilege();
void sceVideoOutAddBufferYccPrivilege();
void sceVideoOutAddDisplayPositionEvent();
void sceVideoOutAddDriver();
void sceVideoOutAddPreVblankStartEvent();
void sceVideoOutAddS3dHmdPrivilege();
void sceVideoOutAddSetModeEvent();
void sceVideoOutAddStereoBuffer();
void sceVideoOutAddVblankEvent();
void sceVideoOutAdjustColor_();
void sceVideoOutColorSettingsSetGamma_();
void sceVideoOutConfigureOptionsInitialize_();
void sceVideoOutConfigureOutputMode_();
void sceVideoOutConfigureOutputModeEx_();
void sceVideoOutConfigureOutputModeExSubmitDoneUnsafe_();
void sceVideoOutControlHdcpEncryption();
void sceVideoOutCursorDisable();
void sceVideoOutCursorEnable();
void sceVideoOutCursorIsUpdatePending();
void sceVideoOutCursorSet2xMagnify();
void sceVideoOutCursorSetHotSpot();
void sceVideoOutCursorSetImageAddress();
void sceVideoOutCursorSetPosition();
void sceVideoOutCursorSetPositionStereo();
void sceVideoOutCurveSamplePointsCalc_();
void sceVideoOutDeleteDisplayPositionEvent();
void sceVideoOutDeleteDriver();
void sceVideoOutDeleteFlipEvent();
void sceVideoOutDeletePreVblankStartEvent();
void sceVideoOutDeleteSetModeEvent();
void sceVideoOutDeleteVblankEvent();
void sceVideoOutDriverAddEvent();
void sceVideoOutDriverDecrementBufferLabel();
void sceVideoOutDriverDeleteEvent();
void sceVideoOutDriverGetBufferLabelAddress();
void sceVideoOutDriverGetEopHandle();
void sceVideoOutDriverGetFinishedEopHandle();
void sceVideoOutDriverGetLatestEopHandle();
void sceVideoOutDriverIncrementBufferLabel();
void sceVideoOutDriverResetBufferLabel();
void sceVideoOutDriverTriggerEvent();
void sceVideoOutGetBufferInformation();
void sceVideoOutGetBufferLabelAddress();
void sceVideoOutGetCoredumpOutputMode();
void sceVideoOutGetCurrentOutputMode_();
void sceVideoOutGetDeviceCapabilityInfo_();
void sceVideoOutGetDeviceInfoEx_();
void sceVideoOutGetDeviceInfoExOts_();
void sceVideoOutGetEventCount();
void sceVideoOutGetEventData();
void sceVideoOutGetEventId();
void sceVideoOutGetHdmiKsvList_();
void sceVideoOutGetHdmiMonitorInfo_();
void sceVideoOutGetHdmiMonitorInfoNoMask_();
void sceVideoOutGetPortStatusInfo_();
void sceVideoOutGetPortStatusInfoByBusSpecifier_();
void sceVideoOutGetStatusForWebcore();
void sceVideoOutGetVblankStatus();
void sceVideoOutGetVideoOutModeByBusSpecifier_();
void sceVideoOutHdmiMonitorInfoIsSupportedHdcpVersion_();
void sceVideoOutHdmiMonitorInfoIsSupportedVideoOutMode_();
void sceVideoOutLockBuffer();
void sceVideoOutModeSetAny_();
void sceVideoOutRazorAddCallback();
void sceVideoOutRazorRecallCallbacks();
void sceVideoOutRazorRemoveCallback();
void sceVideoOutRegisterBufferAttribute();
void sceVideoOutRegisterStereoBuffers();
void sceVideoOutRemoveBuffer();
void sceVideoOutSetBlankAfterResume();
void sceVideoOutSetDisplayEventPosition();
void sceVideoOutSetGamutMetadata_();
void sceVideoOutSetToneMap_();
void sceVideoOutSetWindowModeMargins();
void sceVideoOutSubmitChangeBufferAttribute();
void sceVideoOutSubmitEopFlip();
void sceVideoOutSysAddSetModeEvent();
void sceVideoOutSysAddVblankEvent();
void sceVideoOutSysClose();
void sceVideoOutSysConfigureOutputMode_();
void sceVideoOutSysCursorDisable();
void sceVideoOutSysCursorEnable();
void sceVideoOutSysCursorIsUpdatePending();
void sceVideoOutSysCursorObtain();
void sceVideoOutSysCursorRelease();
void sceVideoOutSysCursorSetPosition();
void sceVideoOutSysDeleteVblankEvent();
void sceVideoOutSysGetColorConversionStatus();
void sceVideoOutSysGetCurrentOutputMode_();
void sceVideoOutSysGetDeviceCapabilityInfoByBusSpecifier_();
void sceVideoOutSysGetFlipStatus();
void sceVideoOutSysGetMonitorInfo_();
void sceVideoOutSysGetPortStatusInfo_();
void sceVideoOutSysGetPortStatusInfoByBusSpecifier_();
void sceVideoOutSysGetResolutionStatus();
void sceVideoOutSysGetVblankStatus();
void sceVideoOutSysIsSupportedByMonitorInfo_();
void sceVideoOutSysReadCrc();
void sceVideoOutSysReadCrc64();
void sceVideoOutSysResetAtGpuReset();
void sceVideoOutSysResetZoomBuffers();
void sceVideoOutSysSetBlackLevel();
void sceVideoOutSysSetDcePipeMode();
void sceVideoOutSysSetDimmer();
void sceVideoOutSysSetDisplayParameters();
void sceVideoOutSysSetInvertedColors();
void sceVideoOutSysSetOutputCsc();
void sceVideoOutSysSetOverscanRatio();
void sceVideoOutSysSetZoomBuffers();
void sceVideoOutSysUpdateDisplayParameter_();
void sceVideoOutSysUpdatePrivilege();
void sceVideoOutSysUpdateRenderingMode();
void sceVideoOutSysUpdateScalerParameters();
void sceVideoOutUnlockBuffer();
void sceVideoOutUnregisterBufferAttribute();
void sceVideoOutWaitVblank();

#ifdef __cplusplus
}
#endif
#endif
