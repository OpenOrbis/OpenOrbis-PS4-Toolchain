#ifndef _SCE_VIDEO_DEC_H_
#define _SCE_VIDEO_DEC_H_

#include <stdint.h>
#include "_types/videodec.h"

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceVideodecCreateDecoder(const OrbisVideodecConfigInfo*, const OrbisVideodecResourceInfo*, OrbisVideodecCtrl*);
int32_t sceVideodecDecode(OrbisVideodecCtrl*, const OrbisVideodecInputData*, OrbisVideodecFrameBuffer*, OrbisVideodecPictureInfo*);
int32_t sceVideodecFlush(OrbisVideodecCtrl*, OrbisVideodecFrameBuffer*, OrbisVideodecPictureInfo*);
int32_t sceVideodecQueryResourceInfo(const OrbisVideodecConfigInfo*, OrbisVideodecResourceInfo*);
int32_t sceVideodecReset(OrbisVideodecCtrl*);
int32_t sceVideodecDeleteDecoder(OrbisVideodecCtrl*);

//
void sceVideodecMapMemory();


#ifdef __cplusplus
}
#endif
#endif
