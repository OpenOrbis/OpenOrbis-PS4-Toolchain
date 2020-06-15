#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceUpsrvGetCompletedTaskId();
void sceUpsrvGetRebootFlag();
void sceUpsrvGetSystemExUpdateTaskState();
void sceUpsrvInitialize();
void sceUpsrvPostErrorLog();
void sceUpsrvResumePausedTask();
void sceUpsrvSwitchSystemExBank();
void sceUpsrvSwitchSystemExBankWithoutVerify();
void sceUpsrvTerminate();
void sceUpsrvUpdateCancelBDUpdate();
void sceUpsrvUpdateCheckCancel();
void sceUpsrvUpdateCheckCreateHandler();
void sceUpsrvUpdateCheckDestroyHandler();
void sceUpsrvUpdateCheckDoCheckSystem();
void sceUpsrvUpdateCheckDoCheckSystemBeta();
void sceUpsrvUpdateCheckDoCheckSystemForDevKit();
void sceUpsrvUpdateCheckDoCheckSystemForSettings();
void sceUpsrvUpdateCheckDoCheckSystemVersionDown();
void sceUpsrvUpdateCheckDoCheckSystemWithPupInfo();
void sceUpsrvUpdateCheckGetUpdatelistURL();
void sceUpsrvUpdateCreateUpdateTask();
void sceUpsrvUpdateDestroyUpdateTask();
void sceUpsrvUpdateDoCheckBootUpdate();
void sceUpsrvUpdateDoUpdate();
void sceUpsrvUpdateDoUpdateBeta();
void sceUpsrvUpdateDoUpdateSystemEx();
void sceUpsrvUpdateDoUpdateWithHandler();
void sceUpsrvUpdateDoUpdateWithPupInfo();
void sceUpsrvUpdateDoUpdateWithPupPath();
void sceUpsrvUpdateGetBetaAgreementUrl();
void sceUpsrvUpdateGetBetaAgreementUrlForUpdate();
void sceUpsrvUpdateGetBetaFeatureListUrlForUpdate();
void sceUpsrvUpdateGetDownloadProgress();
void sceUpsrvUpdateGetEulaDisplay();
void sceUpsrvUpdateGetEulaStr();
void sceUpsrvUpdateGetEulaStrLen();
void sceUpsrvUpdateGetFeatureListUrl();
void sceUpsrvUpdateGetFeatureListUrlForSystemExUpdate();
void sceUpsrvUpdateGetFeatureListUrlForUpdate();
void sceUpsrvUpdateGetImageWritingProgress();
void sceUpsrvUpdateGetObfuscatedString();
void sceUpsrvUpdateGetUpdateTaskInfo();
void sceUpsrvUpdateGetUpdateTaskMgrInfo();
void sceUpsrvUpdateSetEulaAccept();
void sceUpsrvUpdateSetUpdateMode();
void sceUpsrvUpdateStartUpdateTask();
void sceUpsrvVerifySystemExBank();
