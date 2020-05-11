#ifndef _SCE_COMPOSITE_H_
#define _SCE_COMPOSITE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceCompositorCheckCrash();
// Empty Comment
void sceCompositorCommandGpuPerfBegin();
// Empty Comment
void sceCompositorCommandGpuPerfEnd();
// Empty Comment
void sceCompositorFlush();
// Empty Comment
void sceCompositorFlushWithRepeat();
// Empty Comment
void sceCompositorGetCanvasHandle();
// Empty Comment
void sceCompositorGetRemainedCommandNum();
// Empty Comment
void sceCompositorInit();
// Empty Comment
void sceCompositorMakeCanvasHandle();
// Empty Comment
void sceCompositorMapAnotherProcess();
// Empty Comment
void sceCompositorReleaseLocalStall();
// Empty Comment
void sceCompositorResetZoomCommand();
// Empty Comment
void sceCompositorSetCompositeCanvasCommandInC();
// Empty Comment
void sceCompositorSetCursorImageAddress();
// Empty Comment
void sceCompositorSetDebugPositionCommand();
// Empty Comment
void sceCompositorSetEndOfFrameCommand();
// Empty Comment
void sceCompositorSetEventCommand();
// Empty Comment
void sceCompositorSetFlipCommand();
// Empty Comment
void sceCompositorSetGameSufaceControlCommand();
// Empty Comment
void sceCompositorSetGnmContextCommand();
// Empty Comment
void sceCompositorSetIndirectCompositionCommand();
// Empty Comment
void sceCompositorSetIndirectRenderTargetConfigCommand();
// Empty Comment
void sceCompositorSetInvisibleCanvasCommand();
// Empty Comment
void sceCompositorSetLocalStallCommand();
// Empty Comment
void sceCompositorSetMemoryCommand();
// Empty Comment
void sceCompositorSetMorpheusState();
// Empty Comment
void sceCompositorSetPostEventCommand();
// Empty Comment
void sceCompositorSetRepeatCommand();
// Empty Comment
void sceCompositorSetResolutionCommand();
// Empty Comment
void sceCompositorSetZoomCommand();
// Empty Comment
void sceCompositorSystemConfig();
// Empty Comment
void sceCompositorWaitEndOfRendering();
// Empty Comment
void sceCompositorWaitEvent();
// Empty Comment
void sceCompositorWaitPostEvent();
// Empty Comment
void sceCompsoitorGetGpuClock();
// Empty Comment
void sceCompsoitorGetRenderingTime();

#endif

#ifdef __cplusplus
}
#endif