#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVoiceQoSConnect();
void sceVoiceQoSCreateLocalEndpoint();
void sceVoiceQoSCreateRemoteEndpoint();
void sceVoiceQoSDebugGetStatus();
void sceVoiceQoSDeleteLocalEndpoint();
void sceVoiceQoSDeleteRemoteEndpoint();
void sceVoiceQoSDisconnect();
void sceVoiceQoSEnd();
void sceVoiceQoSGetConnectionAttribute();
void sceVoiceQoSGetLocalEndpoint();
void sceVoiceQoSGetLocalEndpointAttribute();
void sceVoiceQoSGetRemoteEndpoint();
void sceVoiceQoSGetRemoteEndpointAttribute();
void sceVoiceQoSGetStatus();
void sceVoiceQoSInit();
void sceVoiceQoSReadPacket();
void sceVoiceQoSSetConnectionAttribute();
void sceVoiceQoSSetLocalEndpointAttribute();
void sceVoiceQoSSetRemoteEndpointAttribute();
void sceVoiceQoSWritePacket();
