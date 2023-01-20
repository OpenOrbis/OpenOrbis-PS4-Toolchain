#ifndef _SCE_GNM_DRIVER_H_
#define _SCE_GNM_DRIVER_H_

#include <stdint.h>
#include <orbis/_types/gnm.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceGnmAddEqEvent();
// Empty Comment
void sceGnmAreSubmitsAllowed();
// Empty Comment
void sceGnmBeginWorkload();
// Empty Comment
void sceGnmCreateWorkloadStream();
// Empty Comment
void sceGnmDebugHardwareStatus();
// Empty Comment
void sceGnmDeleteEqEvent();
// Empty Comment
void sceGnmDestroyWorkloadStream();
// Empty Comment
void sceGnmDingDong();
// Empty Comment
void sceGnmDingDongForWorkload();
// Empty Comment
void sceGnmDisableMipStatsReport();
// Empty Comment
void sceGnmDispatchDirect();
// Empty Comment
void sceGnmDispatchIndirect();
// Empty Comment
void sceGnmDispatchIndirectOnMec();
// Empty Comment
void sceGnmDispatchInitDefaultHardwareState();
// Queue a draw indexed instruction into the command buffer.
int32_t sceGnmDrawIndex(
	uint32_t* cmd, uint32_t numdwords, uint32_t indexcount,
	const void* indexaddr, OrbisGnmDrawIndexFlags flags
);
// Empty Comment
void sceGnmDrawIndexAuto();
// Empty Comment
void sceGnmDrawIndexIndirect();
// Empty Comment
void sceGnmDrawIndexIndirectMulti();
// Empty Comment
void sceGnmDrawIndexMultiInstanced();
// Empty Comment
void sceGnmDrawIndexOffset();
// Empty Comment
void sceGnmDrawIndirect();
// Empty Comment
void sceGnmDrawIndirectMulti();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState175();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState200();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState350();
// Empty Comment
void sceGnmDrawInitToDefaultContextState();
// Empty Comment
void sceGnmDrawOpaqueAuto();
// Empty Comment
void sceGnmDriverCaptureInProgress();
// Empty Comment
void sceGnmDriverTraceInProgress();
// Empty Comment
void sceGnmDriverTriggerCapture();
// Empty Comment
void sceGnmEndWorkload();
// Empty Comment
void sceGnmFindResourcesPublic();
// Empty Comment
void sceGnmFlushGarlic(void);
// Empty Comment
void sceGnmGetEqEventType();
// Empty Comment
void sceGnmGetEqTimeStamp();
// Empty Comment
void sceGnmGetGpuBlockStatus();
// Empty Comment
void sceGnmGetGpuInfoStatus();
// Empty Comment
void sceGnmGetLastWaitedAddress();
// Empty Comment
void sceGnmGetNumTcaUnits();
// Empty Comment
void sceGnmGetOwnerName();
// Empty Comment
void sceGnmGetProtectionFaultTimeStamp();
// Empty Comment
void sceGnmGetResourceBaseAddressAndSizeInBytes();
// Empty Comment
void sceGnmGetResourceName();
// Empty Comment
void sceGnmGetResourceShaderGuid();
// Empty Comment
void sceGnmGetResourceType();
// Empty Comment
void sceGnmGetResourceUserData();
// Empty Comment
void sceGnmGetShaderProgramBaseAddress();
// Empty Comment
void sceGnmGetShaderStatus();
// Empty Comment
void sceGnmGetTheTessellationFactorRingBufferBaseAddress();
// Empty Comment
void sceGnmInsertPopMarker();
// Empty Comment
void sceGnmInsertPushColorMarker();
// Empty Comment
void sceGnmInsertPushMarker();
// Empty Comment
void sceGnmInsertSetColorMarker();
// Empty Comment
void sceGnmInsertSetMarker();
// Empty Comment
void sceGnmInsertThreadTraceMarker();
// Empty Comment
void sceGnmInsertWaitFlipDone();
// Empty Comment
void sceGnmIsUserPaEnabled();
// Empty Comment
void sceGnmLogicalCuIndexToPhysicalCuIndex();
// Empty Comment
void sceGnmLogicalCuMaskToPhysicalCuMask();
// Empty Comment
void sceGnmMapComputeQueue();
// Empty Comment
void sceGnmMapComputeQueueWithPriority();
// Empty Comment
void sceGnmQueryResourceRegistrationUserMemoryRequirements();
// Empty Comment
void sceGnmRegisterGdsResource();
// Empty Comment
void sceGnmRegisterGnmLiveCallbackConfig();
// Empty Comment
void sceGnmRegisterOwner();
// Empty Comment
void sceGnmRegisterResource();
// Empty Comment
void sceGnmRequestFlipAndSubmitDone();
// Empty Comment
void sceGnmRequestFlipAndSubmitDoneForWorkload();
// Empty Comment
void sceGnmRequestMipStatsReportAndReset();
// Empty Comment
void sceGnmResetVgtControl();
// Empty Comment
void sceGnmSetCsShader();
// Empty Comment
void sceGnmSetCsShaderWithModifier();
// Empty Comment
void sceGnmSetEmbeddedPsShader();
// Empty Comment
void sceGnmSetEmbeddedVsShader();
// Empty Comment
void sceGnmSetEsShader();
// Empty Comment
void sceGnmSetGsRingSizes();
// Empty Comment
void sceGnmSetGsShader();
// Empty Comment
void sceGnmSetHsShader();
// Empty Comment
void sceGnmSetLsShader();
// Set the pixel shader to be used in the command buffer.
int32_t sceGnmSetPsShader(
	uint32_t* cmd, uint32_t numdwords, const void* psregs
);
// Set the pixel shader to be used in the command buffer.
int32_t sceGnmSetPsShader350(
	uint32_t* cmd, uint32_t numdwords, const void* psregs
);
// Empty Comment
void sceGnmSetResourceRegistrationUserMemory();
// Empty Comment
void sceGnmSetResourceUserData();
// Empty Comment
void sceGnmSetSpiEnableSqCounters();
// Empty Comment
void sceGnmSetSpiEnableSqCountersForUnitInstance();
// Empty Comment
void sceGnmSetupMipStatsReport();
// Empty Comment
void sceGnmSetVgtControl();
// Set the vertex shader to be used in the command buffer.
int32_t sceGnmSetVsShader(
	uint32_t* cmd, uint32_t numdwords,
	const void* vsregs, uint32_t shadermodifier
);
// Empty Comment
void sceGnmSetWaveLimitMultipliers();
// Empty Comment
void sceGnmSubmitAndFlipCommandBuffers();
// Empty Comment
void sceGnmSubmitAndFlipCommandBuffersForWorkload();
// Submit one or more draw command buffer, and optionally one or more compute command buffers.
int32_t sceGnmSubmitCommandBuffers(
	uint32_t count, void* dcbaddrs[], uint32_t* dcbbytesizes,
	void* ccbaddrs[], uint32_t* ccbbytesizes
);
// Empty Comment
void sceGnmSubmitCommandBuffersForWorkload();
// Empty Comment
int32_t sceGnmSubmitDone(void);
// Empty Comment
void sceGnmUnmapComputeQueue();
// Empty Comment
void sceGnmUnregisterAllResourcesForOwner();
// Empty Comment
void sceGnmUnregisterOwnerAndResources();
// Empty Comment
void sceGnmUnregisterResource();
// Empty Comment
void sceGnmUpdateGsShader();
// Empty Comment
void sceGnmUpdateHsShader();
// Empty Comment
void sceGnmUpdatePsShader();
// Empty Comment
void sceGnmUpdatePsShader350();
// Empty Comment
void sceGnmUpdateVsShader();
// Empty Comment
void sceGnmValidateCommandBuffers();
// Empty Comment
void sceGnmValidateDisableDiagnostics();
// Empty Comment
void sceGnmValidateDispatchCommandBuffers();
// Empty Comment
void sceGnmValidateDrawCommandBuffers();
// Empty Comment
void sceGnmValidateGetDiagnosticInfo();
// Empty Comment
void sceGnmValidateGetDiagnostics();
// Empty Comment
void sceGnmValidateGetVersion();
// Empty Comment
void sceGnmValidateOnSubmitEnabled();
// Empty Comment
void sceGnmValidateResetState();
// Empty Comment
void sceGnmValidationRegisterMemoryCheckCallback();
// Empty Comment
void sceRazorCaptureCommandBuffersOnlyImmediate();
// Empty Comment
void sceRazorCaptureCommandBuffersOnlySinceLastFlip();
// Empty Comment
void sceRazorCaptureImmediate();
// Empty Comment
void sceRazorCaptureSinceLastFlip();
// Empty Comment
void sceRazorIsLoaded();


#ifdef __cplusplus
}
#endif

#endif
