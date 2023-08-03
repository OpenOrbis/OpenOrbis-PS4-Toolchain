#ifndef _SCE_SAVEDATA_H_
#define _SCE_SAVEDATA_H_

#include <stdint.h>
#include <orbis/_types/save_data.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceSaveDataInitialize3(int32_t initParams);
int32_t sceSaveDataMount(OrbisSaveDataMount*, OrbisSaveDataMountResult*);
int32_t sceSaveDataUmount(OrbisSaveDataMountPoint*);
int32_t sceSaveDataDelete(OrbisSaveDataDelete *del);
int32_t sceSaveDataSetParam(const OrbisSaveDataMountPoint * mountPoint, uint32_t type, void * buffer, size_t bufferSize);

// Empty Comment
void sceSaveDataBackup();
// Empty Comment
void sceSaveDataCheckBackupData();
// Empty Comment
void sceSaveDataCheckBackupDataInternal();
// Empty Comment
void sceSaveDataClearProgress();
// Empty Comment
void sceSaveDataDelete5();
// Searches save data for a spesific Dir Name
int32_t sceSaveDataDirNameSearch(const OrbisSaveDataDirNameSearchCond *cond,OrbisSaveDataDirNameSearchResult *result);
// Empty Comment
void sceSaveDataDirNameSearchInternal();
// Empty Comment
void sceSaveDataGetEventResult();
// Empty Comment
void sceSaveDataGetMountInfo(const OrbisSaveDataMountPoint *mountPoint, OrbisSaveDataMountInfo *info);
// Empty Comment
int32_t sceSaveDataGetParam(const OrbisSaveDataMountPoint *mountPoint, uint32_t paramType, void *paramBuf, size_t paramBufSize, size_t *gotSize);
// Empty Comment
int32_t sceSaveDataGetProgress(float *progress);
// Empty Comment
void sceSaveDataGetSaveDataMemory();
// Empty Comment
void sceSaveDataGetSaveDataMemory2();
// Empty Comment
void sceSaveDataInitialize();
// Empty Comment
void sceSaveDataInitialize2();
// Empty Comment
int32_t sceSaveDataLoadIcon(const OrbisSaveDataMountPoint *mountPoint, OrbisSaveDataIcon *icon);
// Empty Comment
int32_t sceSaveDataMount2(const OrbisSaveDataMount2 *mount, OrbisSaveDataMountResult *mountResult);
// Empty Comment
void sceSaveDataMount5();
// Empty Comment
void sceSaveDataMountInternal();
// Empty Comment
void sceSaveDataRestoreBackupData();
// Empty Comment
int32_t sceSaveDataSaveIcon(const OrbisSaveDataMountPoint *mountPoint, const OrbisSaveDataIcon *icon);
// Empty Comment
void sceSaveDataSetSaveDataMemory();
// Empty Comment
void sceSaveDataSetSaveDataMemory2();
// Empty Comment
void sceSaveDataSetupSaveDataMemory();
// Empty Comment
void sceSaveDataSetupSaveDataMemory2();
// Empty Comment
void sceSaveDataSyncSaveDataMemory();
// Empty Comment
void sceSaveDataTerminate();
// Empty Comment
void sceSaveDataTransferringMount();
// Empty Comment
void sceSaveDataUmountWithBackup();
//This will delete all save data for a spesific user
int32_t sceSaveDataDeleteAllUser();

#ifdef __cplusplus
}
#endif

#endif
