#ifndef _SCE_VIDEO_DEC_2_H_
#define _SCE_VIDEO_DEC_2_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceVideodec2AllocateComputeQueue();
// Empty Comment
void sceVideodec2CreateDecoder();
// Empty Comment
void sceVideodec2CreateHevcDecoder();
// Empty Comment
void sceVideodec2Decode();
// Empty Comment
void sceVideodec2DeleteDecoder();
// Empty Comment
void sceVideodec2Flush();
// Empty Comment
void sceVideodec2GetPictureInfo();
// Empty Comment
void sceVideodec2QueryComputeMemoryInfo();
// Empty Comment
void sceVideodec2QueryDecoderMemoryInfo();
// Empty Comment
void sceVideodec2ReleaseComputeQueue();
// Empty Comment
void sceVideodec2Reset();


#endif

#ifdef __cplusplus
}
#endif