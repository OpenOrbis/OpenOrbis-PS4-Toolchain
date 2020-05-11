#ifndef _SCE_BACKUP_RESTORE_H_
#define _SCE_BACKUP_RESTORE_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif


// Empty Comment
void sceBackupRestoreUtilBackupData();
// Empty Comment
void sceBackupRestoreUtilCancelBackupData();
// Empty Comment
void sceBackupRestoreUtilCancelGetRequiredSize();
// Empty Comment
void sceBackupRestoreUtilCancelRestoreData();
// Empty Comment
void sceBackupRestoreUtilDeleteBackupData();
// Empty Comment
void sceBackupRestoreUtilGetBackupDataInfo();
// Empty Comment
void sceBackupRestoreUtilGetBackupProgress();
// Empty Comment
void sceBackupRestoreUtilGetRequiredSize();
// Empty Comment
void sceBackupRestoreUtilGetRestoreProgress();
// Empty Comment
void sceBackupRestoreUtilInitialize();
// Empty Comment
void sceBackupRestoreUtilRestoreData();
// Empty Comment
void sceBackupRestoreUtilTerminate();

#endif

#ifdef __cplusplus
}
#endif