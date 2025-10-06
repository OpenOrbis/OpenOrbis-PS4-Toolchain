#ifndef _SCE_SYS_UTIL_H_
#define _SCE_SYS_UTIL_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceSysUtilSendAddressingSystemNotification();
// Empty Comment
void sceSysUtilSendAddressingSystemNotificationWithDeviceId();
// Empty Comment
void sceSysUtilSendAddressingSystemNotificationWithUserId();
// Empty Comment
void sceSysUtilSendAddressingSystemNotificationWithUserName();
// Empty Comment
void sceSysUtilSendNotificationRequest();
// Empty Comment
void sceSysUtilSendNpDebugNotificationRequest();
// Empty Comment
void sceSysUtilSendSystemNotification();
// Empty Comment
void sceSysUtilSendSystemNotificationWithAppId();
// Empty Comment
void sceSysUtilSendSystemNotificationWithAppInfo();
// Empty Comment
void sceSysUtilSendSystemNotificationWithAppName();
// Empty Comment
void sceSysUtilSendSystemNotificationWithAppNameRelatedToUser();
// Empty Comment
void sceSysUtilSendSystemNotificationWithDeviceId();
// Empty Comment
void sceSysUtilSendSystemNotificationWithDeviceIdRelatedToUser();
// Empty Comment
void sceSysUtilSendSystemNotificationWithErrorCode();
// Empty Comment
void sceSysUtilSendSystemNotificationWithParams();
// Empty Comment
void sceSysUtilSendSystemNotificationWithText(int type, const char * message);
// Empty Comment
void sceSysUtilSendSystemNotificationWithTextRelatedToUser();
// Empty Comment
void sceSysUtilSendSystemNotificationWithUserId();
// Empty Comment
void sceSysUtilSendSystemNotificationWithUserName();
// Empty Comment
void sceSysUtilSendSystemNotificationWithUserNameInfo();
// Empty Comment
void sceSysUtilSendTrcCheckNotificationRequest();

#ifdef __cplusplus
}
#endif

#endif
