#pragma once 

#include "common_dialog.h"
#include <stdint.h>

typedef int32_t OrbisUserServiceUserId;
typedef int32_t OrbisMsgDialogButtonId;
typedef int32_t OrbisMsgDialogProgressBarTarget;

typedef enum OrbisMsgDialogButton : OrbisMsgDialogButtonId
{
	ORBIS_MSG_DIALOG_BUTTON_ID_INVALID = 0,
	ORBIS_MSG_DIALOG_BUTTON_ID_OK = 1,
	ORBIS_MSG_DIALOG_BUTTON_ID_YES = 1,
	ORBIS_MSG_DIALOG_BUTTON_ID_NO = 2,
	ORBIS_MSG_DIALOG_BUTTON_ID_BUTTON1 = 1,
	ORBIS_MSG_DIALOG_BUTTON_ID_BUTTON2 = 2,
} OrbisMsgDialogButton;

typedef enum OrbisMsgDialogMode {
	ORBIS_MSG_DIALOG_MODE_USER_MSG = 1,
	ORBIS_MSG_DIALOG_MODE_PROGRESS_BAR = 2,
	ORBIS_MSG_DIALOG_MODE_SYSTEM_MSG = 3,
} OrbisMsgDialogMode;

typedef struct OrbisMsgDialogResult {
	OrbisMsgDialogMode mode;
	int32_t result;
	OrbisMsgDialogButton buttonId;
	char reserved[32];
} OrbisMsgDialogResult;

typedef enum OrbisMsgDialogButtonType {
	ORBIS_MSG_DIALOG_BUTTON_TYPE_OK = 0,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_YESNO = 1,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_NONE = 2,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL = 3,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_WAIT = 5,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_WAIT_CANCEL = 6,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_YESNO_FOCUS_NO = 7,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_OK_CANCEL_FOCUS_CANCEL = 8,
	ORBIS_MSG_DIALOG_BUTTON_TYPE_2BUTTONS = 9,
} OrbisMsgDialogButtonType;

typedef enum OrbisMsgDialogProgressBarType {
	ORBIS_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE = 0,
	ORBIS_MSG_DIALOG_PROGRESSBAR_TYPE_PERCENTAGE_CANCEL = 1,
} OrbisMsgDialogProgressBarType;

typedef enum OrbisMsgDialogSystemMessageType {
	ORBIS_MSG_DIALOG_SYSMSG_TYPE_TRC_EMPTY_STORE = 0,
	ORBIS_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_CHAT_RESTRICTION = 1,
	ORBIS_MSG_DIALOG_SYSMSG_TYPE_TRC_PSN_UGC_RESTRICTION = 2,
	ORBIS_MSG_DIALOG_SYSMSG_TYPE_CAMERA_NOT_CONNECTED = 4,
	ORBIS_MSG_DIALOG_SYSMSG_TYPE_WARNING_PROFILE_PICTURE_AND_NAME_NOT_SHARED = 5,
} OrbisMsgDialogSystemMessageType;

typedef struct OrbisMsgDialogButtonsParam {
	const char *msg1;
	const char *msg2;
	char reserved[32];
} OrbisMsgDialogButtonsParam;

typedef struct OrbisMsgDialogUserMessageParam {
	OrbisMsgDialogButtonType buttonType;
	int32_t :32;
	const char *msg;
	OrbisMsgDialogButtonsParam *buttonsParam;
	char reserved[24];
} OrbisMsgDialogUserMessageParam;

typedef struct OrbisMsgDialogProgressBarParam {
	OrbisMsgDialogProgressBarType barType;
	int32_t :32;
	const char *msg;
	char reserved[64];
} OrbisMsgDialogProgressBarParam;

typedef struct OrbisMsgDialogSystemMessageParam {
	OrbisMsgDialogSystemMessageType sysMsgType;
	char reserved[32];
} OrbisMsgDialogSystemMessageParam;

typedef struct OrbisMsgDialogParam {
	OrbisCommonDialogBaseParam baseParam;
	size_t size;
	OrbisMsgDialogMode mode;
	int32_t :32;
	OrbisMsgDialogUserMessageParam *userMsgParam;
	OrbisMsgDialogProgressBarParam *progBarParam;
	OrbisMsgDialogSystemMessageParam *sysMsgParam;
	OrbisUserServiceUserId userId;
	char reserved[40];
	int32_t :32;
} OrbisMsgDialogParam;
