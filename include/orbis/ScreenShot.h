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
void sceScreenShotDisable();
// Empty Comment
void sceScreenShotDisableNotification();
// Empty Comment
void sceScreenShotEnable();
// Empty Comment
void sceScreenShotEnableNotification();
// Empty Comment
void sceScreenShotGetAppInfo();
// Empty Comment
void sceScreenShotIsDisabled();
// Empty Comment
void sceScreenShotIsVshScreenCaptureDisabled();
// Sets overlay image with manual positioning
int sceScreenShotSetOverlayImage(const char *overlay_image, int x, int y);
// Sets overlay image with manual positioning
int sceScreenShotSetOverlayImageWithOrigin(const char *overlay_image, int x, int y, int);
// Empty Comment
void sceScreenShotSetParam();


#endif

#ifdef __cplusplus
}
#endif
