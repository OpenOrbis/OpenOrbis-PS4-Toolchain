#ifndef _SCE_COMMON_DIALOG_H_
#define _SCE_COMMON_DIALOG_H_

#include <stdbool.h>
#include <stdint.h>
#include <orbis/_types/common_dialog.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Initialize system dialog.
int32_t sceCommonDialogInitialize();
// Check if a system dialog is currently running.
bool sceCommonDialogIsUsed();

#ifdef __cplusplus
}
#endif

#endif
