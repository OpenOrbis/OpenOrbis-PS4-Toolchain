#ifndef _SCE_VIDEO_DEC_H_
#define _SCE_VIDEO_DEC_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceVideodecCreateDecoder();
// Empty Comment
void sceVideodecDecode();
// Empty Comment
void sceVideodecDeleteDecoder();
// Empty Comment
void sceVideodecFlush();
// Empty Comment
void sceVideodecMapMemory();
// Empty Comment
void sceVideodecQueryResourceInfo();
// Empty Comment
void sceVideodecReset();


#endif

#ifdef __cplusplus
}
#endif