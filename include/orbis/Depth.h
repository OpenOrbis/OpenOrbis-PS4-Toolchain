#ifndef _SCE_DEPTH_H_
#define _SCE_DEPTH_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceDepthGetCalibrationData();
// Empty Comment
void sceDepthGetImage();
// Empty Comment
void sceDepthHandCandidateTrackerGetResult();
// Empty Comment
void sceDepthHasCalibrationData();
// Empty Comment
void sceDepthHeadCandidateTrackerGetResult();
// Empty Comment
void sceDepthHeadCandidateTrackerSetValidationInformation();
// Empty Comment
void sceDepthInitialize();
// Empty Comment
void sceDepthLoadCalibrationData();
// Empty Comment
void sceDepthQueryMemory();
// Empty Comment
void sceDepthSetCalibrationData();
// Empty Comment
void sceDepthSetCommands();
// Empty Comment
void sceDepthSetRoi();
// Empty Comment
void sceDepthSubmit();
// Empty Comment
void sceDepthTerminate();
// Empty Comment
void sceDepthUpdate();
// Empty Comment
void sceDepthValidateCurrentCalibrationData();
// Empty Comment
void sceDepthWaitAndExecutePostProcess();

#endif

#ifdef __cplusplus
}
#endif
