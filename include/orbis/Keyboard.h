#ifndef _SCE_KEYBOARD_H_
#define _SCE_KEYBOARD_H_

#include <stdint.h>
#include <orbis/_types/keyboard.h>
#include <orbis/_types/errors.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t sceKeyboardInit(void);
int32_t sceKeyboardOpen(int32_t userID, int32_t type, int32_t index, void* param);
int32_t sceKeyboardClose(int32_t handle);
int32_t sceKeyboardReadState(int32_t handle, OrbisKeyboardData* data);
int32_t sceKeyboardGetKey2Char(int32_t handle, bool unknown, int32_t locks, int32_t mods, int32_t keycode, OrbisKeyboardKey2Char* data);

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
