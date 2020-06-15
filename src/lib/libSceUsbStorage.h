#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceUsbStorageGetDeviceInfo();
void sceUsbStorageGetDeviceList();
void sceUsbStorageInit();
void sceUsbStorageIsExist();
void sceUsbStorageRegisterCallback();
void sceUsbStorageRegisterCallbackForMapAvailable();
void sceUsbStorageRequestMap();
void sceUsbStorageRequestUnmap();
void sceUsbStorageTerm();
void sceUsbStorageUnregisterCallback();
void sceUsbStorageUnregisterCallbackForMapAvailable();
