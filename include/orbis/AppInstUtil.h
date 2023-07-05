#ifndef _SCE_APP_INST_UTIL_H_
#define _SCE_APP_INST_UTIL_H_

#include "_types/appinst_util.h"

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceAppInstUtilInitialize(void);
int32_t sceAppInstUtilTerminate(void);

int32_t sceAppInstUtilGetTitleIdFromPkg(const char* pkgPath, char* titleId, int32_t* isApp);
int32_t sceAppInstUtilGetPrimaryAppSlot(const char* titleId, int32_t* slot);

int32_t sceAppInstUtilAppPrepareOverwritePkg(const char* pkgPath);

int32_t sceAppInstUtilAppInstallPkg(const char* pkgPath, void* reserved);

int32_t sceAppInstUtilAppUnInstall(const char* titleId);
int32_t sceAppInstUtilAppUnInstallByUser(const char* titleId, int32_t userId);
int32_t sceAppInstUtilAppUnInstallPat(const char* titleId);
int32_t sceAppInstUtilAppUnInstallTypes(const char* titleId, uint32_t deleteTypes);
int32_t sceAppInstUtilAppUnInstallAddcont(const char* titleId, const char* addcontName);
int32_t sceAppInstUtilAppUnInstallTheme(const char* contentId);

bool sceAppInstUtilAppIsInInstalling(const char* contentId);
int32_t sceAppInstUtilAppIsInUpdating(const char* titleId, int32_t* updating);
int32_t sceAppInstUtilAppExists(const char* titleId, int32_t* exists);
int32_t sceAppInstUtilAppGetSize(const char* titleId, uint32_t* size);

int32_t sceAppInstUtilAppRecoverApp(const char* titleId);

int32_t sceAppInstUtilGetInstallProgress(const char* contentId, uint32_t* progress);
int32_t sceAppInstUtilGetInstallProgressInfo(const char* contentId, uint32_t* state, uint32_t* progress, uint32_t* progressSize, uint32_t* totalSize, uint32_t* restSec);

// Empty Comment
void sceAppInstUtilAppCancelableUnInstall();
// Empty Comment
void sceAppInstUtilAppCancelableUnInstallByUser();
// Empty Comment
void sceAppInstUtilAppCancelUnInstall();
// Empty Comment
void sceAppInstUtilAppConvertAppDiscToDownload();
// Empty Comment
void sceAppInstUtilAppConvertAppDownloadToDisc();
// Empty Comment
void sceAppInstUtilAppDestroyMetadata();
// Empty Comment
void sceAppInstUtilAppDestroyPkg();
// Empty Comment
void sceAppInstUtilAppGetAddcontInfo();
// Empty Comment
void sceAppInstUtilAppGetAddcontInfoByContentId();
// Empty Comment
void sceAppInstUtilAppGetAddcontListTotalSize();
// Empty Comment
void sceAppInstUtilAppGetAddcontNum();
// Empty Comment
void sceAppInstUtilAppGetCustomThemeInfo();
// Empty Comment
void sceAppInstUtilAppInstallAll();
// Empty Comment
void sceAppInstUtilAppInstallCloudGame();
// Empty Comment
void sceAppInstUtilAppInstallGetLinkState();
// Empty Comment
void sceAppInstUtilAppInstallMediaPlayer();
// Empty Comment
void sceAppInstUtilAppInstallRequestAddcontFromDisc();
// Empty Comment
void sceAppInstUtilAppInstallTitleDir();
// Empty Comment
void sceAppInstUtilAppSetSavedataUploadStatus();
// Empty Comment
void sceAppInstUtilAppUnInstallForMultiInstall();
// Empty Comment
void sceAppInstUtilAppUpdateStartTime();
// Empty Comment
void sceAppInstUtilCancelDataDiscCopy();
// Empty Comment
void sceAppInstUtilCheckAppSystemVer();
// Empty Comment
void sceAppInstUtilGetAddcontInstalledStatus();
// Empty Comment
void sceAppInstUtilGetAppEmptySlot();
// Empty Comment
void sceAppInstUtilGetAppSlotInfoList();
// Empty Comment
void sceAppInstUtilGetDataDiscCopyProgress();
// Empty Comment
void sceAppInstUtilGetInsertedDiscRoleType();
// Empty Comment
void sceAppInstUtilJson();
// Empty Comment
void sceAppInstUtilRequestDataDiscCopy();
// Empty Comment
void sceAppInstUtilRequestInstallDiscGame();
// Empty Comment
void sceAppInstUtilSetPrimaryAppSlot();

#ifdef __cplusplus
}
#endif

#endif
