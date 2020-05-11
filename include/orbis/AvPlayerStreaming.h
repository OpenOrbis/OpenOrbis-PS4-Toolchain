#ifndef _SCE_AV_PLAYER_STREAMING_H_
#define _SCE_AV_PLAYER_STREAMING_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void MvpHttpDeInit();
// Empty Comment
void MvpHttpGet();
// Empty Comment
void MvpHttpGetLastError();
// Empty Comment
void MvpHttpInit();
// Empty Comment
void MvpHttpPost();
// Empty Comment
void MvpHttpSetCert();
// Empty Comment
void MvpHttpSetRecvTimeout();
// Empty Comment
void MvpHttpSetRedirectCb();
// Empty Comment
void sceTsOpenFile();
// Empty Comment
void sceTsOpenFileEx();
// Empty Comment
void sceTsStartFileStreaming();
// Empty Comment
void sceTsStopFileStreaming();

#endif

#ifdef __cplusplus
}
#endif