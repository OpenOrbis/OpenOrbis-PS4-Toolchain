#pragma once

#include <stdint.h>

typedef enum {
	ORBIS_DIALOG_OK = 0,
	ORBIS_DIALOG_CANCEL = 1,
	ORBIS_DIALOG_ABORD = 2,
} OrbisDialogResultStatus;

typedef enum OrbisVAlignment {
	ORBIS_V_TOP = 0,
	ORBIS_V_CENTER = 1,
	ORBIS_V_VALIGN_BOTTOM = 2,
} OrbisVAlignment;

typedef enum OrbisHAlignment {
	ORBIS_H_LEFT = 0,
	ORBIS_H_CENTER = 1,
	ORBIS_H_RIGHT = 2,
} OrbisHAlignment;

typedef enum OrbisInput {
	ORBIS__DEFAULT = 0,
} OrbisInput;

typedef enum OrbisImeType {
	ORBIS_TYPE_DEFAULT = 0,
	ORBIS_TYPE_BASIC_LATIN = 1,
	ORBIS_TYPE_TYPE_URL = 2,
	ORBIS_TYPE_MAIL = 3,
	ORBIS_TYPE_NUMBER = 4,
} OrbisImeType;

typedef enum OrbisButtonLabel {
	ORBIS_BUTTON_LABEL_DEFAULT = 0,
	ORBIS_BUTTON_LABEL_SEND = 1,
	ORBIS_BUTTON_LABEL_SEARCH = 2,
	ORBIS_BUTTON_LABEL_GO = 3,
} OrbisButtonLabel;

typedef enum {
	ORBIS_DIALOG_STATUS_NONE = 0,
	ORBIS_DIALOG_STATUS_RUNNING = 1,
	ORBIS_DIALOG_STATUS_STOPPED = 2,
} OrbisDialogStatus;

typedef int(*OrbisTextFilter)(
	wchar_t *outText,
	uint32_t *outTextLength,
	const wchar_t *srcText,
	uint32_t srcTextLength
);

typedef struct OrbisDialogResult {
	OrbisDialogResultStatus endstatus;
	int8_t reserved[12];
} OrbisDialogResult;

typedef struct OrbisImeSetting {
	int32_t userId;
	OrbisImeType type;
	uint64_t supportedLanguages;
	OrbisButtonLabel enterLabel;
	OrbisInput inputMethod;
	OrbisTextFilter filter;
	uint32_t option;
	uint32_t maxTextLength;
	wchar_t *inputTextBuffer;
	float posx;
	float posy;
	OrbisHAlignment horizontalAlignment;
	OrbisVAlignment verticalAlignment;
	void *work;
	void *arg;
	void *eventfunc;
	int8_t reserved[8];
} OrbisImeSetting;

typedef struct OrbisImeDialogSetting {
	uint32_t userId;
	OrbisImeType type;
	uint64_t supportedLanguages;
	OrbisButtonLabel enterLabel;
	OrbisInput inputMethod;
	OrbisTextFilter filter;
	uint32_t option;
	uint32_t maxTextLength;
	wchar_t *inputTextBuffer;
	float posx;
	float posy;
	OrbisHAlignment horizontalAlignment;
	OrbisVAlignment verticalAlignment;
	const wchar_t *placeholder;
	const wchar_t *title;
	int8_t reserved[16];
} OrbisImeDialogSetting;
