#pragma once 

#include <stdint.h>

#define ORBIS_COMMON_DIALOG_MAGIC_NUMBER 0xC0D1A109

typedef enum OrbisCommonDialogResult {
	ORBIS_COMMON_DIALOG_RESULT_OK				= 0,
	ORBIS_COMMON_DIALOG_RESULT_USER_CANCELED	= 1
} OrbisCommonDialogResult;

typedef struct OrbisCommonDialogBaseParam {
	size_t size;
	uint8_t reserved[36];
	uint32_t magic;
} OrbisCommonDialogBaseParam __attribute__ ((__aligned__(8)));

typedef enum OrbisCommonDialogStatus {
	ORBIS_COMMON_DIALOG_STATUS_NONE				= 0,
	ORBIS_COMMON_DIALOG_STATUS_INITIALIZED		= 1,
	ORBIS_COMMON_DIALOG_STATUS_RUNNING			= 2,
	ORBIS_COMMON_DIALOG_STATUS_FINISHED			= 3
} OrbisCommonDialogStatus;
