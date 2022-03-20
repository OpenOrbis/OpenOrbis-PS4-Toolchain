#pragma once

#include "rtc.h"

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

typedef enum OrbisImeKeyboardType
{
	ORBIS_IME_KEYBOARD_TYPE_NONE			 =  0,
	ORBIS_IME_KEYBOARD_TYPE_DANISH			 =  1,
	ORBIS_IME_KEYBOARD_TYPE_GERMAN			 =  2,
	ORBIS_IME_KEYBOARD_TYPE_GERMAN_SW		 =  3,
	ORBIS_IME_KEYBOARD_TYPE_ENGLISH_US		 =  4,
	ORBIS_IME_KEYBOARD_TYPE_ENGLISH_GB		 =  5,
	ORBIS_IME_KEYBOARD_TYPE_SPANISH			 =  6,
	ORBIS_IME_KEYBOARD_TYPE_SPANISH_LA		 =  7,
	ORBIS_IME_KEYBOARD_TYPE_FINNISH			 =  8,
	ORBIS_IME_KEYBOARD_TYPE_FRENCH			 =  9,
	ORBIS_IME_KEYBOARD_TYPE_FRENCH_BR		 = 10,
	ORBIS_IME_KEYBOARD_TYPE_FRENCH_CA		 = 11,
	ORBIS_IME_KEYBOARD_TYPE_FRENCH_SW		 = 12,
	ORBIS_IME_KEYBOARD_TYPE_ITALIAN			 = 13,
	ORBIS_IME_KEYBOARD_TYPE_DUTCH			 = 14,
	ORBIS_IME_KEYBOARD_TYPE_NORWEGIAN		 = 15,
	ORBIS_IME_KEYBOARD_TYPE_POLISH			 = 16,
	ORBIS_IME_KEYBOARD_TYPE_PORTUGUESE_BR	 = 17,
	ORBIS_IME_KEYBOARD_TYPE_PORTUGUESE_PT	 = 18,
	ORBIS_IME_KEYBOARD_TYPE_RUSSIAN			 = 19,
	ORBIS_IME_KEYBOARD_TYPE_SWEDISH			 = 20,
	ORBIS_IME_KEYBOARD_TYPE_TURKISH			 = 21,
	ORBIS_IME_KEYBOARD_TYPE_JAPANESE_ROMAN	 = 22,
	ORBIS_IME_KEYBOARD_TYPE_JAPANESE_KANA	 = 23,
	ORBIS_IME_KEYBOARD_TYPE_KOREAN			 = 24,
	ORBIS_IME_KEYBOARD_TYPE_SM_CHINESE		 = 25,
	ORBIS_IME_KEYBOARD_TYPE_TR_CHINESE_ZY	 = 26,
	ORBIS_IME_KEYBOARD_TYPE_TR_CHINESE_PY_HK = 27,
	ORBIS_IME_KEYBOARD_TYPE_TR_CHINESE_PY_TW = 28,
	ORBIS_IME_KEYBOARD_TYPE_TR_CHINESE_CG	 = 29,
	ORBIS_IME_KEYBOARD_TYPE_ARABIC_AR		 = 30,
} OrbisImeKeyboardType;

typedef enum OrbisImePanelPriority
{
	ORBIS_IME_PANEL_PRIORITY_DEFAULT	= 0,
	ORBIS_IME_PANEL_PRIORITY_ALPHABET	= 1,
	ORBIS_IME_PANEL_PRIORITY_SYMBOL		= 2,
	ORBIS_IME_PANEL_PRIORITY_ACCENT		= 3,
} OrbisImePanelPriority;

typedef struct OrbisImeKeycode
{
	uint16_t keycode;
	wchar_t  character;
	uint32_t status;
	OrbisImeKeyboardType type;
	int32_t  userId;			
	uint32_t resourceId;
	OrbisRtcTick timestamp;
} OrbisImeKeycode;

typedef struct OrbisImeColor
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
} OrbisImeColor;

typedef int(*OrbisTextFilter)(wchar_t *outText, uint32_t *outTextLength, const wchar_t *srcText, uint32_t srcTextLength);
typedef int(*OrbisImeExtendedKeyboardFilter)(const OrbisImeKeycode *srcKeycode,uint16_t *outKeycode, uint32_t *outStatus, void *reserved);

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

typedef struct OrbisImeSettingsExtended
{
	uint32_t option;
	OrbisImeColor colorBase;
	OrbisImeColor colorLine;
	OrbisImeColor colorTextField;
	OrbisImeColor colorPreedit;
	OrbisImeColor colorButtonDefault;
	OrbisImeColor colorButtonFunction;
	OrbisImeColor colorButtonSymbol;
	OrbisImeColor colorText;
	OrbisImeColor colorSpecial;
	OrbisImePanelPriority priority;
	char* additionalDictionaryPath;
	OrbisImeExtendedKeyboardFilter extKeyboardFilter;
	uint32_t disableDevice;
	uint32_t extKeyboardMode;
	int8_t reserved[60];
} OrbisImeSettingsExtended;

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
