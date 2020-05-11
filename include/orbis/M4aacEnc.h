#ifndef _SCE_M4AAC_ENC_H_
#define _SCE_M4AAC_ENC_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceM4aacEncClearContext();
// Empty Comment
void sceM4aacEncCreateEncoder();
// Empty Comment
void sceM4aacEncDeleteEncoder();
// Empty Comment
void sceM4aacEncEncode();
// Empty Comment
void sceM4aacEncFlush();

#endif

#ifdef __cplusplus
}
#endif