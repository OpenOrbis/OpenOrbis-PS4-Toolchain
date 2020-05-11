#ifndef _SCE_NP_AUTH_H_
#define _SCE_NP_AUTH_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceNpAuthAbortRequest();
// Empty Comment
void sceNpAuthCreateAsyncRequest();
// Empty Comment
void sceNpAuthCreateRequest();
// Empty Comment
void sceNpAuthDeleteRequest();
// Empty Comment
void sceNpAuthGetAuthorizationCode();
// Empty Comment
void sceNpAuthGetAuthorizationCodeA();
// Empty Comment
void sceNpAuthGetIdTokenA();
// Empty Comment
void sceNpAuthPollAsync();
// Empty Comment
void sceNpAuthSetTimeout();
// Empty Comment
void sceNpAuthWaitAsync();

#endif

#ifdef __cplusplus
}
#endif