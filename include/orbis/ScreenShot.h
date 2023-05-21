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
int sceScreenShotDisable();
// Empty Comment
int sceScreenShotDisableNotification();
// Empty Comment
int sceScreenShotEnable();
// Empty Comment
int sceScreenShotEnableNotification();
// Empty Comment
void sceScreenShotGetAppInfo();
// Empty Comment
int sceScreenShotIsDisabled();
// Empty Comment
int sceScreenShotIsVshScreenCaptureDisabled();
// Sets overlay image with manual positioning
int sceScreenShotSetOverlayImage(const char *path, int x, int y);
// Sets overlay image with specified positioning
int sceScreenShotSetOverlayImageWithOrigin(const char *path, int x, int y, int);
// Empty Comment
void sceScreenShotSetParam();

#ifdef __cplusplus
}
#endif

#endif
