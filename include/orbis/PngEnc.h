#ifndef _SCE_PNG_ENC_H
#define _SCE_PNG_ENC_H

#include <stdint.h>
#include <orbis/_types/png.h>

#if defined(__cplusplus)
extern "C" {
#endif


// Empty Comment
int32_t scePngEncCreate(const OrbisPngEncCreateParam *, void *, uint32_t, OrbisPngEncHandle *);
// Empty Comment
int32_t scePngEncDelete(OrbisPngEncHandle);
// Empty Comment
int32_t scePngEncEncode(OrbisPngEncHandle, const OrbisPngEncEncodeParam *, OrbisPngEncOutputInfo *);
// Empty Comment
int32_t scePngEncQueryMemorySize(const OrbisPngEncCreateParam *);

#ifdef __cplusplus
}
#endif

#endif
