#ifndef _SCE_FIBER_H_
#define _SCE_FIBER_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void _sceFiberAttachContextAndRun();
// Empty Comment
void _sceFiberAttachContextAndSwitch();
// Empty Comment
void _sceFiberGetThreadFramePointerAddress();
// Empty Comment
void _sceFiberInitializeImpl();
// Empty Comment
void _sceFiberInitializeWithInternalOptionImpl();
// Empty Comment
void sceFiberFinalize();
// Empty Comment
void sceFiberGetInfo();
// Empty Comment
void sceFiberGetSelf();
// Empty Comment
void sceFiberOptParamInitialize();
// Empty Comment
void sceFiberRename();
// Empty Comment
void sceFiberReturnToThread();
// Empty Comment
void sceFiberRun();
// Empty Comment
void sceFiberStartContextSizeCheck();
// Empty Comment
void sceFiberStopContextSizeCheck();
// Empty Comment
void sceFiberSwitch();

#endif

#ifdef __cplusplus
}
#endif