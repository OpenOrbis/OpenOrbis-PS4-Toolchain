#ifndef _SCE_SCREENSHOT_H_
#define _SCE_SCREENSHOT_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void _Z5dummyv();
// Empty Comment
void sceScreenShotCapture();
// Empty Comment
int32_t sceScreenShotDisable();
// Empty Comment
int32_t sceScreenShotDisableNotification();
// Empty Comment
int32_t sceScreenShotEnable();
// Empty Comment
int32_t sceScreenShotEnableNotification();
// Empty Comment
void sceScreenShotGetAppInfo();
// Empty Comment
int32_t sceScreenShotIsDisabled();
// Empty Comment
int32_t sceScreenShotIsVshScreenCaptureDisabled();
// Sets overlay image with manual positioning
int32_t sceScreenShotSetOverlayImage(const char *path, int32_t x, int32_t y);
// Sets overlay image with specified positioning
int32_t sceScreenShotSetOverlayImageWithOrigin(const char *path, int32_t x, int32_t y, int);
// Empty Comment
void sceScreenShotSetParam();

#ifdef __cplusplus
}
#endif

#endif
