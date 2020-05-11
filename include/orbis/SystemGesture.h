#ifndef _SCE_SYSTEM_GESTURE_H_
#define _SCE_SYSTEM_GESTURE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceSystemGestureAppendTouchRecognizer();
// Empty Comment
void sceSystemGestureClose();
// Empty Comment
void sceSystemGestureCreateTouchRecognizer();
// Empty Comment
void sceSystemGestureFinalizePrimitiveTouchRecognizer();
// Empty Comment
void sceSystemGestureGetPrimitiveTouchEventByIndex();
// Empty Comment
void sceSystemGestureGetPrimitiveTouchEventByPrimitiveID();
// Empty Comment
void sceSystemGestureGetPrimitiveTouchEvents();
// Empty Comment
void sceSystemGestureGetPrimitiveTouchEventsCount();
// Empty Comment
void sceSystemGestureGetTouchEventByEventID();
// Empty Comment
void sceSystemGestureGetTouchEventByIndex();
// Empty Comment
void sceSystemGestureGetTouchEvents();
// Empty Comment
void sceSystemGestureGetTouchEventsCount();
// Empty Comment
void sceSystemGestureGetTouchRecognizerInformation();
// Empty Comment
void sceSystemGestureInitializePrimitiveTouchRecognizer();
// Empty Comment
void sceSystemGestureOpen();
// Empty Comment
void sceSystemGestureRemoveTouchRecognizer();
// Empty Comment
void sceSystemGestureResetPrimitiveTouchRecognizer();
// Empty Comment
void sceSystemGestureResetTouchRecognizer();
// Empty Comment
void sceSystemGestureUpdateAllTouchRecognizer();
// Empty Comment
void sceSystemGestureUpdatePrimitiveTouchRecognizer();
// Empty Comment
void sceSystemGestureUpdateTouchRecognizer();
// Empty Comment
void sceSystemGestureUpdateTouchRecognizerRectangle();

#endif

#ifdef __cplusplus
}
#endif