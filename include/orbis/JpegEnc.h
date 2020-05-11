#ifndef _SCE_JPEG_ENC_H_
#define _SCE_JPEG_ENC_H_

#include <stdint.h>
#include <orbis/_types/jpeg.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
int32_t sceJpegEncCreate(const OrbisJpegEncCreateParam *, void*, uint32_t, OrbisJpegEncHandle *);
// Empty Comment
int32_t sceJpegEncDelete(OrbisJpegEncHandle);
// Empty Comment
int32_t sceJpegEncEncode(OrbisJpegEncHandle, const OrbisJpegEncEncodeParam *, OrbisJpgEncOutputInfo *);
// Empty Comment
void sceJpegEncQueryMemorySize(OrbisJpegEncCreateParam *, void *, uint32_t, OrbisJpegEncHandle *);


#ifdef __cplusplus
}
#endif

#endif	
