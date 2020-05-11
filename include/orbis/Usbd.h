#ifndef _SCE_USBD_H_
#define _SCE_USBD_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceUsbdAllocTransfer();
// Empty Comment
void sceUsbdAttachKernelDriver();
// Empty Comment
void sceUsbdBulkTransfer();
// Empty Comment
void sceUsbdCancelTransfer();
// Empty Comment
void sceUsbdCheckConnected();
// Empty Comment
void sceUsbdClaimInterface();
// Empty Comment
void sceUsbdClearHalt();
// Empty Comment
void sceUsbdClose();
// Empty Comment
void sceUsbdControlTransfer();
// Empty Comment
void sceUsbdControlTransferGetData();
// Empty Comment
void sceUsbdControlTransferGetSetup();
// Empty Comment
void sceUsbdDetachKernelDriver();
// Empty Comment
void sceUsbdEventHandlerActive();
// Empty Comment
void sceUsbdEventHandlingOk();
// Empty Comment
void sceUsbdExit();
// Empty Comment
void sceUsbdFillBulkTransfer();
// Empty Comment
void sceUsbdFillControlSetup();
// Empty Comment
void sceUsbdFillControlTransfer();
// Empty Comment
void sceUsbdFillInterruptTransfer();
// Empty Comment
void sceUsbdFillIsoTransfer();
// Empty Comment
void sceUsbdFreeConfigDescriptor();
// Empty Comment
void sceUsbdFreeDeviceList();
// Empty Comment
void sceUsbdFreeTransfer();
// Empty Comment
void sceUsbdGetActiveConfigDescriptor();
// Empty Comment
void sceUsbdGetBusNumber();
// Empty Comment
void sceUsbdGetConfigDescriptor();
// Empty Comment
void sceUsbdGetConfigDescriptorByValue();
// Empty Comment
void sceUsbdGetConfiguration();
// Empty Comment
void sceUsbdGetDescriptor();
// Empty Comment
void sceUsbdGetDevice();
// Empty Comment
void sceUsbdGetDeviceAddress();
// Empty Comment
void sceUsbdGetDeviceDescriptor();
// Empty Comment
void sceUsbdGetDeviceList();
// Empty Comment
void sceUsbdGetDeviceSpeed();
// Empty Comment
void sceUsbdGetIsoPacketBuffer();
// Empty Comment
void sceUsbdGetMaxIsoPacketSize();
// Empty Comment
void sceUsbdGetMaxPacketSize();
// Empty Comment
void sceUsbdGetStringDescriptor();
// Empty Comment
void sceUsbdGetStringDescriptorAscii();
// Empty Comment
void sceUsbdHandleEvents();
// Empty Comment
void sceUsbdHandleEventsLocked();
// Empty Comment
void sceUsbdHandleEventsTimeout();
// Empty Comment
void sceUsbdInit();
// Empty Comment
void sceUsbdInterruptTransfer();
// Empty Comment
void sceUsbdKernelDriverActive();
// Empty Comment
void sceUsbdLockEvents();
// Empty Comment
void sceUsbdLockEventWaiters();
// Empty Comment
void sceUsbdOpen();
// Empty Comment
void sceUsbdOpenDeviceWithVidPid();
// Empty Comment
void sceUsbdRefDevice();
// Empty Comment
void sceUsbdReleaseInterface();
// Empty Comment
void sceUsbdResetDevice();
// Empty Comment
void sceUsbdSetConfiguration();
// Empty Comment
void sceUsbdSetInterfaceAltSetting();
// Empty Comment
void sceUsbdSetIsoPacketLengths();
// Empty Comment
void sceUsbdSubmitTransfer();
// Empty Comment
void sceUsbdTryLockEvents();
// Empty Comment
void sceUsbdUnlockEvents();
// Empty Comment
void sceUsbdUnlockEventWaiters();
// Empty Comment
void sceUsbdUnrefDevice();
// Empty Comment
void sceUsbdWaitForEvent();

#endif

#ifdef __cplusplus
}
#endif