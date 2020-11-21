#ifndef _ORBIS_COMMON_DIALOG_H_
#define _ORBIS_COMMON_DIALOG_H_

#include <stdint.h>


#ifdef __cplusplus 
extern "C" {
#endif



#define ORBIS_COMMON_DIALOG_MAGIC_NUMBER 0xC0D1A109


typedef enum OrbisCommonDialogStatus {
	ORBIS_COMMON_DIALOG_STATUS_NONE				= 0,
	ORBIS_COMMON_DIALOG_STATUS_INITIALIZED		= 1,
	ORBIS_COMMON_DIALOG_STATUS_RUNNING			= 2,
	ORBIS_COMMON_DIALOG_STATUS_FINISHED			= 3
} OrbisCommonDialogStatus;

typedef enum OrbisCommonDialogResult {
	ORBIS_COMMON_DIALOG_RESULT_OK					= 0,
	ORBIS_COMMON_DIALOG_RESULT_USER_CANCELED		= 1,
} OrbisCommonDialogResult;

typedef struct OrbisCommonDialogBaseParam {
	size_t size;
	uint8_t reserved[36];
	uint32_t magic;
} OrbisCommonDialogBaseParam __attribute__ ((__aligned__(8)));


static inline void _sceCommonDialogSetMagicNumber( uint32_t* magic, const OrbisCommonDialogBaseParam* param )
{
	*magic = (uint32_t)( ORBIS_COMMON_DIALOG_MAGIC_NUMBER + (uint64_t)param );
}

static inline void _sceCommonDialogBaseParamInit(OrbisCommonDialogBaseParam *param)
{
	memset(param, 0x0, sizeof(OrbisCommonDialogBaseParam));
	param->size = (uint32_t)sizeof(OrbisCommonDialogBaseParam);
	_sceCommonDialogSetMagicNumber( &(param->magic), param );
}


// Empty Comment
void sceCommonDialogInitialize();
// Empty Comment
void sceCommonDialogIsUsed();

#endif

#ifdef __cplusplus
}
#endif