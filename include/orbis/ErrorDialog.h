#ifndef _SCE_ERROR_DIALOG_H_
#define _SCE_ERROR_DIALOG_H_

#include "_types/error_dialog.h"
#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

// closes the opened error dialog
void sceErrorDialogClose();

// returns the status of the running error dialog 
OrbisErrorDialogStatus sceErrorDialogGetStatus();

// Initializes the error dialog libary, this needs to be called prior to using this library
int32_t sceErrorDialogInitialize();

// Opens the error dialog with the set Params
int32_t sceErrorDialogOpen(OrbisErrorDialogParam*);

// Unkown, first arg might be OrbisErrorDialogParam?
void sceErrorDialogOpenDetail(void*, char*, char*, char*, char*);

// Unkown, first arg might be OrbisErrorDialogParam?
void sceErrorDialogOpenWithReport(void*, char*);

// force clsoing of the error dialog
void sceErrorDialogTerminate();

// Gets the updated status of the currently running error dialog
OrbisErrorDialogStatus sceErrorDialogUpdateStatus();


#ifdef __cplusplus
}
#endif
#endif