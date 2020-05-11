#ifndef _SCE_PNG_DEC_H
#define _SCE_PNG_DEC_H

#include <stdint.h>
#include <orbis/_types/png.h>

#if defined(__cplusplus)
extern "C" {
#endif

// Empty Comment
int32_t scePngDecCreate(const OrbisPngDecCreateParam *, void *, uint32_t, OrbisPngDecHandle *);
// Empty Comment
int32_t scePngDecDecode(OrbisPngDecHandle, const OrbisPngDecDecodeParam *, OrbisPngDecImageInfo *);
// Empty Comment
int32_t scePngDecDelete(OrbisPngDecHandle);
// Empty Comment
int32_t scePngDecParseHeader(const OrbisPngDecParseParam *, OrbisPngDecImageInfo *);
// Empty Comment
int32_t scePngDecQueryMemorySize(const OrbisPngDecCreateParam *, void *, uint32_t, OrbisPngDecHandle *);

#ifdef __cplusplus
}
#endif

#endif
