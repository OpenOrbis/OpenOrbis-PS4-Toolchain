#ifndef _SCE_GNM_DRIVER_H_
#define _SCE_GNM_DRIVER_H_

#include <stdint.h>
#include <orbis/_types/gnm.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceGnmAddEqEvent();
// Checks if any draw or compute submission will stall sceGnmSubmitDone()
// Returns 1 if it won't stall, and 0 if it will
int32_t sceGnmAreSubmitsAllowed(void);
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
// numdwords must be 10, and 10 DWORDS must be available in cmd.
int32_t sceGnmDrawIndex(
	uint32_t* cmd, uint32_t numdwords, uint32_t indexcount,
	const void* indexaddr, OrbisGnmDrawFlags flags
);
// Queue a draw instruction using auto generated indices
// into the command buffer.
// numdwords must be 7, and 7 DWORDS must be available in cmd.
int32_t sceGnmDrawIndexAuto(
	uint32_t* cmd, uint32_t numdwords, uint32_t indexcount,
	OrbisGnmDrawFlags flags
);
// Empty Comment
void sceGnmDrawIndexIndirect();
// Empty Comment
void sceGnmDrawIndexIndirectMulti();
// Empty Comment
void sceGnmDrawIndexMultiInstanced();
// Empty Comment
void sceGnmDrawIndexOffset();
// Queue an indirect draw instruction into the command buffer.
// numdwords must be 9, and 9 DWORDS must be available in cmd.
int32_t sceGnmDrawIndirect(
	uint32_t* cmd, uint32_t numdwords, uint32_t dataoffset,
	uint32_t stage, uint8_t vertexoffusersgpr, uint8_t instanceoffusersgpr,
	OrbisGnmDrawFlags flags
);
// Empty Comment
void sceGnmDrawIndirectMulti();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState175();
// Empty Comment
void sceGnmDrawInitDefaultHardwareState200();
// Sets the hardware's graphics ring state to its default values.
// numdwords must be 256, and 256 DWORDS must be available in cmd.
int32_t sceGnmDrawInitDefaultHardwareState350(
	uint32_t* cmd, uint32_t numdwords
);
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
// Sets a predefined pixel shader according to the shader ID
// to be used in the command buffer.
// Available shader IDs:
// - 0: Empty shader
// - 1: Empty shader exporting 32 bit R and G
// Any other ID will return an error.
// numdwords must be 40, and 40 DWORDS must be available in cmd.
int32_t sceGnmSetEmbeddedPsShader(
	uint32_t* cmd, uint32_t numdwords, int32_t shaderid
);
// Sets a predefined vertex shader according to the shader ID
// to be used in the command buffer.
// Available shader IDs:
// - 0: Fullscreen quad shader
// Any other ID will return an error.
// numdwords must be 29, and 29 DWORDS must be available in cmd.
int32_t sceGnmSetEmbeddedVsShader(
	uint32_t* cmd, uint32_t numdwords,
	int32_t shaderid, uint32_t shadermodifier
);
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
// numdwords must be 40, and 40 DWORDS must be available in cmd.
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
// numdwords must be 29, and 29 DWORDS must be available in cmd.
int32_t sceGnmSetVsShader(
	uint32_t* cmd, uint32_t numdwords,
	const void* vsregs, uint32_t shadermodifier
);
// Empty Comment
void sceGnmSetWaveLimitMultipliers();
// Submit one or more draw command buffer, and optionally one or more compute command buffers,
// then flip a registered video buffer.
int32_t sceGnmSubmitAndFlipCommandBuffers(
	uint32_t count, void* dcbaddrs[], uint32_t* dcbbytesizes,
	void* ccbaddrs[], uint32_t* ccbbytesizes, uint32_t videohandle,
	uint32_t displaybufidx, uint32_t flipmode, uint64_t fliparg
);
// Empty Comment
void sceGnmSubmitAndFlipCommandBuffersForWorkload();
// Submit one or more draw command buffer, and optionally one or more compute command buffers.
int32_t sceGnmSubmitCommandBuffers(
	uint32_t count, void* dcbaddrs[], uint32_t* dcbbytesizes,
	void* ccbaddrs[], uint32_t* ccbbytesizes
);
// Empty Comment
void sceGnmSubmitCommandBuffersForWorkload();
// Tell the driver that all command buffers were submitted for this frame.
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
