/*-
 * OpenOrbis PS4 Toolchain - SCE Pad (Controller)
 * -
 * This file contains objects and functions for interfacing with the DualShock 4 (DS4) controller.
 *
 * Special thanks to bigboss (psxdev) for reversing some of these.
 */

#ifndef _SCE_PAD_H_
#define _SCE_PAD_H_

#include <stdint.h>
#include <orbis/_types/pad.h>
#include <orbis/_types/errors.h>


#ifdef __cplusplus 
extern "C" {
#endif


int32_t scePadInit(void);
int32_t scePadOpen(int32_t userID, int32_t type, int32_t index, void *param);
int32_t scePadOpenExt(int32_t userID, int32_t type, int32_t index, OrbisPadExtParam *param);
int32_t scePadClose(int32_t handle);
int32_t scePadRead(int32_t handle, OrbisPadData *data, int32_t count);
int32_t scePadReadState(int32_t handle, OrbisPadData *data);
int32_t scePadResetLightBar(int32_t handle);
int32_t scePadSetLightBar(int32_t handle, OrbisPadColor *inputColor);
int32_t scePadGetControllerInformation(int32_t handle, OrbisPadInformation *info);
int32_t scePadGetExtControllerInformation(int32_t handle, OrbisPadInformation *info);
int32_t scePadGetHandle(int32_t userID, uint32_t controller_type, uint32_t controller_index);
int32_t scePadResetOrientation(int32_t handle);
int32_t scePadSetVibration(int32_t handle, const OrbisPadVibeParam *param);
int32_t scePadOutputReport(int32_t handle, int32_t type, uint8_t *report, int32_t length);

// The below functions are currently not reversed
void scePadConnectPort();
void scePadDeviceClassGetExtendedInformation();
void scePadDeviceClassParseData();
void scePadDeviceOpen();
void scePadDisableVibration();
void scePadDisconnectDevice();
void scePadDisconnectPort();
void scePadEnableAutoDetect();
void scePadEnableExtensionPort();
void scePadEnableSpecificDeviceClass();
void scePadEnableUsbConnection();
void scePadGetBluetoothAddress();
void scePadGetCapability();
void scePadGetDataInternal();
void scePadGetDeviceId();
void scePadGetDeviceInfo();
void scePadGetExtensionUnitInfo();
void scePadGetFeatureReport();
void scePadGetIdleCount();
void scePadGetInfo();
void scePadGetInfoByPortType();
void scePadGetLicenseControllerInformation();
void scePadGetMotionSensorPosition();
void scePadGetMotionTimerUnit();
void scePadGetSphereRadius();
void scePadGetVersionInfo();
void scePadIsBlasterConnected();
void scePadIsDS4Connected();
void scePadIsLightBarBaseBrightnessControllable();
void scePadIsMoveConnected();
void scePadIsMoveReproductionModel();
void scePadIsValidHandle();
void scePadMbusInit();
void scePadMbusTerm();
void scePadOpenExt2();
void scePadReadBlasterForTracker();
int scePadReadExt(int handle, OrbisPadData* data, int count);
void scePadReadForTracker();
void scePadReadHistory();
int scePadReadStateExt(int handle, OrbisPadData* data);
void scePadResetLightBarAll();
void scePadResetLightBarAllByPortType();
void scePadResetOrientationForTracker();
void scePadSetAngularVelocityDeadbandState();
void scePadSetAutoPowerOffCount();
void scePadSetButtonRemappingInfo();
void scePadSetConnection();
void scePadSetExtensionReport();
void scePadSetFeatureReport();
void scePadSetForceIntercepted();
void scePadSetLightBarBaseBrightness();
void scePadSetLightBarBlinking();
void scePadSetLightBarForTracker();
void scePadSetLoginUserNumber();
void scePadSetMotionSensorState();
void scePadSetProcessFocus();
void scePadSetProcessPrivilege();
void scePadSetProcessPrivilegeOfButtonRemapping();
void scePadSetTiltCorrectionState();
void scePadSetUserColor();
void scePadSetVibrationForce();
void scePadSetVrTrackingMode();
void scePadShareOutputData();
void scePadStartRecording();
void scePadStopRecording();
void scePadSwitchConnection();
void scePadVertualDeviceAddDevice();
void scePadVirtualDeviceAddDevice();
void scePadVirtualDeviceDeleteDevice();
void scePadVirtualDeviceGetRemoteSetting();
void scePadVirtualDeviceInsertData();

#ifdef __cplusplus
}
#endif
#endif
