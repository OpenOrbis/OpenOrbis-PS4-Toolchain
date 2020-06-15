#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVdecCoreCreateDecoder();
void sceVdecCoreDeleteDecoder();
void sceVdecCoreFinalizeComputeResource();
void sceVdecCoreFlushDecodeOutput();
void sceVdecCoreGetDecodeOutput();
void sceVdecCoreInitializeComputeResource();
void sceVdecCoreMapMemoryBlock();
void sceVdecCoreQueryComputeResourceInfo();
void sceVdecCoreQueryFrameBufferInfo();
void sceVdecCoreQueryInstanceSize();
void sceVdecCoreResetDecoder();
void sceVdecCoreSetDecodeInput();
void sceVdecCoreSetDecodeOutputSw();
void sceVdecCoreSyncDecode();
void sceVdecCoreSyncDecodeOutputSw();
void sceVdecCoreSyncDecodeWptr();
void sceVdecCoreTrySyncDecode();
void sceVdecCoreTrySyncDecodeOutputSw();
void sceVdecCoreTrySyncDecodeWptr();
