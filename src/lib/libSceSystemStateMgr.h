#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceSystemStateMgrCancelShutdownTimer();
void sceSystemStateMgrEnterMediaPlaybackMode();
void sceSystemStateMgrEnterStandby();
void sceSystemStateMgrExtendShutdownTimer();
void sceSystemStateMgrExtendShutdownTimerForPostAutoUpdateProcess();
void sceSystemStateMgrGetCurrentState();
void sceSystemStateMgrGetTriggerCode();
void sceSystemStateMgrIsBdDriveReady();
void sceSystemStateMgrIsGpuPerformanceNormal();
void sceSystemStateMgrIsShellUIShutdownInProgress();
void sceSystemStateMgrIsStandbyModeEnabled();
void sceSystemStateMgrLeaveMediaPlaybackMode();
void sceSystemStateMgrNotifySystemSuspendResumeProgress();
void sceSystemStateMgrReboot();
void sceSystemStateMgrSendCecOneTouchPlayCommand();
void sceSystemStateMgrStartRebootTimer();
void sceSystemStateMgrStartShutdownTimer();
void sceSystemStateMgrStartStadbyTimer();
void sceSystemStateMgrStartVshAutoUpdateTimer();
void sceSystemStateMgrTickMusicPlayback();
void sceSystemStateMgrTickPartyChat();
void sceSystemStateMgrTurnOff();
void sceSystemStateMgrVshAutoUpdate();
void sceSystemStateMgrWaitVshAutoUpdateVerifyDone();
void sceSystemStateMgrWakeUp();
