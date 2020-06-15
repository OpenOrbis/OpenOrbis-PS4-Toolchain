#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVrTrackerCpuProcess();
void sceVrTrackerGetPlayAreaWarningInfo();
void sceVrTrackerGetResult();
void sceVrTrackerGetTime();
void sceVrTrackerGpuSubmit();
void sceVrTrackerGpuWait();
void sceVrTrackerGpuWaitAndCpuProcess();
void sceVrTrackerInit();
void sceVrTrackerNotifyEndOfCpuProcess();
void sceVrTrackerQueryMemory();
void sceVrTrackerRecalibrate();
void sceVrTrackerRegisterDevice();
void sceVrTrackerRegisterDeviceInternal();
void sceVrTrackerResetAll();
void sceVrTrackerResetOrientationRelative();
void sceVrTrackerSaveInternalBuffers();
void sceVrTrackerSetDurationUntilStatusNotTracking();
void sceVrTrackerSetExtendedMode();
void sceVrTrackerSetLEDBrightness();
void sceVrTrackerSetRestingMode();
void sceVrTrackerTerm();
void sceVrTrackerUnregisterDevice();
void sceVrTrackerUpdateMotionSensorData();
