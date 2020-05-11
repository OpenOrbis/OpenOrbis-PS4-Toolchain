#ifndef _SCE_AV_PLAYER_H_
#define _SCE_AV_PLAYER_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceAvPlayerAddSource();
// Empty Comment
void sceAvPlayerAddSourceEx();
// Empty Comment
void sceAvPlayerClose();
// Empty Comment
void sceAvPlayerCurrentTime();
// Empty Comment
void sceAvPlayerDisableStream();
// Empty Comment
void sceAvPlayerEnableStream();
// Empty Comment
void sceAvPlayerGetAudioData();
// Empty Comment
void sceAvPlayerGetStreamInfo();
// Empty Comment
void sceAvPlayerGetVideoData();
// Empty Comment
void sceAvPlayerGetVideoDataEx();
// Empty Comment
void sceAvPlayerInit();
// Empty Comment
void sceAvPlayerInitEx();
// Empty Comment
void sceAvPlayerIsActive();
// Empty Comment
void sceAvPlayerJumpToTime();
// Empty Comment
void sceAvPlayerPause();
// Empty Comment
void sceAvPlayerPostInit();
// Empty Comment
void sceAvPlayerResume();
// Empty Comment
void sceAvPlayerSetLogCallback();
// Empty Comment
void sceAvPlayerSetLooping();
// Empty Comment
void sceAvPlayerSetTrickSpeed();
// Empty Comment
void sceAvPlayerStart();
// Empty Comment
void sceAvPlayerStop();
// Empty Comment
void sceAvPlayerStreamCount();
// Empty Comment
void sceAvPlayerVprintf();


#endif

#ifdef __cplusplus
}
#endif