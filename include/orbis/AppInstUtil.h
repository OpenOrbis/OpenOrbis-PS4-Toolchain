#ifndef _SCE_APP_INST_UTIL_H_
#define _SCE_APP_INST_UTIL_H_

#include "_types/appinst_util.h"

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

int sceAppInstUtilInitialize(void);
int sceAppInstUtilTerminate(void);

int sceAppInstUtilGetTitleIdFromPkg(const char* pkgPath, char* titleId, int* isApp);
int sceAppInstUtilGetPrimaryAppSlot(const char* titleId, int* slot);

int sceAppInstUtilAppPrepareOverwritePkg(const char* pkgPath);

int sceAppInstUtilAppInstallPkg(const char* pkgPath, void* reserved);

int sceAppInstUtilAppUnInstall(const char* titleId);
int sceAppInstUtilAppUnInstallByUser(const char* titleId, int userId);
int sceAppInstUtilAppUnInstallPat(const char* titleId);
int sceAppInstUtilAppUnInstallTypes(const char* titleId, unsigned int deleteTypes);
int sceAppInstUtilAppUnInstallAddcont(const char* titleId, const char* addcontName);
int sceAppInstUtilAppUnInstallTheme(const char* contentId);

bool sceAppInstUtilAppIsInInstalling(const char* contentId);
int sceAppInstUtilAppIsInUpdating(const char* titleId, int* updating);
int sceAppInstUtilAppExists(const char* titleId, int* exists);
int sceAppInstUtilAppGetSize(const char* titleId, unsigned long* size);

int sceAppInstUtilAppRecoverApp(const char* titleId);

int sceAppInstUtilGetInstallProgress(const char* contentId, unsigned int* progress);
int sceAppInstUtilGetInstallProgressInfo(const char* contentId, unsigned int* state, unsigned int* progress, unsigned long* progressSize, unsigned long* totalSize, unsigned int* restSec);

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
