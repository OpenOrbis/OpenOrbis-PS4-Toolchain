#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceRazorCpuBeginLogicalFileAccess();
void sceRazorCpuDisableFiberUserMarkers();
void sceRazorCpuEndLogicalFileAccess();
void sceRazorCpuFiberLogNameChange();
void sceRazorCpuFiberSwitch();
void sceRazorCpuFlushOccurred();
void sceRazorCpuGetDataTagStorageSize();
void sceRazorCpuGpuMarkerSync();
void sceRazorCpuInitDataTags();
void sceRazorCpuInitializeGpuMarkerContext();
void sceRazorCpuInitializeInternal();
void sceRazorCpuIsCapturing();
void sceRazorCpuJobManagerDispatch();
void sceRazorCpuJobManagerJob();
void sceRazorCpuJobManagerSequence();
void sceRazorCpuPlotValue();
void sceRazorCpuPopMarker();
void sceRazorCpuPushMarker();
void sceRazorCpuPushMarkerStatic();
void sceRazorCpuResizeTaggedBuffer();
void sceRazorCpuSetPopMarkerCallback();
void sceRazorCpuSetPushMarkerCallback();
void sceRazorCpuSetPushMarkerStaticCallback();
void sceRazorCpuShutdownDataTags();
void sceRazorCpuStartCaptureInternal();
void sceRazorCpuStopCaptureInternal();
void sceRazorCpuSync();
void sceRazorCpuTagArray();
void sceRazorCpuTagBuffer();
void sceRazorCpuUnTagBuffer();
void sceRazorCpuWriteBookmark();
