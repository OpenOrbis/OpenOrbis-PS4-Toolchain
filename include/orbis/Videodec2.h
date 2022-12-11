#ifndef _SCE_VIDEO_DEC_2_H_
#define _SCE_VIDEO_DEC_2_H_

#include <stdint.h>
#include "_types/Videodec2.h"

#ifdef __cplusplus 
extern "C" {
#endif
void sceVideodec2CreateHevcDecoder();

int32_t sceVideodec2AllocateComputeQueue(const OrbisVideodec2ComputeConfigInfo*, const OrbisVideodec2ComputeMemoryInfo*, void**);
int32_t sceVideodec2CreateDecoder(const OrbisVideodec2DecoderConfigInfo*, const OrbisVideodec2DecoderMemoryInfo*, void**);
int32_t sceVideodec2Decode(void*, const OrbisVideodec2InputData*, OrbisVideodec2FrameBuffer* , OrbisVideodec2OutputInfo*);
int32_t sceVideodec2Flush(void* , OrbisVideodec2FrameBuffer* , OrbisVideodec2OutputInfo*);
int32_t sceVideodec2GetPictureInfo(const OrbisVideodec2OutputInfo* , void* , void*);
int32_t sceVideodec2QueryComputeMemoryInfo(OrbisVideodec2ComputeMemoryInfo*);
int32_t sceVideodec2QueryDecoderMemoryInfo(const OrbisVideodec2DecoderConfigInfo*, OrbisVideodec2DecoderMemoryInfo*);

int32_t sceVideodec2ReleaseComputeQueue(void*);
int32_t sceVideodec2Reset(void*);
int32_t sceVideodec2DeleteDecoder(void*);

#ifdef __cplusplus
}
#endif
#endif