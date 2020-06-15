#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceHidControlConnectHandle();
void sceHidControlConnectPort();
void sceHidControlDisconnectDevice();
void sceHidControlDisconnectHandle();
void sceHidControlDisconnectPort();
void sceHidControlGetAuthInformation();
void sceHidControlGetBatteryState();
void sceHidControlGetDeviceId();
void sceHidControlGetDeviceInfo();
void sceHidControlGetDeviceName();
void sceHidControlGetJediExtensionUnitInfo();
void sceHidControlGetJediState();
void sceHidControlGetSparkState();
void sceHidControlInit();
void sceHidControlSetApplicationFocus();
void sceHidControlSetHandleState();
void sceHidControlSetJediAudioOutPath();
void sceHidControlSetJediVolumeGain();
void sceHidControlSetProcessFocus();
void sceHidControlSetRevokeList();
void sceHidControlSetUserColor();
