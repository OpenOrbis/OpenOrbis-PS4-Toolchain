#ifndef _SCE_VIDEO_CORE_SERVER_INTERFACE_H_
#define _SCE_VIDEO_CORE_SERVER_INTERFACE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceVideoCoreAbortRequest();
// Empty Comment
void sceVideoCoreAcquireDecoderResource();
// Empty Comment
void sceVideoCoreAddStream();
// Empty Comment
void sceVideoCoreAsyncSendRequest();
// Empty Comment
void sceVideoCoreCancelThumbnail();
// Empty Comment
void sceVideoCoreChangeActiveStatus();
// Empty Comment
void sceVideoCoreDeleteStream();
// Empty Comment
void sceVideoCoreGetCanvasHandle();
// Empty Comment
void sceVideoCoreGetPlayStatus();
// Empty Comment
void sceVideoCoreGetPlayStatus2();
// Empty Comment
void sceVideoCoreGetStreamUid();
// Empty Comment
void sceVideoCoreRegistEventCallback();
// Empty Comment
void sceVideoCoreReleaseDecoderResource();
// Empty Comment
void sceVideoCoreSetInitializeInfo();
// Empty Comment
void sceVideoCoreSetPlaybackRange();
// Empty Comment
void sceVideoCoreSetThumbnailInfo();
// Empty Comment
void sceVideoCoreSyncSendRequest();
// Empty Comment
void sceVideoCoreUnregistEventCallback();


#endif

#ifdef __cplusplus
}
#endif