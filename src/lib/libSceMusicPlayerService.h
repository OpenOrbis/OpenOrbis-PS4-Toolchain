#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceMusicPlayerServiceBeginTransaction();
void sceMusicPlayerServiceCreateTrackList();
void sceMusicPlayerServiceEndTransaction();
void sceMusicPlayerServiceGetAudioVolume();
void sceMusicPlayerServiceGetCurrentPlayStatus();
void sceMusicPlayerServiceGetPlaybackResults();
void sceMusicPlayerServiceGetPlayStatusExtension();
void sceMusicPlayerServiceGetTrackInfo();
void sceMusicPlayerServiceGetTrackListVersion();
void sceMusicPlayerServiceInitialize();
void sceMusicPlayerServiceInitialize2();
void sceMusicPlayerServiceInitialize3();
void sceMusicPlayerServiceInsertTrackEntry();
void sceMusicPlayerServiceNextTrack();
void sceMusicPlayerServicePause();
void sceMusicPlayerServicePlay();
void sceMusicPlayerServicePlayStartByTime();
void sceMusicPlayerServicePreviousTrack();
void sceMusicPlayerServiceReceiveEvent();
void sceMusicPlayerServiceRemoveAllData();
void sceMusicPlayerServiceRemoveTrackEntry();
void sceMusicPlayerServiceRemoveTrackList();
void sceMusicPlayerServiceSeek();
void sceMusicPlayerServiceSetAudioVolume();
void sceMusicPlayerServiceSetRepeatMode();
void sceMusicPlayerServiceSetShuffle();
void sceMusicPlayerServiceSetTrackList();
void sceMusicPlayerServiceSetTrackList2();
void sceMusicPlayerServiceSetUsbStorageDeviceInfo();
void sceMusicPlayerServiceStop();
void sceMusicPlayerServiceTerminate();
void sceMusicPlayerServiceUnpause();
