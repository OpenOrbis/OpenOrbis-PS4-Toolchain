#ifndef _SCE_CONTENT_EXPORT_H_
#define _SCE_CONTENT_EXPORT_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceContentExportCancel();
// Empty Comment
void sceContentExportFinish();
// Empty Comment
void sceContentExportFromData();
// Empty Comment
void sceContentExportFromDataWithThumbnail();
// Empty Comment
void sceContentExportFromFile();
// Empty Comment
void sceContentExportFromFileWithThumbnail();
// Empty Comment
void sceContentExportGetProgress();
// Empty Comment
void sceContentExportInit();
// Empty Comment
void sceContentExportStart();
// Empty Comment
void sceContentExportTerm();

#endif

#ifdef __cplusplus
}
#endif