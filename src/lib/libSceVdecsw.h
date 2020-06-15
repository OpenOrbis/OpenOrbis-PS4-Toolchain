#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVdecswAllocateComputeQueue();
void sceVdecswCreateDecoder();
void sceVdecswDeleteDecoder();
void sceVdecswFinalizeDecodeSequence();
void sceVdecswGetAvcPictureInfo();
void sceVdecswGetHevcPictureInfo();
void sceVdecswGetPictureInfo();
void sceVdecswQueryComputeMemoryInfo();
void sceVdecswQueryDecoderMemoryInfo();
void sceVdecswReleaseComputeQueue();
void sceVdecswResetDecoder();
void sceVdecswSetDecodeInput();
void sceVdecswSetDecodeOutput();
void sceVdecswSyncDecodeInput();
void sceVdecswSyncDecodeOutput();
void sceVdecswTrySyncDecodeInput();
void sceVdecswTrySyncDecodeOutput();
