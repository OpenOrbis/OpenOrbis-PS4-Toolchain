#ifndef _SCE_VIDEO_DEC_2_H_
#define _SCE_VIDEO_DEC_2_H_

#include <stdint.h>
#include "_types/Videodec2.h"

#ifdef __cplusplus 
extern "C" 
{
#endif

int32_t sceVideodec2AllocateComputeQueue(const OrbisVideodec2ComputeConfigInfo* ComputeCfgInfoIn, const OrbisVideodec2ComputeMemoryInfo* ComputeMemInfoIn, void** ComputeQueueOut);
int32_t sceVideodec2CreateDecoder(const OrbisVideodec2DecoderConfigInfo* DecoderConfigInfoIn, const OrbisVideodec2DecoderMemoryInfo* DecoderMemoryInfoIn, void** DecoderInstanceOut);
int32_t sceVideodec2Decode(void* decoderInstanceIn, const OrbisVideodec2InputData* InputDataInOut, OrbisVideodec2FrameBuffer* FrameBufferInOut, OrbisVideodec2OutputInfo* OutputInfoOut);
int32_t sceVideodec2Flush(void* decoderInstanceIn, OrbisVideodec2FrameBuffer* FrameBufferInOut, OrbisVideodec2OutputInfo* OutputInfoOut);
int32_t sceVideodec2GetPictureInfo(const OrbisVideodec2OutputInfo* OutputInfoIn, void* p1stPictureInfoOut, void* p2ndPictureInfoOut);
int32_t sceVideodec2QueryComputeMemoryInfo(OrbisVideodec2ComputeMemoryInfo* ComputeMemInfoOut);
int32_t sceVideodec2QueryDecoderMemoryInfo(const OrbisVideodec2DecoderConfigInfo* DecoderConfigInfoIn, OrbisVideodec2DecoderMemoryInfo* DecoderMemoryInfoOut);
int32_t sceVideodec2ReleaseComputeQueue(void* computeQueueIn);
int32_t sceVideodec2Reset(void* decoderInstanceIn);
int32_t sceVideodec2DeleteDecoder(void* decoderInstanceIn);
 
void sceVideodec2CreateHevcDecoder();

#ifdef __cplusplus
}
#endif
#endif
