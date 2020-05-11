#ifndef _SCE_IME_H_
#define _SCE_IME_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceImeClose();
// Empty Comment
void sceImeConfigGet();
// Empty Comment
void sceImeConfigSet();
// Empty Comment
void sceImeConfirmCandidate();
// Empty Comment
void sceImeDicAddWord();
// Empty Comment
void sceImeDicDeleteLearnDics();
// Empty Comment
void sceImeDicDeleteUserDics();
// Empty Comment
void sceImeDicDeleteWord();
// Empty Comment
void sceImeDicGetWords();
// Empty Comment
void sceImeDicReplaceWord();
// Empty Comment
void sceImeDisableController();
// Empty Comment
void sceImeGetPanelPositionAndForm();
// Empty Comment
void sceImeGetPanelSize();
// Empty Comment
void sceImeKeyboardClose();
// Empty Comment
void sceImeKeyboardGetInfo();
// Empty Comment
void sceImeKeyboardGetResourceId();
// Empty Comment
void sceImeKeyboardOpen();
// Empty Comment
void sceImeKeyboardOpenInternal();
// Empty Comment
void sceImeKeyboardSetMode();
// Empty Comment
void sceImeKeyboardUpdate();
// Empty Comment
void sceImeOpen();
// Empty Comment
void sceImeOpenInternal();
// Empty Comment
void sceImeParamInit();
// Empty Comment
void sceImeSetCandidateIndex();
// Empty Comment
void sceImeSetCaret();
// Empty Comment
void sceImeSetText();
// Empty Comment
void sceImeSetTextGeometry();
// Empty Comment
void sceImeUpdate();
// Empty Comment
void sceImeVshClearPreedit();
// Empty Comment
void sceImeVshClose();
// Empty Comment
void sceImeVshConfirmPreedit();
// Empty Comment
void sceImeVshGetPanelPositionAndForm();
// Empty Comment
void sceImeVshInformConfirmdString();
// Empty Comment
void sceImeVshOpen();
// Empty Comment
void sceImeVshSetCaretGeometry();
// Empty Comment
void sceImeVshSetCaretIndexInPreedit();
// Empty Comment
void sceImeVshSetPanelPosition();
// Empty Comment
void sceImeVshSetParam();
// Empty Comment
void sceImeVshSetPreeditGeometry();
// Empty Comment
void sceImeVshSetSelectGeometry();
// Empty Comment
void sceImeVshSetSelectionText();
// Empty Comment
void sceImeVshUpdate();
// Empty Comment
void sceImeVshUpdateContext();
// Empty Comment
void sceImeVshUpdateContext2();


#endif

#ifdef __cplusplus
}
#endif