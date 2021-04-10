#ifndef _SCE_KEYBOARD_H_
#define _SCE_KEYBOARD_H_

#include <stdint.h>
#include <orbis/_types/keyboard.h>
#include <orbis/_types/errors.h>

#define SCE_SYSMODULE_KEYBOARD 0x106

#ifdef __cplusplus 
extern "C" {
#endif

int sceKeyboardInit(void);
int sceKeyboardOpen(int userID, int type, int index, void* param);
int sceKeyboardClose(int handle);
int sceKeyboardReadState(int handle, OrbisKeyboardData* data);
int sceKeyboardGetKey2Char(int handle, bool unknown, int locks, int mods, int keycode, OrbisKeyboardKey2Char* data);

// The below functions are currently not reversed
void sceKeyboardConnectPort(void);
void sceKeyboardDebugGetDeviceId(void);
void sceKeyboardDeviceOpen(void);
void sceKeyboardDisconnectDevice(void);
void sceKeyboardDisconnectPort(void);
void sceKeyboardGetConnection(void);
void sceKeyboardGetDeviceInfo(void);
void sceKeyboardMbusInit(void);
void sceKeyboardRead(void);
void sceKeyboardSetProcessFocus(void);
void sceKeyboardSetProcessPrivilege(void);

#ifdef __cplusplus
}
#endif
#endif
