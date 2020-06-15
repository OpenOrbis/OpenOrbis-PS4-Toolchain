#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceSystemServiceDeclareReadyForSuspend();
void sceSystemServiceDisableSuspendNotification();
void sceSystemServiceEnableSuspendNotification();
