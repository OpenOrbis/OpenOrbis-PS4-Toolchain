#ifndef _SCE_VIDEO_DEC_H_
#define _SCE_VIDEO_DEC_H_

#include <stdint.h>
#include "_types/videodec.h"

#ifdef __cplusplus 
extern "C" 
{
#endif

int32_t sceVideodecCreateDecoder(const OrbisVideodecConfigInfo* CfgInfoIn, const OrbisVideodecResourceInfo* RsrcInfoIn, OrbisVideodecCtrl* CtrlOut);
int32_t sceVideodecDecode(OrbisVideodecCtrl* CtrlIn, const OrbisVideodecInputData* InputDataIn, OrbisVideodecFrameBuffer* FrameBufferInOut, OrbisVideodecPictureInfo* PictureInfoOut);
int32_t sceVideodecFlush(OrbisVideodecCtrl* CtrlIn, OrbisVideodecFrameBuffer* FrameBufferInOut, OrbisVideodecPictureInfo* PictureInfoOut);
int32_t sceVideodecQueryResourceInfo(const OrbisVideodecConfigInfo* CfgInfoIn, OrbisVideodecResourceInfo* RsrcInfoOut);
int32_t sceVideodecReset(OrbisVideodecCtrl* CfgInfoIn);
int32_t sceVideodecDeleteDecoder(OrbisVideodecCtrl* CfgInfoIn);

void sceVideodecMapMemory();

#ifdef __cplusplus
}
#endif
#endif
