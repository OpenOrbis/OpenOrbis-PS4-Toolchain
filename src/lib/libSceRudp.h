#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceRudpAccept();
void sceRudpActivate();
void sceRudpBind();
void sceRudpCreateContext();
void sceRudpEnableInternalIOThread();
void sceRudpEnableInternalIOThread2();
void sceRudpEnd();
void sceRudpFlush();
void sceRudpGetContextStatus();
void sceRudpGetLocalInfo();
void sceRudpGetMaxSegmentSize();
void sceRudpGetNumberOfPacketsToRead();
void sceRudpGetOption();
void sceRudpGetRemoteInfo();
void sceRudpGetSizeReadable();
void sceRudpGetSizeWritable();
void sceRudpGetStatus();
void sceRudpInit();
void sceRudpInitiate();
void sceRudpListen();
void sceRudpNetFlush();
void sceRudpNetReceived();
void sceRudpPollCancel();
void sceRudpPollControl();
void sceRudpPollCreate();
void sceRudpPollDestroy();
void sceRudpPollWait();
void sceRudpProcessEvents();
void sceRudpRead();
void sceRudpSetEventHandler();
void sceRudpSetMaxSegmentSize();
void sceRudpSetOption();
void sceRudpTerminate();
void sceRudpWrite();
