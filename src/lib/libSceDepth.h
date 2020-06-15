#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void _sceDepthCalcHeteroAdjustParam();
void _sceDepthHeadCandidateTrackerGetInformation();
void _sceDepthHeadCandidateTrackerSetInformation();
void _sceDepthSetCameraFactoryCalibrationData();
void _sceDepthSetHeteroAdjustParam();
void _sceDepthSetHeteroMode();
void sceDepthCalculateRectificationInformation();
void sceDepthDisableHeteroMode();
void sceDepthEnableExtendedMode();
void sceDepthEnableHeteroMode();
void sceDepthEnableHeteroModeAndGenerateInformation();
void sceDepthGetCalibrationData();
void sceDepthGetImage();
void sceDepthGetRectificationInformation();
void sceDepthGetSrParameter();
void sceDepthHandCandidateTrackerGetResult();
void sceDepthHasCalibrationData();
void sceDepthHeadCandidateDetectorGetResults();
void sceDepthHeadCandidateTrackerGetResult();
void sceDepthHeadCandidateTrackerSetValidationInformation();
void sceDepthInitialize();
void sceDepthLoadCalibrationData();
void sceDepthQueryMemory();
void sceDepthSaveInternalBuffers();
void sceDepthSetCalibrationData();
void sceDepthSetCommands();
void sceDepthSetPostFilterParameter();
void sceDepthSetPreFilterParameter();
void sceDepthSetRectificationInformation();
void sceDepthSetRoi();
void sceDepthSetRoiset();
void sceDepthSetSrParameter();
void sceDepthSetSrTnrParameter();
void sceDepthSubmit();
void sceDepthTerminate();
void sceDepthUpdate();
void sceDepthValidateCurrentCalibrationData();
void sceDepthWaitAndExecutePostProcess();
