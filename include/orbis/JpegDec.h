#ifndef _SCE_JPEG_DEC_H_
#define _SCE_JPEG_DEC_H_

#include <stdint.h>
#include <orbis/_types/jpeg.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
int32_t sceJpegDecCreate(const OrbisJpegDecCreateParam *, void *, uint32_t, OrbisJpegDecHandle *);
// Empty Comment
int32_t sceJpegDecDecode(OrbisJpegDecHandle, const OrbisJpegDecDecodeParam *, OrbisJpegDecImageInfo *);
// Empty Comment
int32_t sceJpegDecDelete(OrbisJpegDecHandle);
// Empty Comment
int32_t sceJpegDecParseHeader(const OrbisJpegDecParseParam *, OrbisJpegDecImageInfo *);
// Empty Comment
int32_t sceJpegDecQueryMemorySize(const OrbisJpegDecCreateParam *, void *, uint32_t, OrbisJpegDecHandle *);


#ifdef __cplusplus
}
#endif

#endif	
