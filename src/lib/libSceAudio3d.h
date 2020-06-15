#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceAudio3dAudioOutClose();
void sceAudio3dAudioOutOpen();
void sceAudio3dAudioOutOutput();
void sceAudio3dAudioOutOutputs();
void sceAudio3dBedWrite();
void sceAudio3dBedWrite2();
void sceAudio3dCreateSpeakerArray();
void sceAudio3dDeleteSpeakerArray();
void sceAudio3dGetDefaultOpenParameters();
void sceAudio3dGetSpeakerArrayMemorySize();
void sceAudio3dGetSpeakerArrayMixCoefficients();
void sceAudio3dInitialize();
void sceAudio3dObjectReserve();
void sceAudio3dObjectSetAttributes();
void sceAudio3dObjectUnreserve();
void sceAudio3dPortAdvance();
void sceAudio3dPortClose();
void sceAudio3dPortCreate();
void sceAudio3dPortDestroy();
void sceAudio3dPortFlush();
void sceAudio3dPortFreeState();
void sceAudio3dPortGetAttributesSupported();
void sceAudio3dPortGetList();
void sceAudio3dPortGetParameters();
void sceAudio3dPortGetQueueLevel();
void sceAudio3dPortGetState();
void sceAudio3dPortGetStatus();
void sceAudio3dPortOpen();
void sceAudio3dPortPush();
void sceAudio3dPortQueryDebug();
void sceAudio3dPortSetAttribute();
void sceAudio3dReportRegisterHandler();
void sceAudio3dReportUnregisterHandler();
void sceAudio3dSetGpuRenderer();
void sceAudio3dStrError();
void sceAudio3dTerminate();
