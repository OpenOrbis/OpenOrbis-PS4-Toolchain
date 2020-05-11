#ifndef _SCE_APP_INST_UTIL_H_
#define _SCE_APP_INST_UTIL_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

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
void sceAppInstUtilAppExists();
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
void sceAppInstUtilAppGetSize();
// Empty Comment
void sceAppInstUtilAppInstallAll();
// Empty Comment
void sceAppInstUtilAppInstallCloudGame();
// Empty Comment
void sceAppInstUtilAppInstallGetLinkState();
// Empty Comment
void sceAppInstUtilAppInstallMediaPlayer();
// Empty Comment
void sceAppInstUtilAppInstallPkg();
// Empty Comment
void sceAppInstUtilAppInstallRequestAddcontFromDisc();
// Empty Comment
void sceAppInstUtilAppInstallTitleDir();
// Empty Comment
void sceAppInstUtilAppIsInInstalling();
// Empty Comment
void sceAppInstUtilAppIsInUpdating();
// Empty Comment
void sceAppInstUtilAppPrepareOverwritePkg();
// Empty Comment
void sceAppInstUtilAppRecoverApp();
// Empty Comment
void sceAppInstUtilAppSetSavedataUploadStatus();
// Empty Comment
void sceAppInstUtilAppUnInstall();
// Empty Comment
void sceAppInstUtilAppUnInstallAddcont();
// Empty Comment
void sceAppInstUtilAppUnInstallByUser();
// Empty Comment
void sceAppInstUtilAppUnInstallForMultiInstall();
// Empty Comment
void sceAppInstUtilAppUnInstallPat();
// Empty Comment
void sceAppInstUtilAppUnInstallTheme();
// Empty Comment
void sceAppInstUtilAppUnInstallTypes();
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
void sceAppInstUtilGetInstallProgress();
// Empty Comment
void sceAppInstUtilGetInstallProgressInfo();
// Empty Comment
void sceAppInstUtilGetPrimaryAppSlot();
// Empty Comment
void sceAppInstUtilGetTitleIdFromPkg();
// Empty Comment
void sceAppInstUtilInitialize();
// Empty Comment
void sceAppInstUtilJson();
// Empty Comment
void sceAppInstUtilRequestDataDiscCopy();
// Empty Comment
void sceAppInstUtilRequestInstallDiscGame();
// Empty Comment
void sceAppInstUtilSetPrimaryAppSlot();
// Empty Comment
void sceAppInstUtilTerminate();

#endif

#ifdef __cplusplus
}
#endif