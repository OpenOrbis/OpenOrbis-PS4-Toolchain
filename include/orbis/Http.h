#include <stddef.h>
#include <stdint.h>
#include <orbis/_types/http.h>

#ifndef _SCE_HTTP_H_
#define _SCE_HTTP_H_

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
int32_t sceHttpAbortRequest(int32_t reqId);
// Empty Comment
void sceHttpAbortRequestForce();
// Empty Comment
void sceHttpAbortWaitRequest();
// Empty Comment
void sceHttpAddCookie();
// Empty Comment
int32_t sceHttpAddRequestHeader(int32_t id, const char *name, const char *value, int32_t mode);
// Empty Comment
void sceHttpAddRequestHeaderRaw();
// Empty Comment
void sceHttpAuthCacheExport();
// Empty Comment
void sceHttpAuthCacheFlush();
// Empty Comment
void sceHttpAuthCacheImport();
// Empty Comment
void sceHttpCookieExport();
// Empty Comment
void sceHttpCookieFlush();
// Empty Comment
void sceHttpCookieImport();
// Empty Comment
int32_t sceHttpCreateConnection(int32_t tmplId, const char *serverName, const char *scheme, uint16_t port, int32_t isEnableKeepalive);
// Empty Comment
int32_t sceHttpCreateConnectionWithURL(int32_t templateId, const char *url, bool isKeepalive);
// Empty Comment
void sceHttpCreateEpoll();
// Empty Comment
int32_t sceHttpCreateRequest(int32_t connId, int32_t method, const char *path, uint64_t	contentLength);
// Empty Comment
int32_t sceHttpCreateRequest2(int32_t connId, const char* method, const char *path, uint64_t contentLength);
// Empty Comment
int32_t sceHttpCreateRequestWithURL(int32_t conectId, int32_t method, const char *url, uint64_t contentLength);
// Empty Comment
int32_t sceHttpCreateRequestWithURL2(int32_t connId, const char* method, const char *url, uint64_t contentLength);
// Empty Comment
int32_t sceHttpCreateTemplate(int32_t httpCtxId, const char*userAgent, int32_t httpVer, int32_t proxy);
// Empty Comment
void sceHttpDbgGetConnectionStat();
// Empty Comment
void sceHttpDbgGetRequestStat();
// Empty Comment
void sceHttpDbgSetPrintf();
// Empty Comment
void sceHttpDbgShowConnectionStat();
// Empty Comment
void sceHttpDbgShowMemoryPoolStat();
// Empty Comment
void sceHttpDbgShowRequestStat();
// Empty Comment
void sceHttpDbgShowStat();
// Empty Comment
int32_t sceHttpDeleteConnection(int32_t connId);
// Empty Comment
int32_t sceHttpDeleteRequest(int32_t reqId);
// Empty Comment
int32_t sceHttpDeleteTemplate(int32_t templateId);
// Empty Comment
void sceHttpDestroyEpoll();
// Empty Comment
void sceHttpGetAcceptEncodingGZIPEnabled();
// Empty Comment
int32_t sceHttpGetAllResponseHeaders(int32_t reqId, char **header, size_t *headerSize);
// Empty Comment
int32_t sceHttpGetAuthEnabled(int32_t id, int32_t *isEnable);
// Empty Comment
int32_t sceHttpGetAutoRedirect(int32_t id, int32_t *isEnable);
// Empty Comment
void sceHttpGetCookie();
// Empty Comment
void sceHttpGetCookieEnabled();
// Empty Comment
void sceHttpGetCookieStats();
// Empty Comment
void sceHttpGetEpoll();
// Empty Comment
void sceHttpGetEpollId();
// Empty Comment
int32_t sceHttpGetLastErrno(int32_t reqId, int32_t* errNum);
// Empty Comment
void sceHttpGetMemoryPoolStats();
// Empty Comment
int32_t sceHttpGetNonblock(int32_t id, int32_t *isEnable);
// Empty Comment
int32_t sceHttpGetResponseContentLength(int32_t reqId, int32_t *result, size_t *contentLength);
// Empty Comment
int32_t sceHttpGetStatusCode(int32_t reqId, int32_t *statusCode);
// Empty Comment
int32_t sceHttpInit(int32_t memId, int32_t sslId, size_t poolSize);
// Empty Comment
void sceHttpParseResponseHeader();
// Empty Comment
void sceHttpParseStatusLine();
// Empty Comment
int32_t sceHttpReadData(int32_t reqId, void *data, uint32_t size);
// Empty Comment
void sceHttpRedirectCacheFlush();
// Empty Comment
void sceHttpRemoveRequestHeader();
// Empty Comment
void sceHttpRequestGetAllHeaders();
// Empty Comment
int32_t sceHttpsDisableOption(int32_t id, uint32_t flags);
// Empty Comment
void sceHttpsDisableOptionPrivate();
// Empty Comment
int32_t sceHttpsEnableOption(int32_t id, uint32_t flags);
// Empty Comment
void sceHttpsEnableOptionPrivate();
// Empty Comment
int32_t sceHttpSendRequest(int32_t reqId, const void *postData, size_t size);
// Empty Comment
void sceHttpSetAcceptEncodingGZIPEnabled();
// Empty Comment
void sceHttpSetAuthEnabled();
// Empty Comment
void sceHttpSetAuthInfoCallback();
// Empty Comment
void sceHttpSetAutoRedirect();
// Empty Comment
void sceHttpSetChunkedTransferEnabled();
// Empty Comment
int32_t sceHttpSetConnectTimeOut(int32_t id, uint32_t usec);
// Empty Comment
void sceHttpSetCookieEnabled();
// Empty Comment
void sceHttpSetCookieMaxNum();
// Empty Comment
void sceHttpSetCookieMaxNumPerDomain();
// Empty Comment
void sceHttpSetCookieMaxSize();
// Empty Comment
void sceHttpSetCookieRecvCallback();
// Empty Comment
void sceHttpSetCookieSendCallback();
// Empty Comment
void sceHttpSetCookieTotalMaxSize();
// Empty Comment
void sceHttpSetDefaultAcceptEncodingGZIPEnabled();
// Empty Comment
void sceHttpSetEpoll();
// Empty Comment
void sceHttpSetEpollId();
// Empty Comment
void sceHttpSetInflateGZIPEnabled();
// Empty Comment
void sceHttpSetNonblock();
// Empty Comment
void sceHttpSetPolicyOption();
// Empty Comment
void sceHttpSetPriorityOption();
// Empty Comment
void sceHttpSetProxy();
// Empty Comment
void sceHttpSetRecvBlockSize();
// Empty Comment
void sceHttpSetRecvTimeOut();
// Empty Comment
void sceHttpSetRedirectCallback();
// Empty Comment
int32_t sceHttpSetRequestContentLength(int32_t id, uint64_t contentLength);
// Empty Comment
void sceHttpSetResolveRetry();
// Empty Comment
int32_t sceHttpSetResolveTimeOut(int32_t id, uint32_t usec);
// Empty Comment
void sceHttpSetResponseHeaderMaxSize();
// Empty Comment
int32_t sceHttpSetSendTimeOut(int32_t id, uint32_t usec);
// Empty Comment
void sceHttpsFreeCaList();
// Empty Comment
void sceHttpsGetCaList();
// Empty Comment
void sceHttpsGetSslError();
// Empty Comment
int32_t sceHttpsLoadCert(int32_t httpId, int32_t nbr, void* cert_list, void* cert, void* private_key);
// Empty Comment
int32_t sceHttpsSetSslCallback(int32_t id, OrbisHttpsCallback cbfunc, void *userArg);
// Empty Comment
void sceHttpsSetSslVersion();
// Empty Comment
void sceHttpsUnloadCert();
// Empty Comment
int32_t sceHttpTerm(int32_t httpCtxId);
// Empty Comment
void sceHttpTryGetNonblock();
// Empty Comment
void sceHttpTrySetNonblock();
// Empty Comment
void sceHttpUnsetEpoll();
// Empty Comment
void sceHttpUriBuild();
// Empty Comment
void sceHttpUriCopy();
// Empty Comment
void sceHttpUriEscape();
// Empty Comment
void sceHttpUriMerge();
// Empty Comment
void sceHttpUriParse();
// Empty Comment
void sceHttpUriSweepPath();
// Empty Comment
void sceHttpUriUnescape();
// Empty Comment
void sceHttpWaitRequest();


#ifdef __cplusplus
}
#endif

#endif
