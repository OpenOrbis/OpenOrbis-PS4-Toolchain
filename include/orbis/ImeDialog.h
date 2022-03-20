#include <orbis/_types/ime_dialog.h>

#ifndef _SCE_IME_DIALOG_H_
#define _SCE_IME_DIALOG_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceImeDialogAbort();
// Empty Comment
void sceImeDialogForceClose();
// Empty Comment
void sceImeDialogGetCurrentStarState();
// Empty Comment
void sceImeDialogGetPanelPositionAndForm();
// Empty Comment
void sceImeDialogGetPanelSize();
// Empty Comment
void sceImeDialogGetPanelSizeExtended();
// Empty Comment
int sceImeDialogGetResult(OrbisDialogResult *result);
// Empty Comment
OrbisDialogStatus sceImeDialogGetStatus();
// Empty Comment
int sceImeDialogInit(const OrbisImeDialogSetting *param, OrbisImeSettingsExtended* paramExtended);
// Empty Comment
void sceImeDialogInitInternal();
// Empty Comment
void sceImeDialogInitInternal2();
// Empty Comment
void sceImeDialogInitInternal3();
// Empty Comment
void sceImeDialogSetPanelPosition();
// Empty Comment
int sceImeDialogTerm();

#ifdef __cplusplus
}
#endif
#endif