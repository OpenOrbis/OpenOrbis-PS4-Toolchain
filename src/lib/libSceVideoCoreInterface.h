#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVideoCoreInterfaceAddVblankEvent();
void sceVideoCoreInterfaceCloseCanvas();
void sceVideoCoreInterfaceCloseVideoOut();
void sceVideoCoreInterfaceCreateCanvasContext();
void sceVideoCoreInterfaceCreateFrameBufferContext();
void sceVideoCoreInterfaceDestroyCanvasContext();
void sceVideoCoreInterfaceDestroyFrameBufferContext();
void sceVideoCoreInterfaceFinishRendering();
void sceVideoCoreInterfaceFlushVideoOutBuffer();
void sceVideoCoreInterfaceGetCanvasVideoBufferAddress();
void sceVideoCoreInterfaceGetCanvasVideoBufferSize();
void sceVideoCoreInterfaceGetRenderFrameBuffer();
void sceVideoCoreInterfaceInitializeInterface();
void sceVideoCoreInterfaceLoadModule();
void sceVideoCoreInterfaceMainLoop();
void sceVideoCoreInterfaceOpenCanvas();
void sceVideoCoreInterfaceOpenVideoOut();
void sceVideoCoreInterfaceSetCanvasId();
void sceVideoCoreInterfaceSetFunctionTable();
void sceVideoCoreInterfaceSetFunctionTableExt();
void sceVideoCoreInterfaceSetVideoOutBufferInfo();
void sceVideoCoreInterfaceSubmitCanvases();
void sceVideoCoreInterfaceUnloadModule();
void sceVideoCoreInterfaceWaitCanvasFlip();
