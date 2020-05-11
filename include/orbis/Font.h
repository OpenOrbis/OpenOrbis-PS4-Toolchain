#ifndef _SCE_FONT_H_
#define _SCE_FONT_H_

#include <stdint.h>
#include <orbis/_types/font.h>

#if defined(__cplusplus)
extern "C" {
#endif

// Empty Comment
void sceFontAttachDeviceCacheBuffer();
// Empty Comment
void sceFontBindRenderer();
// Empty Comment
void sceFontCharacterGetBidiLevel();
// Empty Comment
void sceFontCharacterGetTextFontCode();
// Empty Comment
void sceFontCharacterGetTextOrder();
// Empty Comment
void sceFontCharacterLooksFormatCharacters();
// Empty Comment
void sceFontCharacterLooksWhiteSpace();
// Empty Comment
void sceFontCharacterRefersTextBack();
// Empty Comment
void sceFontCharacterRefersTextNext();
// Empty Comment
void sceFontClearDeviceCache();
// Empty Comment
void sceFontCloseFont();
// Empty Comment
void sceFontCreateLibrary();
// Empty Comment
void sceFontCreateLibraryWithEdition();
// Empty Comment
void sceFontCreateRenderer();
// Empty Comment
void sceFontCreateRendererWithEdition();
// Empty Comment
void sceFontCreateString();
// Empty Comment
void sceFontCreateWritingLine();
// Empty Comment
void sceFontDefineAttribute();
// Empty Comment
void sceFontDeleteGlyph();
// Empty Comment
void sceFontDestroyLibrary();
// Empty Comment
void sceFontDestroyRenderer();
// Empty Comment
void sceFontDestroyString();
// Empty Comment
void sceFontDestroyWritingLine();
// Empty Comment
void sceFontDettachDeviceCacheBuffer();
// Empty Comment
void sceFontGenerateCharGlyph();
// Empty Comment
void sceFontGetAttribute();
// Empty Comment
void sceFontGetCharGlyphCode();
// Empty Comment
void sceFontGetCharGlyphMetrics();
// Empty Comment
void sceFontGetEffectSlant();
// Empty Comment
void sceFontGetEffectWeight();
// Empty Comment
void sceFontGetFontGlyphsCount();
// Empty Comment
void sceFontGetFontResolution();
// Empty Comment
void sceFontGetHorizontalLayout();
// Empty Comment
void sceFontGetKerning();
// Empty Comment
void sceFontGetLibrary();
// Empty Comment
void sceFontGetPixelResolution();
// Empty Comment
void sceFontGetRenderCharGlyphMetrics();
// Empty Comment
void sceFontGetRenderEffectSlant();
// Empty Comment
void sceFontGetRenderEffectWeight();
// Empty Comment
void sceFontGetRenderScaledKerning();
// Empty Comment
void sceFontGetRenderScalePixel();
// Empty Comment
void sceFontGetRenderScalePoint();
// Empty Comment
void sceFontGetResolutionDpi();
// Empty Comment
void sceFontGetScalePixel();
// Empty Comment
void sceFontGetScalePoint();
// Empty Comment
void sceFontGetScriptLanguage();
// Empty Comment
void sceFontGetTypographicDesign();
// Empty Comment
void sceFontGetVerticalLayout();
// Empty Comment
void sceFontGlyphDefineAttribute();
// Empty Comment
void sceFontGlyphGetAttribute();
// Empty Comment
void sceFontGlyphGetGlyphForm();
// Empty Comment
void sceFontGlyphGetMetricsForm();
// Empty Comment
void sceFontGlyphRefersMetrics();
// Empty Comment
void sceFontGlyphRefersMetricsHorizontal();
// Empty Comment
void sceFontGlyphRefersMetricsHorizontalAdvance();
// Empty Comment
void sceFontGlyphRefersMetricsHorizontalX();
// Empty Comment
void sceFontGlyphRefersOutline();
// Empty Comment
void sceFontGlyphRenderImage();
// Empty Comment
void sceFontGlyphRenderImageHorizontal();
// Empty Comment
void sceFontGlyphRenderImageVertical();
// Empty Comment
void sceFontMemoryInit();
// Empty Comment
void sceFontMemoryTerm();
// Empty Comment
void sceFontOpenFontFile();
// Empty Comment
void sceFontOpenFontInstance();
// Empty Comment
void sceFontOpenFontMemory();
// Empty Comment
void sceFontOpenFontSet();
// Empty Comment
void sceFontRebindRenderer();
// Empty Comment
void sceFontRenderCharGlyphImage();
// Empty Comment
void sceFontRenderCharGlyphImageHorizontal();
// Empty Comment
void sceFontRenderCharGlyphImageVertical();
// Empty Comment
void sceFontRenderSurfaceInit();
// Empty Comment
void sceFontRenderSurfaceSetScissor();
// Empty Comment
void sceFontRenderSurfaceSetStyleFrame();
// Empty Comment
void sceFontSetEffectSlant();
// Empty Comment
void sceFontSetEffectWeight();
// Empty Comment
void sceFontSetFontsOpenMode();
// Empty Comment
void sceFontSetResolutionDpi();
// Empty Comment
void sceFontSetScalePixel();
// Empty Comment
void sceFontSetScalePoint();
// Empty Comment
void sceFontSetScriptLanguage();
// Empty Comment
void sceFontSetTypographicDesign();
// Empty Comment
void sceFontSetupRenderEffectSlant();
// Empty Comment
void sceFontSetupRenderEffectWeight();
// Empty Comment
void sceFontSetupRenderScalePixel();
// Empty Comment
void sceFontSetupRenderScalePoint();
// Empty Comment
void sceFontStringGetTerminateCode();
// Empty Comment
void sceFontStringGetTerminateOrder();
// Empty Comment
void sceFontStringGetWritingForm();
// Empty Comment
void sceFontStringRefersRenderCharacters();
// Empty Comment
void sceFontStringRefersTextCharacters();
// Empty Comment
void sceFontStyleFrameGetEffectSlant();
// Empty Comment
void sceFontStyleFrameGetEffectWeight();
// Empty Comment
void sceFontStyleFrameGetResolutionDpi();
// Empty Comment
void sceFontStyleFrameGetScalePixel();
// Empty Comment
void sceFontStyleFrameGetScalePoint();
// Empty Comment
void sceFontStyleFrameInit();
// Empty Comment
void sceFontStyleFrameSetEffectSlant();
// Empty Comment
void sceFontStyleFrameSetEffectWeight();
// Empty Comment
void sceFontStyleFrameSetResolutionDpi();
// Empty Comment
void sceFontStyleFrameSetScalePixel();
// Empty Comment
void sceFontStyleFrameSetScalePoint();
// Empty Comment
void sceFontStyleFrameUnsetEffectSlant();
// Empty Comment
void sceFontStyleFrameUnsetEffectWeight();
// Empty Comment
void sceFontStyleFrameUnsetScale();
// Empty Comment
void sceFontSupportExternalFonts();
// Empty Comment
void sceFontSupportSystemFonts();
// Empty Comment
void sceFontTextSourceInit();
// Empty Comment
void sceFontTextSourceRewind();
// Empty Comment
void sceFontTextSourceSetDefaultFont();
// Empty Comment
void sceFontTextSourceSetWritingForm();
// Empty Comment
void sceFontUnbindRenderer();
// Empty Comment
void sceFontWritingGetRenderMetrics();
// Empty Comment
void sceFontWritingInit();
// Empty Comment
void sceFontWritingLineClear();
// Empty Comment
void sceFontWritingLineGetOrderingSpace();
// Empty Comment
void sceFontWritingLineGetRenderMetrics();
// Empty Comment
void sceFontWritingLineRefersRenderStep();
// Empty Comment
void sceFontWritingLineWritesOrder();
// Empty Comment
void sceFontWritingRefersRenderStep();
// Empty Comment
void sceFontWritingRefersRenderStepCharacter();
// Empty Comment
void sceFontWritingSetMaskInvisible();

#ifdef __cplusplus
}
#endif

#endif
