#ifndef _SCE_COMPANION_HTTPD_H_
#define _SCE_COMPANION_HTTPD_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceCompanionHttpdAddHeader();
// Empty Comment
void sceCompanionHttpdGet2ndScreenStatus();
// Empty Comment
void sceCompanionHttpdGetEvent();
// Empty Comment
void sceCompanionHttpdGetUserId();
// Empty Comment
void sceCompanionHttpdInitialize();
// Empty Comment
void sceCompanionHttpdInitialize2();
// Empty Comment
void sceCompanionHttpdOptParamInitialize();
// Empty Comment
void sceCompanionHttpdRegisterRequestBodyReceptionCallback();
// Empty Comment
void sceCompanionHttpdRegisterRequestCallback();
// Empty Comment
void sceCompanionHttpdRegisterRequestCallback2();
// Empty Comment
void sceCompanionHttpdSetBody();
// Empty Comment
void sceCompanionHttpdSetStatus();
// Empty Comment
void sceCompanionHttpdStart();
// Empty Comment
void sceCompanionHttpdStop();
// Empty Comment
void sceCompanionHttpdTerminate();
// Empty Comment
void sceCompanionHttpdUnregisterRequestBodyReceptionCallback();
// Empty Comment
void sceCompanionHttpdUnregisterRequestCallback();

#endif

#ifdef __cplusplus
}
#endif