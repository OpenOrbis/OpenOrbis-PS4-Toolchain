#ifndef _SCE_NGS2_H_
#define _SCE_NGS2_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceNgs2CalcWaveformBlock();
// Empty Comment
void sceNgs2CustomRackGetModuleInfo();
// Empty Comment
void sceNgs2GeomApply();
// Empty Comment
void sceNgs2GeomCalcListener();
// Empty Comment
void sceNgs2GeomResetListenerParam();
// Empty Comment
void sceNgs2GeomResetSourceParam();
// Empty Comment
void sceNgs2GetWaveformFrameInfo();
// Empty Comment
void sceNgs2PanGetVolumeMatrix();
// Empty Comment
void sceNgs2PanInit();
// Empty Comment
void sceNgs2ParseWaveformData();
// Empty Comment
void sceNgs2ParseWaveformFile();
// Empty Comment
void sceNgs2ParseWaveformUser();
// Empty Comment
void sceNgs2RackCreate();
// Empty Comment
void sceNgs2RackCreateWithAllocator();
// Empty Comment
void sceNgs2RackDestroy();
// Empty Comment
void sceNgs2RackGetInfo();
// Empty Comment
void sceNgs2RackGetUserData();
// Empty Comment
void sceNgs2RackGetVoiceHandle();
// Empty Comment
void sceNgs2RackLock();
// Empty Comment
void sceNgs2RackQueryBufferSize();
// Empty Comment
void sceNgs2RackSetUserData();
// Empty Comment
void sceNgs2RackUnlock();
// Empty Comment
void sceNgs2ReportRegisterHandler();
// Empty Comment
void sceNgs2ReportUnregisterHandler();
// Empty Comment
void sceNgs2SystemCreate();
// Empty Comment
void sceNgs2SystemCreateWithAllocator();
// Empty Comment
void sceNgs2SystemDestroy();
// Empty Comment
void sceNgs2SystemEnumHandles();
// Empty Comment
void sceNgs2SystemEnumRackHandles();
// Empty Comment
void sceNgs2SystemGetInfo();
// Empty Comment
void sceNgs2SystemGetUserData();
// Empty Comment
void sceNgs2SystemLock();
// Empty Comment
void sceNgs2SystemQueryBufferSize();
// Empty Comment
void sceNgs2SystemRender();
// Empty Comment
void sceNgs2SystemSetGrainSamples();
// Empty Comment
void sceNgs2SystemSetSampleRate();
// Empty Comment
void sceNgs2SystemSetUserData();
// Empty Comment
void sceNgs2SystemUnlock();
// Empty Comment
void sceNgs2VoiceControl();
// Empty Comment
void sceNgs2VoiceGetMatrixInfo();
// Empty Comment
void sceNgs2VoiceGetOwner();
// Empty Comment
void sceNgs2VoiceGetPortInfo();
// Empty Comment
void sceNgs2VoiceGetState();
// Empty Comment
void sceNgs2VoiceGetStateFlags();

#endif

#ifdef __cplusplus
}
#endif