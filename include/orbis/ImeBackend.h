#ifndef _SCE_IME_BACKEND_H_
#define _SCE_IME_BACKEND_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceImeBackendAllConfirm();
// Empty Comment
void sceImeBackendClose();
// Empty Comment
void sceImeBackendConvertBackward();
// Empty Comment
void sceImeBackendDeleteCharacter();
// Empty Comment
void sceImeBackendEnterCharacter();
// Empty Comment
void sceImeBackendGetCandidateList();
// Empty Comment
void sceImeBackendGetCaretIndex();
// Empty Comment
void sceImeBackendGetConfirmString();
// Empty Comment
void sceImeBackendGetConvertString();
// Empty Comment
void sceImeBackendGetString();
// Empty Comment
void sceImeBackendPartConfirm();


#endif

#ifdef __cplusplus
}
#endif