#ifndef _SCE_VDEC_CORE_H_
#define _SCE_VDEC_CORE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceVdecCoreCreateDecoder();
// Empty Comment
void sceVdecCoreDeleteDecoder();
// Empty Comment
void sceVdecCoreFlushDecodeOutput();
// Empty Comment
void sceVdecCoreGetDecodeOutput();
// Empty Comment
void sceVdecCoreMapMemoryBlock();
// Empty Comment
void sceVdecCoreQueryFrameBufferInfo();
// Empty Comment
void sceVdecCoreQueryInstanceSize();
// Empty Comment
void sceVdecCoreResetDecoder();
// Empty Comment
void sceVdecCoreSetDecodeInput();
// Empty Comment
void sceVdecCoreSyncDecode();

#endif

#ifdef __cplusplus
}
#endif