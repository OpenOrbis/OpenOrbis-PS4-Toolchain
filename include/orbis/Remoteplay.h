#ifndef _SCE_REMOTE_PLAY_H_
#define _SCE_REMOTE_PLAY_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceRemoteplayApprove();
// Empty Comment
void sceRemoteplayClearConnectHistory();
// Empty Comment
void sceRemoteplayGetConnectHistory();
// Empty Comment
void sceRemoteplayGetConnectionStatus();
// Empty Comment
void sceRemoteplayGetMbusDeviceInfo();
// Empty Comment
void sceRemoteplayInitialize();
// Empty Comment
void sceRemoteplayNotifyNpPushWakeup();
// Empty Comment
void sceRemoteplayProhibit();
// Empty Comment
void sceRemoteplayProhibitStreaming();
// Empty Comment
void sceRemoteplaySetProhibition();
// Empty Comment
void sceRemoteplayTerminate();

#endif

#ifdef __cplusplus
}
#endif