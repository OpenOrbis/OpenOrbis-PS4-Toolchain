#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void MvpHttpAbort();
void MvpHttpDeInit();
void MvpHttpGet();
void MvpHttpGetLastError();
void MvpHttpHead();
void MvpHttpHeadCleanup();
void MvpHttpInit();
void MvpHttpPost();
void MvpHttpSetCert();
void MvpHttpSetRecvTimeout();
void MvpHttpSetRedirectCb();
void sceTsCloseFile();
void sceTsDisableRepresentation();
void sceTsEnableRepresentation();
void sceTsEnableStream();
void sceTsGetAvailableBW();
void sceTsGetLiveStatus();
void sceTsGetNextAuInfo();
void sceTsGetNextUnitData();
void sceTsGetRepresentationCount();
void sceTsGetRepresentationInfo();
void sceTsGetSeekWindow();
void sceTsGetStreamInfo();
void sceTsGetUrlEncryptionType();
void sceTsJumpPTS();
void sceTsOpenFile();
void sceTsOpenFileEx();
void sceTsReleaseBuffer();
void sceTsRepresentationIsEnabled();
void sceTsSetAvailableBW();
void sceTsSetStartingBW();
void sceTsStartFileStreaming();
void sceTsStopFileStreaming();
