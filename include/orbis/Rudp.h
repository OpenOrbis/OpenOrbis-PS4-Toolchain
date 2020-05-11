#ifndef _SCE_RUDP_H_
#define _SCE_RUDP_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceRudpAccept();
// Empty Comment
void sceRudpActivate();
// Empty Comment
void sceRudpBind();
// Empty Comment
void sceRudpCreateContext();
// Empty Comment
void sceRudpEnableInternalIOThread();
// Empty Comment
void sceRudpEnableInternalIOThread2();
// Empty Comment
void sceRudpEnd();
// Empty Comment
void sceRudpFlush();
// Empty Comment
void sceRudpGetContextStatus();
// Empty Comment
void sceRudpGetLocalInfo();
// Empty Comment
void sceRudpGetMaxSegmentSize();
// Empty Comment
void sceRudpGetNumberOfPacketsToRead();
// Empty Comment
void sceRudpGetOption();
// Empty Comment
void sceRudpGetRemoteInfo();
// Empty Comment
void sceRudpGetSizeReadable();
// Empty Comment
void sceRudpGetSizeWritable();
// Empty Comment
void sceRudpGetStatus();
// Empty Comment
void sceRudpInit();
// Empty Comment
void sceRudpInitiate();
// Empty Comment
void sceRudpListen();
// Empty Comment
void sceRudpNetFlush();
// Empty Comment
void sceRudpNetReceived();
// Empty Comment
void sceRudpPollCancel();
// Empty Comment
void sceRudpPollControl();
// Empty Comment
void sceRudpPollCreate();
// Empty Comment
void sceRudpPollDestroy();
// Empty Comment
void sceRudpPollWait();
// Empty Comment
void sceRudpProcessEvents();
// Empty Comment
void sceRudpRead();
// Empty Comment
void sceRudpSetEventHandler();
// Empty Comment
void sceRudpSetMaxSegmentSize();
// Empty Comment
void sceRudpSetOption();
// Empty Comment
void sceRudpTerminate();
// Empty Comment
void sceRudpWrite();

#endif

#ifdef __cplusplus
}
#endif