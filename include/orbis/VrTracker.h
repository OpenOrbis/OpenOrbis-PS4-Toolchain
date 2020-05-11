#ifndef _SCE_VR_TRACKER_H_
#define _SCE_VR_TRACKER_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceVrTrackerCpuProcess();
// Empty Comment
void sceVrTrackerGetPlayAreaWarningInfo();
// Empty Comment
void sceVrTrackerGetResult();
// Empty Comment
void sceVrTrackerGetTime();
// Empty Comment
void sceVrTrackerGpuSubmit();
// Empty Comment
void sceVrTrackerGpuWait();
// Empty Comment
void sceVrTrackerGpuWaitAndCpuProcess();
// Empty Comment
void sceVrTrackerInit();
// Empty Comment
void sceVrTrackerNotifyEndOfCpuProcess();
// Empty Comment
void sceVrTrackerQueryMemory();
// Empty Comment
void sceVrTrackerRecalibrate();
// Empty Comment
void sceVrTrackerRegisterDevice();
// Empty Comment
void sceVrTrackerRegisterDeviceInternal();
// Empty Comment
void sceVrTrackerResetOrientationRelative();
// Empty Comment
void sceVrTrackerSetDurationUntilStatusNotTracking();
// Empty Comment
void sceVrTrackerTerm();
// Empty Comment
void sceVrTrackerUnregisterDevice();
// Empty Comment
void sceVrTrackerUpdateMotionSensorData();


#endif

#ifdef __cplusplus
}
#endif