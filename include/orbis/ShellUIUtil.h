#ifndef _SCE_SHELL_UI_UTIL_H_
#define _SCE_SHELL_UI_UTIL_H_

#include <stdint.h>
#include <orbis/_types/shell_ui.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Empty Comment
void sceShellUIUtilGetAppUrl();
// Empty Comment
void sceShellUIUtilGetDefaultQueryParameter();
// Empty Comment
int sceShellUIUtilInitialize();
// Empty Comment
int sceShellUIUtilLaunchByUri(const char* uri,  OrbisShellUIUtilLaunchByUriParam *Param);
// Empty Comment
void sceShellUIUtilTerminate();

#ifdef __cplusplus
}
#endif

#endif // _SCE_SHELL_UI_UTIL_H_
