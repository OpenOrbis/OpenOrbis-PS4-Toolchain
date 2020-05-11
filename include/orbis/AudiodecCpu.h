#ifndef _SCE_AUDIO_DEC_CPU_H_
#define _SCE_AUDIO_DEC_CPU_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceAudiodecCpuClearContext();
// Empty Comment
void sceAudiodecCpuDecode();
// Empty Comment
void sceAudiodecCpuInitDecoder();
// Empty Comment
void sceAudiodecCpuInternalClearContext();
// Empty Comment
void sceAudiodecCpuInternalDecode();
// Empty Comment
void sceAudiodecCpuInternalInitDecoder();
// Empty Comment
void sceAudiodecCpuInternalQueryMemSize();
// Empty Comment
void sceAudiodecCpuQueryMemSize();


#endif

#ifdef __cplusplus
}
#endif