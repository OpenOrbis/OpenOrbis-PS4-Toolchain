#ifndef _SCE_AUDIO_3D_H_
#define _SCE_AUDIO_3D_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceAudio3dAudioOutClose();
// Empty Comment
void sceAudio3dAudioOutOpen();
// Empty Comment
void sceAudio3dAudioOutOutput();
// Empty Comment
void sceAudio3dAudioOutOutputs();
// Empty Comment
void sceAudio3dBedWrite();
// Empty Comment
void sceAudio3dCreateSpeakerArray();
// Empty Comment
void sceAudio3dDeleteSpeakerArray();
// Empty Comment
void sceAudio3dGetDefaultOpenParameters();
// Empty Comment
void sceAudio3dGetSpeakerArrayMemorySize();
// Empty Comment
void sceAudio3dGetSpeakerArrayMixCoefficients();
// Empty Comment
void sceAudio3dInitialize();
// Empty Comment
void sceAudio3dObjectReserve();
// Empty Comment
void sceAudio3dObjectSetAttributes();
// Empty Comment
void sceAudio3dObjectUnreserve();
// Empty Comment
void sceAudio3dPortAdvance();
// Empty Comment
void sceAudio3dPortClose();
// Empty Comment
void sceAudio3dPortCreate();
// Empty Comment
void sceAudio3dPortDestroy();
// Empty Comment
void sceAudio3dPortFlush();
// Empty Comment
void sceAudio3dPortFreeState();
// Empty Comment
void sceAudio3dPortGetAttributesSupported();
// Empty Comment
void sceAudio3dPortGetList();
// Empty Comment
void sceAudio3dPortGetParameters();
// Empty Comment
void sceAudio3dPortGetQueueLevel();
// Empty Comment
void sceAudio3dPortGetState();
// Empty Comment
void sceAudio3dPortGetStatus();
// Empty Comment
void sceAudio3dPortOpen();
// Empty Comment
void sceAudio3dPortPush();
// Empty Comment
void sceAudio3dPortSetAttribute();
// Empty Comment
void sceAudio3dStrError();
// Empty Comment
void sceAudio3dTerminate();

#endif

#ifdef __cplusplus
}
#endif