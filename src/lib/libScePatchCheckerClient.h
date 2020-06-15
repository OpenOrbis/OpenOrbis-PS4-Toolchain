#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void scePatchCheckerCancel();
void scePatchCheckerCheckPatch();
void scePatchCheckerClearCache();
void scePatchCheckerCreateHandler();
void scePatchCheckerDestroyHandler();
void scePatchCheckerDisableAutoDownload();
void scePatchCheckerEnableAutoDownload();
void scePatchCheckerGetApplicableTick();
void scePatchCheckerGetPackageInfo();
void scePatchCheckerInitialize();
void scePatchCheckerRequestCheckPatch();
void scePatchCheckerRequestCheckPatchByType();
void scePatchCheckerSetCache();
void scePatchCheckerSetFakeCache();
void scePatchCheckerTerminate();
