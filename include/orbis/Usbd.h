#ifndef _SCE_USBD_H_
#define _SCE_USBD_H_

#include <stdint.h>
#include <libusb.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Requires libSceUsbd.sprx to be loaded.
int sceUsbdInit();
int sceUsbdExit();

int sceUsbdGetDeviceList(libusb_device ***list);
int sceUsbdFreeDeviceList(libusb_device **list);
int sceUsbdOpen(libusb_device *dev, libusb_device_handle **dev_handle);
libusb_device_handle *sceUsbdOpenDeviceWithVidPid(uint16_t vendor_id, uint16_t product_id);

uint8_t sceUsbdGetBusNumber(libusb_device *dev);
uint8_t sceUsbdGetDeviceAddress(libusb_device *dev);
int sceUsbdGetPortNumbers(libusb_device *dev, uint8_t *port_numbers, int port_numbers_len);
int sceUsbdGetMaxPacketSize(libusb_device *dev, unsigned char endpoint);
int sceUsbdGetMaxIsoPacketSize(libusb_device *dev, unsigned char endpoint);
int sceUsbdGetDeviceSpeed(libusb_device *dev);

int sceUsbdGetDeviceDescriptor(libusb_device *dev, struct libusb_device_descriptor *config);
int sceUsbdGetActiveConfigDescriptor(libusb_device *dev, struct libusb_config_descriptor **config);
int sceUsbdGetConfigDescriptor(libusb_device *dev, uint8_t config_index, struct libusb_config_descriptor **config);
int sceUsbdGetConfigDescriptorByValue(libusb_device *dev, uint8_t bConfigurationValue, struct libusb_config_descriptor **config);
int sceUsbdFreeConfigDescriptor(struct libusb_config_descriptor *config);

libusb_device *sceUsbdGetDevice(libusb_device_handle *dev_handle);
int sceUsbdGetConfiguration(libusb_device_handle *dev_handle, int *config);
int sceUsbdSetConfiguration(libusb_device_handle *dev_handle, int configuration);
int sceUsbdResetDevice(libusb_device_handle *dev_handle);
int sceUsbdCheckConnected(libusb_device_handle *dev_handle);
void sceUsbdClose(libusb_device_handle *dev_handle);

int sceUsbdGetDescriptor(libusb_device_handle *dev_handle, uint8_t desc_type, uint8_t desc_index, unsigned char *data, int length);
int sceUsbdGetStringDescriptor(libusb_device_handle *dev_handle, uint8_t desc_index, uint16_t langid, unsigned char *data, int length);
int sceUsbdGetStringDescriptorAscii(libusb_device_handle *dev_handle, uint8_t desc_index, uint16_t langid, unsigned char *data, int length);

int sceUsbdClaimInterface(libusb_device_handle *dev_handle, int interface_number);
int sceUsbdReleaseInterface(libusb_device_handle *dev_handle, int interface_number);
int sceUsbdSetInterfaceAltSetting(libusb_device_handle *dev_handle, int interface_number, int alternate_setting);

int sceUsbdControlTransfer(libusb_device_handle *dev_handle, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, unsigned char *data, uint16_t wLength, unsigned int timeout);
int sceUsbdBulkTransfer(libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout);
int sceUsbdInterruptTransfer(libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int length, int *transferred, unsigned int timeout);

struct libusb_transfer *sceUsbdAllocTransfer(int iso_packets);
void sceUsbdFreeTransfer(struct libusb_transfer *transfer);
int sceUsbdSubmitTransfer(struct libusb_transfer *transfer);
int sceUsbdCancelTransfer(struct libusb_transfer *transfer);

unsigned char *sceUsbdControlTransferGetData(struct libusb_transfer *transfer);
struct libusb_control_setup *sceUsbdControlTransferGetSetup(struct libusb_transfer *transfer);
void sceUsbdFillControlSetup(unsigned char *buffer, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength);
void sceUsbdFillControlTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char *buffer, libusb_transfer_cb_fn callback, void *user_data, unsigned int timeout);
void sceUsbdFillBulkTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *buffer, int length, libusb_transfer_cb_fn callback, void *user_data, unsigned int timeout);
void sceUsbdFillInterruptTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *buffer, int length, libusb_transfer_cb_fn callback, void *user_data, unsigned int timeout);
void sceUsbdFillIsoTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *buffer, int length, libusb_transfer_cb_fn callback, void *user_data, unsigned int timeout);
void sceUsbdSetIsoPacketLengths(struct libusb_transfer *transfer, unsigned int length);
unsigned char *sceUsbdGetIsoPacketBuffer(struct libusb_transfer *transfer, unsigned int packet);
int sceUsbdHandleEventsTimeout(int *timeval);

// Empty Comment
void sceUsbdAttachKernelDriver();
// Empty Comment
void sceUsbdClearHalt();
// Empty Comment
void sceUsbdDetachKernelDriver();
// Empty Comment
void sceUsbdEventHandlerActive();
// Empty Comment
void sceUsbdEventHandlingOk();
// Empty Comment
void sceUsbdHandleEvents();
// Empty Comment
void sceUsbdHandleEventsLocked();
// Empty Comment
void sceUsbdKernelDriverActive();
// Empty Comment
void sceUsbdLockEvents();
// Empty Comment
void sceUsbdLockEventWaiters();
// Empty Comment
void sceUsbdRefDevice();
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
