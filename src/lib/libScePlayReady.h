#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceBufferAlloc();
void sceBufferDup();
void sceBufferFree();
void sceBufferInit();
void sceBufferRealloc();
void scePlayReadyApiInitializeInitParams();
void scePlayReadyApiIsStarted();
void scePlayReadyApiStart();
void scePlayReadyApiStop();
void scePlayReadyApiVersion();
void scePlayReadyApiVersionString();
void scePlayReadyBufferFree();
void scePlayReadyBufferInit();
void scePlayReadyBufferMalloc();
void scePlayReadyBufferRealloc();
void scePlayReadyContentGetProperty();
void scePlayReadyContentSetProperty();
void scePlayReadyDomainCertEnumFini();
void scePlayReadyDomainCertEnumInit();
void scePlayReadyDomainCertEnumNext();
void scePlayReadyDomainCertFind();
void scePlayReadyDomainJoinGenerateChallenge();
void scePlayReadyDomainJoinProcessResponse();
void scePlayReadyDomainLeaveGenerateChallenge();
void scePlayReadyDomainLeaveProcessResponse();
void scePlayReadyEnvelopeClose();
void scePlayReadyEnvelopeGetSize();
void scePlayReadyEnvelopeInitializeRead();
void scePlayReadyEnvelopeOpen();
void scePlayReadyEnvelopeRead();
void scePlayReadyEnvelopeSeek();
void scePlayReadyFinalize();
void scePlayReadyFreeDecryptContext();
void scePlayReadyInitialize();
void scePlayReadyInitializeInitParams();
void scePlayReadyLicenseAcqGenerateAck();
void scePlayReadyLicenseAcqGenerateChallenge();
void scePlayReadyLicenseAcqGetAdditionalResponseData();
void scePlayReadyLicenseAcqProcessAckResponse();
void scePlayReadyLicenseAcqProcessResponse();
void scePlayReadyMemAlloc();
void scePlayReadyMemFree();
void scePlayReadyMemGetStats();
void scePlayReadyMemRealloc();
void scePlayReadyNewDecryptContext();
void scePlayReadyReaderBind();
void scePlayReadyReaderCommit();
void scePlayReadyReaderDecrypt();
void scePlayReadyReset();
void scePlayReadyStoreCleanup();
