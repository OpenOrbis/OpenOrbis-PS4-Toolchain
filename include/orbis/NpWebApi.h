#ifndef _SCE_NP_WEB_API_H_
#define _SCE_NP_WEB_API_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceNpWebApiAbortHandle();
// Empty Comment
void sceNpWebApiAbortRequest();
// Empty Comment
void sceNpWebApiAddHttpRequestHeader();
// Empty Comment
void sceNpWebApiAddMultipartPart();
// Empty Comment
void sceNpWebApiCheckTimeout();
// Empty Comment
void sceNpWebApiClearAllUnusedConnection();
// Empty Comment
void sceNpWebApiClearUnusedConnection();
// Empty Comment
void sceNpWebApiCreateContext();
// Empty Comment
void sceNpWebApiCreateContextA();
// Empty Comment
void sceNpWebApiCreateExtdPushEventFilter();
// Empty Comment
void sceNpWebApiCreateHandle();
// Empty Comment
void sceNpWebApiCreateMultipartRequest();
// Empty Comment
void sceNpWebApiCreatePushEventFilter();
// Empty Comment
void sceNpWebApiCreateRequest();
// Empty Comment
void sceNpWebApiCreateServicePushEventFilter();
// Empty Comment
void sceNpWebApiDeleteContext();
// Empty Comment
void sceNpWebApiDeleteExtdPushEventFilter();
// Empty Comment
void sceNpWebApiDeleteHandle();
// Empty Comment
void sceNpWebApiDeletePushEventFilter();
// Empty Comment
void sceNpWebApiDeleteRequest();
// Empty Comment
void sceNpWebApiDeleteServicePushEventFilter();
// Empty Comment
void sceNpWebApiGetConnectionStats();
// Empty Comment
void sceNpWebApiGetErrorCode();
// Empty Comment
void sceNpWebApiGetHttpResponseHeaderValue();
// Empty Comment
void sceNpWebApiGetHttpResponseHeaderValueLength();
// Empty Comment
void sceNpWebApiGetHttpStatusCode();
// Empty Comment
void sceNpWebApiGetMemoryPoolStats();
// Empty Comment
void sceNpWebApiInitialize();
// Empty Comment
void sceNpWebApiIntCreateCtxIndExtdPushEventFilter();
// Empty Comment
void sceNpWebApiIntCreateServicePushEventFilter();
// Empty Comment
void sceNpWebApiIntInitialize();
// Empty Comment
void sceNpWebApiReadData();
// Empty Comment
void sceNpWebApiRegisterExtdPushEventCallback();
// Empty Comment
void sceNpWebApiRegisterExtdPushEventCallbackA();
// Empty Comment
void sceNpWebApiRegisterNotificationCallback();
// Empty Comment
void sceNpWebApiRegisterPushEventCallback();
// Empty Comment
void sceNpWebApiRegisterServicePushEventCallback();
// Empty Comment
void sceNpWebApiSendMultipartRequest();
// Empty Comment
void sceNpWebApiSendMultipartRequest2();
// Empty Comment
void sceNpWebApiSendRequest();
// Empty Comment
void sceNpWebApiSendRequest2();
// Empty Comment
void sceNpWebApiSetHandleTimeout();
// Empty Comment
void sceNpWebApiSetMaxConnection();
// Empty Comment
void sceNpWebApiSetMultipartContentType();
// Empty Comment
void sceNpWebApiSetRequestTimeout();
// Empty Comment
void sceNpWebApiTerminate();
// Empty Comment
void sceNpWebApiUnregisterExtdPushEventCallback();
// Empty Comment
void sceNpWebApiUnregisterNotificationCallback();
// Empty Comment
void sceNpWebApiUnregisterPushEventCallback();
// Empty Comment
void sceNpWebApiUnregisterServicePushEventCallback();
// Empty Comment
void sceNpWebApiUtilityParseNpId();

#endif

#ifdef __cplusplus
}
#endif