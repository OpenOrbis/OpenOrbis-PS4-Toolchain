#ifndef _SCE_MOVE_TRACKER_H_
#define _SCE_MOVE_TRACKER_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceMoveTrackerCalibrateReset();
// Empty Comment
void sceMoveTrackerCalibrateYaw();
// Empty Comment
void sceMoveTrackerCameraUpdate();
// Empty Comment
void sceMoveTrackerCaptureInit();
// Empty Comment
void sceMoveTrackerCaptureTerm();
// Empty Comment
void sceMoveTrackerControllersUpdate();
// Empty Comment
void sceMoveTrackerGetState();
// Empty Comment
void sceMoveTrackerGetVersion();
// Empty Comment
void sceMoveTrackerGetWorkingMemorySize();
// Empty Comment
void sceMoveTrackerInit();
// Empty Comment
void sceMoveTrackerPlayGetImages();
// Empty Comment
void sceMoveTrackerPlayGetStates();
// Empty Comment
void sceMoveTrackerPlayStart();
// Empty Comment
void sceMoveTrackerPlayStep();
// Empty Comment
void sceMoveTrackerRecordSave();
// Empty Comment
void sceMoveTrackerRecordStart();
// Empty Comment
void sceMoveTrackerRecordStop();
// Empty Comment
void sceMoveTrackerTerm();

#endif

#ifdef __cplusplus
}
#endif