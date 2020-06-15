#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVideoCoreAbortRequest();
void sceVideoCoreAcquireDecoderResource();
void sceVideoCoreAcquireDecoderResourceForBeWrapper();
void sceVideoCoreAddStream();
void sceVideoCoreAsyncAddStream();
void sceVideoCoreAsyncSendRequest();
void sceVideoCoreCancelThumbnail();
void sceVideoCoreChangeActiveStatus();
void sceVideoCoreChangeAudioStream();
void sceVideoCoreChangeDisplaySize();
void sceVideoCoreChangeHdcpSetting();
void sceVideoCoreChangeSubtitle();
void sceVideoCoreDeleteStream();
void sceVideoCoreGenerateThumbnail();
void sceVideoCoreGenerateThumbnail2();
void sceVideoCoreGetCanvasHandle();
void sceVideoCoreGetPlayStatus();
void sceVideoCoreGetPlayStatus2();
void sceVideoCoreGetStreamUid();
void sceVideoCoreGetThumbnail();
void sceVideoCoreGetThumbnail2();
void sceVideoCoreLaunchVideoCore();
void sceVideoCoreMediaSourceAppendData();
void sceVideoCoreMediaSourceEndOfStream();
void sceVideoCoreMediaSourceSetDuration();
void sceVideoCoreMediaSourceSetTimestampOffset();
void sceVideoCorePlayControl();
void sceVideoCoreRegistEventCallback();
void sceVideoCoreReleaseDecoderResource();
void sceVideoCoreReleaseDecoderResourceForBeWrapper();
void sceVideoCoreSetAudioMute();
void sceVideoCoreSetAudioVolume();
void sceVideoCoreSetFullScreen();
void sceVideoCoreSetInitialInfo();
void sceVideoCoreSetInitializeInfo();
void sceVideoCoreSetPlaybackRange();
void sceVideoCoreSetThumbnailInfo();
void sceVideoCoreSyncAddStream();
void sceVideoCoreSyncSendRequest();
void sceVideoCoreUnregistEventCallback();
