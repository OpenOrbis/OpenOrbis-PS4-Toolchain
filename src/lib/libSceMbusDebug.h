#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceMbusDebugAcquireControl();
void sceMbusDebugAcquireControlWithState();
void sceMbusDebugAcquireControlWithState2();
void sceMbusDebugAcquireControlWithStateFlag();
void sceMbusDebugAddProcess();
void sceMbusDebugCheckProcessResume();
void sceMbusDebugDisableBgmForShellUi();
void sceMbusDebugGetApplicationStartupInfo();
void sceMbusDebugGetControlStatus();
void sceMbusDebugGetDeviceInfo();
void sceMbusDebugGetInternalInfo();
void sceMbusDebugGetPriorityInfo();
void sceMbusDebugReenableBgmForShellUi();
void sceMbusDebugReleaseControl();
void sceMbusDebugRemoveCameraAppModuleFocus();
void sceMbusDebugResumeApplication();
void sceMbusDebugSetApplicationFocusByAppId();
void sceMbusDebugSetCameraAppModuleFocus();
void sceMbusDebugSetControllerFocusByAppId();
void sceMbusDebugSetOtherProcessExcludedAction();
void sceMbusDebugSetPriority();
void sceMbusDebugStartApplication();
void sceMbusDebugStartApplication2();
void sceMbusDebugStartApplicationNull();
void sceMbusDebugSuspendApplication();
void sceMbusDebugTerminateApplication();
void sceMbusDebugTerminateProcess();
