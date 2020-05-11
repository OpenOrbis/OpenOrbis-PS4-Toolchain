#ifndef _SCE_AUDIO_OUT_H
#define _SCE_AUDIO_OUT_H

#include <stdint.h>
#include <orbis/_types/audio_out.h>
#include <orbis/_types/user.h>

#if defined(__cplusplus)
extern "C" {
#endif

// Close the audio out handle & resource.
int32_t sceAudioOutClose(int32_t);

// Gets the last output process time.
int32_t sceAudioOutGetLastOutputTime(int32_t, uint64_t *);

// Gets the port state.
int32_t sceAudioOutGetPortState(int32_t, void *);

// Gets the system state
int32_t sceAudioOutGetSystemState(void *);

// Audio Out Init
int32_t sceAudioOutInit(void);

// document functions later
int32_t sceAudioOutMasteringGetState(void *);
int32_t sceAudioOutMasteringInit(uint32_t);

// Opens the audio port to the system.
int32_t sceAudioOutOpen(int32_t, int32_t, int32_t, uint32_t, uint32_t, uint32_t);

// document functions later
int32_t sceAudioOutOutput(int32_t, const void *);
int32_t sceAudioOutOutputs(void *, uint32_t);
int32_t sceAudioOutSetVolume(int32_t, int32_t, int32_t *);

// needs reversing... -cv
void sceAudioOutA3dControl();
void sceAudioOutA3dExit();
void sceAudioOutA3dInit();
void sceAudioOutAttachToApplicationByPid();
void sceAudioOutChangeAppModuleState();
void sceAudioOutDetachFromApplicationByPid();
void sceAudioOutExConfigureOutputMode();
void sceAudioOutExGetSystemInfo();
void sceAudioOutExPtClose();
void sceAudioOutExPtGetLastOutputTime();
void sceAudioOutExPtOpen();
void sceAudioOutExSystemInfoIsSupportedAudioOutExMode();
void sceAudioOutGetFocusEnablePid();
void sceAudioOutGetHandleStatusInfo();
void sceAudioOutGetInfo();
void sceAudioOutGetInfoOpenNum();
void sceAudioOutGetSimulatedHandleStatusInfo();
void sceAudioOutGetSimulatedHandleStatusInfo2();
void sceAudioOutGetSparkVss();
void sceAudioOutInitIpmiGetSession();
void sceAudioOutMasteringSetParam();
void sceAudioOutMasteringTerm();
void sceAudioOutMbusInit();
void sceAudioOutOpenEx();
void sceAudioOutPtClose();
void sceAudioOutPtGetLastOutputTime();
void sceAudioOutPtOpen();
void sceAudioOutSetConnections();
void sceAudioOutSetConnectionsForUser();
void sceAudioOutSetDevConnection();
void sceAudioOutSetHeadphoneOutMode();
void sceAudioOutSetJediJackVolume();
void sceAudioOutSetJediSpkVolume();
void sceAudioOutSetMainOutput();
void sceAudioOutSetMixLevelPadSpk();
void sceAudioOutSetMorpheusParam();
void sceAudioOutSetMorpheusWorkingMode();
void sceAudioOutSetPortConnections();
void sceAudioOutSetPortStatuses();
void sceAudioOutSetRecMode();
void sceAudioOutSetSparkParam();
void sceAudioOutSetUsbVolume();
void sceAudioOutSetVolumeDown();
void sceAudioOutStartAuxBroadcast();
void sceAudioOutStartSharePlay();
void sceAudioOutStopAuxBroadcast();
void sceAudioOutStopSharePlay();
void sceAudioOutSuspendResume();
void sceAudioOutSysConfigureOutputMode();
void sceAudioOutSysGetHdmiMonitorInfo();
void sceAudioOutSysGetSystemInfo();
void sceAudioOutSysHdmiMonitorInfoIsSupportedAudioOutMode();
void sceAudioOutSystemControlGet();
void sceAudioOutSystemControlSet();

#ifdef __cplusplus
}
#endif

#endif
