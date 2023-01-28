#ifndef _ORBIS_MSG_DIALOG_H_
#define _ORBIS_MSG_DIALOG_H_

#include <stdint.h>
#include <orbis/_types/common_dialog.h>
#include <orbis/_types/msg_dialog.h>

#ifdef __cplusplus 
extern "C" {
#endif

// Initialize the message dialog. Should be called before trying to use the
// message dialog.
int32_t sceMsgDialogInitialize(void);

// Display the message dialog.
int32_t sceMsgDialogOpen(const OrbisMsgDialogParam *param);

// Get the result of the message dialog after the user closes the dialog.
// This can be used to detect which option was pressed (yes, no, cancel, etc).
int32_t sceMsgDialogGetResult(OrbisMsgDialogResult *result);

// Get the status of the message dialog. This can be used to check if a
// message dialog is initialized, is being displayed, or is finished.
OrbisCommonDialogStatus sceMsgDialogGetStatus();

// Update the current status of the message dialog.
OrbisCommonDialogStatus sceMsgDialogUpdateStatus(void);

// Increase the message dialog progress bar percentage.
// OrbisMsgDialogMode must be initialized with ORBIS_MSG_DIALOG_MODE_PROGRESS_BAR.
int32_t sceMsgDialogProgressBarInc(OrbisMsgDialogProgressBarTarget target, uint32_t delta);

// Add a message to the message dialog progress bar.
// OrbisMsgDialogMode must be initialized with ORBIS_MSG_DIALOG_MODE_PROGRESS_BAR.
int32_t sceMsgDialogProgressBarSetMsg(OrbisMsgDialogProgressBarTarget target, const char *barMsg);

// Set the message dialog progress bar immediately without animation.
// OrbisMsgDialogMode must be initialized with ORBIS_MSG_DIALOG_MODE_PROGRESS_BAR.
int32_t sceMsgDialogProgressBarSetValue(OrbisMsgDialogProgressBarTarget target, uint32_t rate);

// Close the message dialog.
int32_t sceMsgDialogClose(void);

// Terminate the message dialog. Should be called when all message dialog
// operations are finished.
int32_t sceMsgDialogTerminate(void);

#ifdef __cplusplus
}
#endif

#endif
