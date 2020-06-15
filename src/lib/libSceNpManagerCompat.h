#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceNpCheckNpAvailability();
void sceNpGetAccountCountry();
void sceNpGetAccountDateOfBirth();
void sceNpGetAccountId();
void sceNpGetAccountLanguage();
void sceNpGetGamePresenceStatus();
void sceNpGetParentalControlInfo();
void sceNpGetUserIdByOnlineId();
void sceNpInGameMessagePrepare();
void sceNpInGameMessageSendData();
void sceNpRegisterGamePresenceCallback();
void sceNpRegisterStateCallback();
void sceNpSetGamePresenceOnline();
void sceNpUnregisterStateCallback();
