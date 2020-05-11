#ifndef _SCE_VOICE_QOS_H_
#define _SCE_VOICE_QOS_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceVoiceQoSConnect();
// Empty Comment
void sceVoiceQoSCreateLocalEndpoint();
// Empty Comment
void sceVoiceQoSCreateRemoteEndpoint();
// Empty Comment
void sceVoiceQoSDebugGetStatus();
// Empty Comment
void sceVoiceQoSDeleteLocalEndpoint();
// Empty Comment
void sceVoiceQoSDeleteRemoteEndpoint();
// Empty Comment
void sceVoiceQoSDisconnect();
// Empty Comment
void sceVoiceQoSEnd();
// Empty Comment
void sceVoiceQoSGetConnectionAttribute();
// Empty Comment
void sceVoiceQoSGetLocalEndpoint();
// Empty Comment
void sceVoiceQoSGetLocalEndpointAttribute();
// Empty Comment
void sceVoiceQoSGetRemoteEndpoint();
// Empty Comment
void sceVoiceQoSGetRemoteEndpointAttribute();
// Empty Comment
void sceVoiceQoSGetStatus();
// Empty Comment
void sceVoiceQoSInit();
// Empty Comment
void sceVoiceQoSReadPacket();
// Empty Comment
void sceVoiceQoSSetConnectionAttribute();
// Empty Comment
void sceVoiceQoSSetLocalEndpointAttribute();
// Empty Comment
void sceVoiceQoSSetRemoteEndpointAttribute();
// Empty Comment
void sceVoiceQoSWritePacket();


#endif

#ifdef __cplusplus
}
#endif