#ifndef _SCE_MUSIC_CORE_SERVER_CLIENT_H_
#define _SCE_MUSIC_CORE_SERVER_CLIENT_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceMusicCoreServerForceKillCurrentCore();
// Empty Comment
void sceMusicCoreServerGetCoreInfo();
// Empty Comment
void sceMusicCoreServerGetEvent();
// Empty Comment
void sceMusicCoreServerGetPlayStartCondition();
// Empty Comment
void sceMusicCoreServerGetPlayStatus();
// Empty Comment
void sceMusicCoreServerGetSpTrackInfo();
// Empty Comment
void sceMusicCoreServerGetSpWakeupAuthorityList();
// Empty Comment
void sceMusicCoreServerGetStatusOfTracks();
// Empty Comment
void sceMusicCoreServerGetTitleId();
// Empty Comment
void sceMusicCoreServerGetTrackInfo();
// Empty Comment
void sceMusicCoreServerInitialize();
// Empty Comment
void sceMusicCoreServerKillCurrentCore();
// Empty Comment
void sceMusicCoreServerLaunchSpCore();
// Empty Comment
void sceMusicCoreServerLaunchUsbMusicCore();
// Empty Comment
void sceMusicCoreServerPlayControl();
// Empty Comment
void sceMusicCoreServerPlaySpUri();
// Empty Comment
void sceMusicCoreServerSetAudioVolume();
// Empty Comment
void sceMusicCoreServerSetRepeatMode();
// Empty Comment
void sceMusicCoreServerSetShuffle();
// Empty Comment
void sceMusicCoreServerSetSpWakeupAuthorityList();
// Empty Comment
void sceMusicCoreServerSetTrackList();
// Empty Comment
void sceMusicCoreServerTerminate();

#endif

#ifdef __cplusplus
}
#endif