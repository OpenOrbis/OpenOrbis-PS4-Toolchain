#ifndef _SCE_PLAY_READY_H_
#define _SCE_PLAY_READY_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void scePlayReadyApiStart();
// Empty Comment
void scePlayReadyApiStop();
// Empty Comment
void scePlayReadyBufferFree();
// Empty Comment
void scePlayReadyBufferMalloc();
// Empty Comment
void scePlayReadyContentGetProperty();
// Empty Comment
void scePlayReadyContentSetProperty();
// Empty Comment
void scePlayReadyDomainCertEnumInit();
// Empty Comment
void scePlayReadyDomainCertEnumNext();
// Empty Comment
void scePlayReadyDomainJoinGenerateChallenge();
// Empty Comment
void scePlayReadyDomainJoinProcessResponse();
// Empty Comment
void scePlayReadyDomainLeaveGenerateChallenge();
// Empty Comment
void scePlayReadyDomainLeaveProcessResponse();
// Empty Comment
void scePlayReadyFinalize();
// Empty Comment
void scePlayReadyFreeDecryptContext();
// Empty Comment
void scePlayReadyInitialize();
// Empty Comment
void scePlayReadyInitializeInitParams();
// Empty Comment
void scePlayReadyLicenseAcqGenerateAck();
// Empty Comment
void scePlayReadyLicenseAcqGenerateChallenge();
// Empty Comment
void scePlayReadyLicenseAcqGetAdditionalResponseData();
// Empty Comment
void scePlayReadyLicenseAcqProcessAckResponse();
// Empty Comment
void scePlayReadyLicenseAcqProcessResponse();
// Empty Comment
void scePlayReadyMemAlloc();
// Empty Comment
void scePlayReadyMemFree();
// Empty Comment
void scePlayReadyMemRealloc();
// Empty Comment
void scePlayReadyNewDecryptContext();
// Empty Comment
void scePlayReadyReaderBind();
// Empty Comment
void scePlayReadyReaderCommit();
// Empty Comment
void scePlayReadyReaderDecrypt();
// Empty Comment
void scePlayReadyReset();
// Empty Comment
void scePlayReadyStoreCleanup();

#endif

#ifdef __cplusplus
}
#endif