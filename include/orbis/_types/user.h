#pragma once 

#include <stdint.h>

#define ORBIS_USER_SERVICE_USER_ID_SYSTEM 0xFF

typedef int OrbisUserServiceUserId;

#define ORBIS_KERNEL_PRIO_FIFO_LOWEST  0x2FF
#define ORBIS_KERNEL_PRIO_FIFO_NORMAL  0x2BC
#define ORBIS_KERNEL_PRIO_FIFO_HIGHEST 0x100

typedef struct OrbisUserServiceInitializeParams {
	uint32_t priority;
} OrbisUserServiceInitializeParams;
