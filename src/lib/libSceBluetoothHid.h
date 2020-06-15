#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceBluetoothHidDebugGetVersion();
void sceBluetoothHidDisconnectDevice();
void sceBluetoothHidGetDeviceInfo();
void sceBluetoothHidGetDeviceName();
void sceBluetoothHidGetFeatureReport();
void sceBluetoothHidGetInputReport();
void sceBluetoothHidGetReportDescriptor();
void sceBluetoothHidInit();
void sceBluetoothHidInterruptOutput();
void sceBluetoothHidParamInitialize();
void sceBluetoothHidRegisterCallback();
void sceBluetoothHidRegisterDevice();
void sceBluetoothHidSetFeatureReport();
void sceBluetoothHidSetOutputReport();
void sceBluetoothHidThreadParamInitialize();
void sceBluetoothHidUnregisterCallback();
void sceBluetoothHidUnregisterDevice();
