#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceIduUtilClearAllSchedules();
void sceIduUtilDeleteSaveData();
void sceIduUtilDisablePriorityDownloads();
void sceIduUtilDownloadInstallPkg();
void sceIduUtilEnablePriorityDownloads();
void sceIduUtilGetAppVersion();
void sceIduUtilGetBgftProgress();
void sceIduUtilGetCompilationDiscInfo();
void sceIduUtilGetCompilationDiscTitleInfo();
void sceIduUtilGetDiscInfo();
void sceIduUtilGetDiskSpaceStats();
void sceIduUtilGetDownloadInstallProgress();
void sceIduUtilGetDownloadState();
void sceIduUtilGetEnvironment();
void sceIduUtilGetInstalledApp();
void sceIduUtilGetInstalledAppWithOffset();
void sceIduUtilGetMasterVersion();
void sceIduUtilGetNumInstalledApps();
void sceIduUtilGetNumSchedules();
void sceIduUtilGetOpenPsId();
void sceIduUtilGetSchedule();
void sceIduUtilGetSettingBin();
void sceIduUtilGetSettingInt();
void sceIduUtilGetSettingStr();
void sceIduUtilHideOverlay();
void sceIduUtilInitialize();
void sceIduUtilIsAppInstalled();
void sceIduUtilIsDiscCompilationDisc();
void sceIduUtilIsDiscInserted();
void sceIduUtilIsInitialised();
void sceIduUtilIsRifInstalled();
void sceIduUtilIsStaffMode();
void sceIduUtilLaunchTitle();
void sceIduUtilLaunchTitleV2();
void sceIduUtilPauseAllDownloads();
void sceIduUtilReboot();
void sceIduUtilRegisterFlag();
void sceIduUtilRegisterOverlayMsg();
void sceIduUtilResumeAllDownloads();
void sceIduUtilSetMoveMode();
void sceIduUtilSetPupVersion();
void sceIduUtilSetSchedule();
void sceIduUtilSetSettingBin();
void sceIduUtilSetSettingInt();
void sceIduUtilSetSettingStr();
void sceIduUtilSetSysLanguage();
void sceIduUtilShowOverlay();
void sceIduUtilTerminate();
void sceIduUtilUninstallApp();
void sceIduUtilUpdateSelf();
