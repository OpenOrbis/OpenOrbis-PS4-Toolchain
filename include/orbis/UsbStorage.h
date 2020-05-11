#ifndef _SCE_USB_STORAGE_H_
#define _SCE_USB_STORAGE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceUsbStorageGetDeviceInfo();
// Empty Comment
void sceUsbStorageGetDeviceList();
// Empty Comment
void sceUsbStorageInit();
// Empty Comment
void sceUsbStorageIsExist();
// Empty Comment
void sceUsbStorageRegisterCallback();
// Empty Comment
void sceUsbStorageRequestMap();
// Empty Comment
void sceUsbStorageRequestUnmap();
// Empty Comment
void sceUsbStorageTerm();
// Empty Comment
void sceUsbStorageUnregisterCallback();

#endif

#ifdef __cplusplus
}
#endif