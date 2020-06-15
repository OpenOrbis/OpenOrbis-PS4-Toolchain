#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVoiceConnectIPortToOPort();
void sceVoiceCreatePort();
void sceVoiceDeletePort();
void sceVoiceDisconnectIPortFromOPort();
void sceVoiceEnd();
void sceVoiceGetBitRate();
void sceVoiceGetMuteFlag();
void sceVoiceGetPortAttr();
void sceVoiceGetPortInfo();
void sceVoiceGetResourceInfo();
void sceVoiceGetVolume();
void sceVoiceInit();
void sceVoicePausePort();
void sceVoicePausePortAll();
void sceVoiceReadFromOPort();
void sceVoiceResetPort();
void sceVoiceResumePort();
void sceVoiceResumePortAll();
void sceVoiceSetBitRate();
void sceVoiceSetMuteFlag();
void sceVoiceSetMuteFlagAll();
void sceVoiceSetThreadsParams();
void sceVoiceSetVolume();
void sceVoiceStart();
void sceVoiceStop();
void sceVoiceUpdatePort();
void sceVoiceVADAdjustment();
void sceVoiceVADSetVersion();
void sceVoiceWriteToIPort();
