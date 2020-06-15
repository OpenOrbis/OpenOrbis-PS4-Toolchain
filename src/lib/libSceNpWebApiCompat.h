#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceNpWebApiCreateContext();
void sceNpWebApiCreatePushEventFilter();
void sceNpWebApiCreateServicePushEventFilter();
void sceNpWebApiDeletePushEventFilter();
void sceNpWebApiDeleteServicePushEventFilter();
void sceNpWebApiRegisterExtdPushEventCallback();
void sceNpWebApiRegisterNotificationCallback();
void sceNpWebApiRegisterPushEventCallback();
void sceNpWebApiRegisterServicePushEventCallback();
void sceNpWebApiUnregisterNotificationCallback();
void sceNpWebApiUnregisterPushEventCallback();
void sceNpWebApiUnregisterServicePushEventCallback();
