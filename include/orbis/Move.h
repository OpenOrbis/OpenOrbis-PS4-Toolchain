#ifndef _SCE_MOVE_H_
#define _SCE_MOVE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceMoveClose();
// Empty Comment
void sceMoveGetDeviceInfo();
// Empty Comment
void sceMoveGetExtensionPortInfo();
// Empty Comment
void sceMoveInit();
// Empty Comment
void sceMoveOpen();
// Empty Comment
void sceMoveReadStateLatest();
// Empty Comment
void sceMoveReadStateRecent();
// Empty Comment
void sceMoveResetLightSphere();
// Empty Comment
void sceMoveSetExtensionPortOutput();
// Empty Comment
void sceMoveSetLightSphere();
// Empty Comment
void sceMoveSetVibration();
// Empty Comment
void sceMoveTerm();

#endif

#ifdef __cplusplus
}
#endif