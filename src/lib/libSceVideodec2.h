#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceVideodec2AllocateComputeQueue();
void sceVideodec2CreateDecoder();
void sceVideodec2CreateHevcDecoder();
void sceVideodec2Decode();
void sceVideodec2DeleteDecoder();
void sceVideodec2Flush();
void sceVideodec2GetAvcPictureInfo();
void sceVideodec2GetHevcPictureInfo();
void sceVideodec2GetPictureInfo();
void sceVideodec2MapDirectMemory();
void sceVideodec2QueryComputeMemoryInfo();
void sceVideodec2QueryDecoderMemoryInfo();
void sceVideodec2QueryHevcDecoderMemoryInfo();
void sceVideodec2ReleaseComputeQueue();
void sceVideodec2Reset();
