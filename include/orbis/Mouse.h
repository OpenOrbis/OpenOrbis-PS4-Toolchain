#ifndef _SCE_MOUSE_H_
#define _SCE_MOUSE_H_

#include <stdint.h>
#include "orbis/_types/mouse.h"

#ifdef __cplusplus 
extern "C" 
{
#endif

int32_t sceMouseInit();
int32_t sceMouseOpen(int32_t userID, int32_t type, int32_t index, const OrbisMouseOpenParam*);
int32_t sceMouseClose(int32_t);
int32_t sceMouseRead(int32_t handle, OrbisMouseData*, int32_t num);

void sceMouseSetPointerSpeed();

#ifdef __cplusplus
}
#endif
#endif