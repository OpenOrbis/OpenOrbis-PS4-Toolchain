#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceNgs2CalcWaveformBlock();
void sceNgs2CustomRackGetModuleInfo();
void sceNgs2FftInit();
void sceNgs2FftProcess();
void sceNgs2FftQuerySize();
void sceNgs2GeomApply();
void sceNgs2GeomCalcListener();
void sceNgs2GeomResetListenerParam();
void sceNgs2GeomResetSourceParam();
void sceNgs2GetWaveformFrameInfo();
void sceNgs2PanGetVolumeMatrix();
void sceNgs2PanInit();
void sceNgs2ParseWaveformData();
void sceNgs2ParseWaveformFile();
void sceNgs2ParseWaveformUser();
void sceNgs2RackCreate();
void sceNgs2RackCreateWithAllocator();
void sceNgs2RackDestroy();
void sceNgs2RackGetInfo();
void sceNgs2RackGetUserData();
void sceNgs2RackGetVoiceHandle();
void sceNgs2RackLock();
void sceNgs2RackQueryBufferSize();
void sceNgs2RackSetUserData();
void sceNgs2RackUnlock();
void sceNgs2ReportRegisterHandler();
void sceNgs2ReportUnregisterHandler();
void sceNgs2SystemCreate();
void sceNgs2SystemCreateWithAllocator();
void sceNgs2SystemDestroy();
void sceNgs2SystemEnumHandles();
void sceNgs2SystemEnumRackHandles();
void sceNgs2SystemGetInfo();
void sceNgs2SystemGetUserData();
void sceNgs2SystemLock();
void sceNgs2SystemQueryBufferSize();
void sceNgs2SystemRender();
void sceNgs2SystemSetGrainSamples();
void sceNgs2SystemSetSampleRate();
void sceNgs2SystemSetUserData();
void sceNgs2SystemUnlock();
void sceNgs2VoiceControl();
void sceNgs2VoiceGetMatrixInfo();
void sceNgs2VoiceGetOwner();
void sceNgs2VoiceGetPortInfo();
void sceNgs2VoiceGetState();
void sceNgs2VoiceGetStateFlags();
