#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVdecwrapCreateDecoder();
void sceVdecwrapDeleteDecoder();
void sceVdecwrapFlushDecodeOutput();
void sceVdecwrapGetDecodeOutput();
void sceVdecwrapMapDirectMemory();
void sceVdecwrapQueryDecoderMemoryInfo();
void sceVdecwrapQueryFrameBufferInfo();
void sceVdecwrapResetDecoder();
void sceVdecwrapSetDecodeInput();
void sceVdecwrapSyncDecode();
