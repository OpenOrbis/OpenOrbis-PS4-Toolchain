#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void FinalizeImeModule();
void InitializeImeModule();
void sceImeClose();
void sceImeConfigGet();
void sceImeConfigSet();
void sceImeConfirmCandidate();
void sceImeDicAddWord();
void sceImeDicDeleteLearnDics();
void sceImeDicDeleteUserDics();
void sceImeDicDeleteWord();
void sceImeDicGetWords();
void sceImeDicReplaceWord();
void sceImeDisableController();
void sceImeFilterText();
void sceImeForTestFunction();
void sceImeGetPanelPositionAndForm();
void sceImeGetPanelSize();
void sceImeKeyboardClose();
void sceImeKeyboardGetInfo();
void sceImeKeyboardGetResourceId();
void sceImeKeyboardOpen();
void sceImeKeyboardOpenInternal();
void sceImeKeyboardSetMode();
void sceImeKeyboardUpdate();
void sceImeOpen();
void sceImeOpenInternal();
void sceImeParamInit();
void sceImeSetCandidateIndex();
void sceImeSetCaret();
void sceImeSetText();
void sceImeSetTextGeometry();
void sceImeUpdate();
void sceImeVshClearPreedit();
void sceImeVshClose();
void sceImeVshConfirmPreedit();
void sceImeVshDisableController();
void sceImeVshGetPanelPositionAndForm();
void sceImeVshInformConfirmdString();
void sceImeVshInformConfirmdString2();
void sceImeVshOpen();
void sceImeVshSendTextInfo();
void sceImeVshSetCaretGeometry();
void sceImeVshSetCaretIndexInPreedit();
void sceImeVshSetPanelPosition();
void sceImeVshSetParam();
void sceImeVshSetPreeditGeometry();
void sceImeVshSetSelectGeometry();
void sceImeVshSetSelectionText();
void sceImeVshUpdate();
void sceImeVshUpdateContext();
void sceImeVshUpdateContext2();
