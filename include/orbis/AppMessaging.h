#ifndef _SCE_APP_MESSAGING_H_
#define _SCE_APP_MESSAGING_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceAppMessagingClearEventFlag();
// Empty Comment
void sceAppMessagingReceiveMsg();
// Empty Comment
void sceAppMessagingSendMsg();
// Empty Comment
void sceAppMessagingSendMsgToShellCore();
// Empty Comment
void sceAppMessagingSendMsgToShellUI();
// Empty Comment
void sceAppMessagingSetEventFlag();
// Empty Comment
void sceAppMessagingTryGetEventFlag();
// Empty Comment
void sceAppMessagingTryReceiveMsg();

#endif

#ifdef __cplusplus
}
#endif