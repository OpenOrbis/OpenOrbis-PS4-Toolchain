#ifndef _SCE_USBD_H_
#define _SCE_USBD_H_

#include <stdint.h>
#include <libusb.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Requires libSceUsbd.sprx to be loaded.
int32_t sceUsbdInit();
int32_t sceUsbdExit();

int32_t sceUsbdGetDeviceList(libusb_device ***list);
int32_t sceUsbdFreeDeviceList(libusb_device **list);
int32_t sceUsbdOpen(libusb_device *dev, libusb_device_handle **dev_handle);
libusb_device_handle *sceUsbdOpenDeviceWithVidPid(uint16_t vendor_id, uint16_t product_id);

uint8_t sceUsbdGetBusNumber(libusb_device *dev);
uint8_t sceUsbdGetDeviceAddress(libusb_device *dev);
int32_t sceUsbdGetPortNumbers(libusb_device *dev, uint8_t *port_numbers, int32_t port_numbers_len);
int32_t sceUsbdGetMaxPacketSize(libusb_device *dev, unsigned char endpoint);
int32_t sceUsbdGetMaxIsoPacketSize(libusb_device *dev, unsigned char endpoint);
int32_t sceUsbdGetDeviceSpeed(libusb_device *dev);

int32_t sceUsbdGetDeviceDescriptor(libusb_device *dev, struct libusb_device_descriptor *config);
int32_t sceUsbdGetActiveConfigDescriptor(libusb_device *dev, struct libusb_config_descriptor **config);
int32_t sceUsbdGetConfigDescriptor(libusb_device *dev, uint8_t config_index, struct libusb_config_descriptor **config);
int32_t sceUsbdGetConfigDescriptorByValue(libusb_device *dev, uint8_t bConfigurationValue, struct libusb_config_descriptor **config);
int32_t sceUsbdFreeConfigDescriptor(struct libusb_config_descriptor *config);

libusb_device *sceUsbdGetDevice(libusb_device_handle *dev_handle);
int32_t sceUsbdGetConfiguration(libusb_device_handle *dev_handle, int32_t *config);
int32_t sceUsbdSetConfiguration(libusb_device_handle *dev_handle, int32_t configuration);
int32_t sceUsbdResetDevice(libusb_device_handle *dev_handle);
int32_t sceUsbdCheckConnected(libusb_device_handle *dev_handle);
void sceUsbdClose(libusb_device_handle *dev_handle);

int32_t sceUsbdGetDescriptor(libusb_device_handle *dev_handle, uint8_t desc_type, uint8_t desc_index, unsigned char *data, int32_t length);
int32_t sceUsbdGetStringDescriptor(libusb_device_handle *dev_handle, uint8_t desc_index, uint16_t langid, unsigned char *data, int32_t length);
int32_t sceUsbdGetStringDescriptorAscii(libusb_device_handle *dev_handle, uint8_t desc_index, uint16_t langid, unsigned char *data, int32_t length);

int32_t sceUsbdClaimInterface(libusb_device_handle *dev_handle, int32_t interface_number);
int32_t sceUsbdReleaseInterface(libusb_device_handle *dev_handle, int32_t interface_number);
int32_t sceUsbdSetInterfaceAltSetting(libusb_device_handle *dev_handle, int32_t interface_number, int32_t alternate_setting);

int32_t sceUsbdControlTransfer(libusb_device_handle *dev_handle, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, unsigned char *data, uint16_t wLength, uint32_t timeout);
int32_t sceUsbdBulkTransfer(libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int32_t length, int32_t *transferred, uint32_t timeout);
int32_t sceUsbdInterruptTransfer(libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *data, int32_t length, int32_t *transferred, uint32_t timeout);

struct libusb_transfer *sceUsbdAllocTransfer(int32_t iso_packets);
void sceUsbdFreeTransfer(struct libusb_transfer *transfer);
int32_t sceUsbdSubmitTransfer(struct libusb_transfer *transfer);
int32_t sceUsbdCancelTransfer(struct libusb_transfer *transfer);

unsigned char *sceUsbdControlTransferGetData(struct libusb_transfer *transfer);
struct libusb_control_setup *sceUsbdControlTransferGetSetup(struct libusb_transfer *transfer);
void sceUsbdFillControlSetup(unsigned char *buffer, uint8_t bmRequestType, uint8_t bRequest, uint16_t wValue, uint16_t wIndex, uint16_t wLength);
void sceUsbdFillControlTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char *buffer, libusb_transfer_cb_fn callback, void *user_data, uint32_t timeout);
void sceUsbdFillBulkTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *buffer, int32_t length, libusb_transfer_cb_fn callback, void *user_data, uint32_t timeout);
void sceUsbdFillInterruptTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *buffer, int32_t length, libusb_transfer_cb_fn callback, void *user_data, uint32_t timeout);
void sceUsbdFillIsoTransfer(struct libusb_transfer *transfer, libusb_device_handle *dev_handle, unsigned char endpoint, unsigned char *buffer, int32_t length, libusb_transfer_cb_fn callback, void *user_data, uint32_t timeout);
void sceUsbdSetIsoPacketLengths(struct libusb_transfer *transfer, uint32_t length);
unsigned char *sceUsbdGetIsoPacketBuffer(struct libusb_transfer *transfer, uint32_t packet);
int32_t sceUsbdHandleEventsTimeout(int32_t *timeval);

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

#ifdef __cplusplus
}
#endif

#endif
