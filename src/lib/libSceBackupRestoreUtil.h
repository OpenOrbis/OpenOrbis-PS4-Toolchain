#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceBackupRestoreUtilBackupData();
void sceBackupRestoreUtilCancelBackupData();
void sceBackupRestoreUtilCancelGetRequiredSize();
void sceBackupRestoreUtilCancelGetTitles();
void sceBackupRestoreUtilCancelRestoreData();
void sceBackupRestoreUtilDeleteBackupData();
void sceBackupRestoreUtilGetBackupDataInfo();
void sceBackupRestoreUtilGetBackupParam();
void sceBackupRestoreUtilGetBackupProgress();
void sceBackupRestoreUtilGetRequiredSize();
void sceBackupRestoreUtilGetRestoreProgress();
void sceBackupRestoreUtilGetTitles();
void sceBackupRestoreUtilInitialize();
void sceBackupRestoreUtilPrepareBackup();
void sceBackupRestoreUtilRestoreData();
void sceBackupRestoreUtilTerminate();
