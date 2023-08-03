#pragma once

#include <stdint.h>

typedef struct OrbisErrorDialogParam {
	int32_t		size;
	int32_t		errorcode;
	int32_t		userId;
	int32_t		reserved;
} OrbisErrorDialogParam;


typedef enum OrbisErrorDialogStatus {
	ORBIS_ERROR_DIALOG_STATUS_NONE			= 0,
	ORBIS_ERROR_DIALOG_STATUS_INITIALIZED	= 1,
	ORBIS_ERROR_DIALOG_STATUS_RUNNING		= 2,
	ORBIS_ERROR_DIALOG_STATUS_FINISHED		= 3
} OrbisErrorDialogStatus;
