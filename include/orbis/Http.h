#ifndef _SCE_HTTP_H_
#define _SCE_HTTP_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceHttpAbortRequest();
// Empty Comment
void sceHttpAbortRequestForce();
// Empty Comment
void sceHttpAbortWaitRequest();
// Empty Comment
void sceHttpAddCookie();
// Empty Comment
void sceHttpAddRequestHeader();
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
void sceHttpCreateConnection();
// Empty Comment
void sceHttpCreateConnectionWithURL();
// Empty Comment
void sceHttpCreateEpoll();
// Empty Comment
void sceHttpCreateRequest();
// Empty Comment
void sceHttpCreateRequest2();
// Empty Comment
void sceHttpCreateRequestWithURL();
// Empty Comment
void sceHttpCreateRequestWithURL2();
// Empty Comment
void sceHttpCreateTemplate();
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
void sceHttpDeleteConnection();
// Empty Comment
void sceHttpDeleteRequest();
// Empty Comment
void sceHttpDeleteTemplate();
// Empty Comment
void sceHttpDestroyEpoll();
// Empty Comment
void sceHttpGetAcceptEncodingGZIPEnabled();
// Empty Comment
void sceHttpGetAllResponseHeaders();
// Empty Comment
void sceHttpGetAuthEnabled();
// Empty Comment
void sceHttpGetAutoRedirect();
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
void sceHttpGetLastErrno();
// Empty Comment
void sceHttpGetMemoryPoolStats();
// Empty Comment
void sceHttpGetNonblock();
// Empty Comment
void sceHttpGetResponseContentLength();
// Empty Comment
void sceHttpGetStatusCode();
// Empty Comment
void sceHttpInit();
// Empty Comment
void sceHttpParseResponseHeader();
// Empty Comment
void sceHttpParseStatusLine();
// Empty Comment
void sceHttpReadData();
// Empty Comment
void sceHttpRedirectCacheFlush();
// Empty Comment
void sceHttpRemoveRequestHeader();
// Empty Comment
void sceHttpRequestGetAllHeaders();
// Empty Comment
void sceHttpsDisableOption();
// Empty Comment
void sceHttpsDisableOptionPrivate();
// Empty Comment
void sceHttpsEnableOption();
// Empty Comment
void sceHttpsEnableOptionPrivate();
// Empty Comment
void sceHttpSendRequest();
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
void sceHttpSetConnectTimeOut();
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
void sceHttpSetRequestContentLength();
// Empty Comment
void sceHttpSetResolveRetry();
// Empty Comment
void sceHttpSetResolveTimeOut();
// Empty Comment
void sceHttpSetResponseHeaderMaxSize();
// Empty Comment
void sceHttpSetSendTimeOut();
// Empty Comment
void sceHttpsFreeCaList();
// Empty Comment
void sceHttpsGetCaList();
// Empty Comment
void sceHttpsGetSslError();
// Empty Comment
void sceHttpsLoadCert();
// Empty Comment
void sceHttpsSetSslCallback();
// Empty Comment
void sceHttpsSetSslVersion();
// Empty Comment
void sceHttpsUnloadCert();
// Empty Comment
void sceHttpTerm();
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


#endif

#ifdef __cplusplus
}
#endif