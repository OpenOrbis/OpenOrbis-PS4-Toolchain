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


#ifdef __cplusplus 
extern "C" {
#endif


int scePadInit(void);
int scePadOpen(int userID, int type, int index, void *param);
int scePadClose(int handle);
int scePadRead(int handle, OrbisPadData *data, int count);
int scePadReadState(int handle, void *data);
int scePadResetLightBar(int handle);
int scePadSetLightBar(int handle, OrbisPadColor *inputColor);
int scePadGetHandle(int userID, uint32_t controller_type, uint32_t controller_index);
int scePadResetOrientation(int handle);
int scePadSetVibration(int handle, const OrbisPadVibeParam *param);

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
void scePadGetControllerInformation();
void scePadGetDataInternal();
void scePadGetDeviceId();
void scePadGetDeviceInfo();
void scePadGetExtControllerInformation();
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
void scePadOpenExt();
void scePadOpenExt2();
void scePadOutputReport();
void scePadReadBlasterForTracker();
void scePadReadExt();
void scePadReadForTracker();
void scePadReadHistory();
void scePadReadStateExt();
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
