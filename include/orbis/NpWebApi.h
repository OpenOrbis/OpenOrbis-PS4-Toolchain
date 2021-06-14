#ifndef _SCE_NP_WEB_API_H_
#define _SCE_NP_WEB_API_H_

#include <stdint.h>
#include <_types/np_common.h>
#include <_types/np_webapi.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int sceNpWebApiAbortHandle(int libCtxId, int handleId);
    int sceNpWebApiAbortRequest(uint64_t requestId);
    int sceNpWebApiAddHttpRequestHeader(int64_t requestId, const char *pFieldName, const char *pValue);
    int sceNpWebApiAddMultipartPart(int64_t requestId, const OrbisNpWebApiMultipartPartParameter *pParam, int *pIndex);
    void sceNpWebApiCheckTimeout(void);
    int sceNpWebApiClearAllUnusedConnection(int userCtxId, bool keepAlive);
    int sceNpWebApiClearUnusedConnection(int userCtxId, const char *pApiGroup, bool keepAlive);
    int sceNpWebApiCreateContextA(int libCtxId, int userId);
    int sceNpWebApiCreateExtdPushEventFilter(int32_t libCtxId, int32_t handleId, const char *pNpServiceName, OrbisNpServiceLabel npServiceLabel, const OrbisNpWebApiExtdPushEventFilterParameter *pFilterParam, size_t filterParamNum);
    int sceNpWebApiCreateHandle(int libCtxId);
    int sceNpWebApiCreateMultipartRequest(int32_t titleUserCtxId, const char *pApiGroup, const char *pPath, OrbisNpWebApiHttpMethod method, int64_t *pRequestId);
    int sceNpWebApiCreateRequest(int titleUserCtxId, const char *pApiGroup, const char *pPath, OrbisNpWebApiHttpMethod method, const OrbisNpWebApiContentParameter *pContentParameter, int64_t *pRequestId);
    int sceNpWebApiDeleteContext(int titleUserCtxId);
    int sceNpWebApiDeleteExtdPushEventFilter(int libCtxId, int filterId);
    void sceNpWebApiDeleteHandle(int libCtxId, int handleId);
    int sceNpWebApiDeleteRequest(int64_t requestId);
    int sceNpWebApiGetConnectionStats(int userCtxId, const char *pApiGroup, void *pStats);
    int sceNpWebApiGetHttpResponseHeaderValue(int64_t requestId, const char *pFieldName, char *pValue, size_t valueSize);
    int sceNpWebApiGetHttpResponseHeaderValueLength(int64_t requestId, const char *pFieldName, size_t *pValueLength);
    int sceNpWebApiGetMemoryPoolStats(int libCtxId, OrbisNpWebApiMemoryPoolStats *pCurrentStat);
    int sceNpWebApiInitialize(int libHttpCtxId, size_t poolSize);
    int sceNpWebApiReadData(int64_t requestId, void *pData, size_t size);
    int sceNpWebApiRegisterExtdPushEventCallback(int32_t userCtxId, int32_t filterId, OrbisNpWebApiExtdPushEventCallbackA cbFunc, void *pUserArg);
    int sceNpWebApiRegisterExtdPushEventCallbackA(int32_t userCtxId, int32_t filterId, OrbisNpWebApiExtdPushEventCallbackA cbFunc, void *pUserArg);
    int sceNpWebApiSendMultipartRequest(int64_t requestId, int32_t partIndex, const void *pData, size_t dataSize, OrbisNpWebApiResponseInformationOption *pRespInfoOption);
    int sceNpWebApiSendMultipartRequest2(int64_t requestId, int32_t partIndex, const void *pData, size_t dataSize, OrbisNpWebApiResponseInformationOption *pRespInfoOption);
    int sceNpWebApiSendRequest2(int64_t requestId, const void *pData, size_t dataSize, OrbisNpWebApiResponseInformationOption *pRespInfoOption);
    int sceNpWebApiSetMaxConnection(int32_t libCtxId, int32_t maxConnection);
    int sceNpWebApiSetMultipartContentType(int64_t requestId, const char *pTypeName, const char *pBoundary);
    int sceNpWebApiSetRequestTimeout(int64_t requestId, uint32_t timeout);
    int sceNpWebApiTerminate(int32_t libCtxId);
    int sceNpWebApiUnregisterExtdPushEventCallback(int32_t userCtxId, int32_t callbackId);
    int sceNpWebApiUnregisterServicePushEventCallback();
    int sceNpWebApiUtilityParseNpId(const char *pJsonNpId, OrbisNpId *pNpId);

    // The below functions are currently not reversed
    void sceNpWebApiCreateContext();
    void sceNpWebApiCreatePushEventFilter();
    void sceNpWebApiCreateServicePushEventFilter();
    void sceNpWebApiDeletePushEventFilter();
    void sceNpWebApiDeleteServicePushEventFilter();
    void sceNpWebApiGetErrorCode();
    void sceNpWebApiGetHttpStatusCode();
    void sceNpWebApiIntCreateCtxIndExtdPushEventFilter();
    void sceNpWebApiIntCreateServicePushEventFilter();
    void sceNpWebApiIntInitialize();
    void sceNpWebApiSendRequest();
    void sceNpWebApiUnregisterNotificationCallback();
    void sceNpWebApiUnregisterPushEventCallback();
    void sceNpWebApiRegisterNotificationCallback();
    void sceNpWebApiRegisterPushEventCallback();
    void sceNpWebApiSetHandleTimeout();
    void sceNpWebApiRegisterServicePushEventCallback();

#endif

#ifdef __cplusplus
}
#endif