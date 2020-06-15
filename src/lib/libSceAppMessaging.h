#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceAppMessagingClearEventFlag();
void sceAppMessagingReceiveMsg();
void sceAppMessagingSendMsg();
void sceAppMessagingSendMsgToShellCore();
void sceAppMessagingSendMsgToShellUI();
void sceAppMessagingSetEventFlag();
void sceAppMessagingTryGetEventFlag();
void sceAppMessagingTryReceiveMsg();
