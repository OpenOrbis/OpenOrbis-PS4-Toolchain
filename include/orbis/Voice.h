#ifndef _SCE_VOICE_H_
#define _SCE_VOICE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceVoiceConnectIPortToOPort();
// Empty Comment
void sceVoiceCreatePort();
// Empty Comment
void sceVoiceDeletePort();
// Empty Comment
void sceVoiceDisconnectIPortFromOPort();
// Empty Comment
void sceVoiceEnd();
// Empty Comment
void sceVoiceGetBitRate();
// Empty Comment
void sceVoiceGetMuteFlag();
// Empty Comment
void sceVoiceGetPortAttr();
// Empty Comment
void sceVoiceGetPortInfo();
// Empty Comment
void sceVoiceGetResourceInfo();
// Empty Comment
void sceVoiceGetVolume();
// Empty Comment
void sceVoiceInit();
// Empty Comment
void sceVoicePausePort();
// Empty Comment
void sceVoicePausePortAll();
// Empty Comment
void sceVoiceReadFromOPort();
// Empty Comment
void sceVoiceResetPort();
// Empty Comment
void sceVoiceResumePort();
// Empty Comment
void sceVoiceResumePortAll();
// Empty Comment
void sceVoiceSetBitRate();
// Empty Comment
void sceVoiceSetMuteFlag();
// Empty Comment
void sceVoiceSetMuteFlagAll();
// Empty Comment
void sceVoiceSetThreadsParams();
// Empty Comment
void sceVoiceSetVolume();
// Empty Comment
void sceVoiceStart();
// Empty Comment
void sceVoiceStop();
// Empty Comment
void sceVoiceUpdatePort();
// Empty Comment
void sceVoiceVADAdjustment();
// Empty Comment
void sceVoiceWriteToIPort();


#endif

#ifdef __cplusplus
}
#endif