#pragma once 

#include <stdint.h>


#define ORBIS_USER_SERVICE_MAX_LOGIN_USERS      4   //Maximum number of users that can be logged in at once
#define ORBIS_USER_SERVICE_MAX_REGISTER_USERS   16  //Maximum number of users that can be registered in the system
#define ORBIS_USER_SERVICE_MAX_USER_NAME_LENGTH 16  //Maximum user name length

#define ORBIS_USER_SERVICE_USER_ID_SYSTEM 0xFF
#define ORBIS_USER_SERVICE_USER_ID_INVALID	-1

typedef int32_t OrbisUserServiceUserId;

#define ORBIS_KERNEL_PRIO_FIFO_LOWEST  0x2FF
#define ORBIS_KERNEL_PRIO_FIFO_NORMAL  0x2BC
#define ORBIS_KERNEL_PRIO_FIFO_HIGHEST 0x100

typedef struct OrbisUserServiceInitializeParams {
	uint32_t priority;
} OrbisUserServiceInitializeParams;

typedef struct OrbisUserServiceLoginUserIdList {
	OrbisUserServiceUserId userId[ORBIS_USER_SERVICE_MAX_LOGIN_USERS];
} OrbisUserServiceLoginUserIdList;

typedef struct OrbisUserServiceRegisteredUserIdList {
	OrbisUserServiceUserId userId[ORBIS_USER_SERVICE_MAX_REGISTER_USERS];
} OrbisUserServiceRegisteredUserIdList;

typedef enum OrbisUserServiceUserColor {
	ORBIS_USER_SERVICE_USER_COLOR_BLUE 	= 0,
	ORBIS_USER_SERVICE_USER_COLOR_RED 	= 1,
	ORBIS_USER_SERVICE_USER_COLOR_GREEN	= 2,
	ORBIS_USER_SERVICE_USER_COLOR_PINK 	= 3,
} OrbisUserServiceUserColor;

typedef enum OrbisUserServiceEventType {
	SCE_USER_SERVICE_EVENT_TYPE_LOGIN  = 0,		// Login event
	SCE_USER_SERVICE_EVENT_TYPE_LOGOUT = 1,		// Logout event
} OrbisUserServiceEventType;

typedef struct OrbisUserServiceEvent {
    OrbisUserServiceEventType event;
    OrbisUserServiceUserId userId;
} OrbisUserServiceEvent;
