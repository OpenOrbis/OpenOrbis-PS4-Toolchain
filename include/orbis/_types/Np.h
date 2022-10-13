#pragma once
#include <orbis/_types/rtc.h>

/* Np Trophy */
typedef struct OrbisNpTrophyGameDetails 
{
	size_t size;
	uint32_t numGroups;
	uint32_t numTrophies;
	uint32_t numPlatinum;
	uint32_t numGold;
	uint32_t numSilver;
	uint32_t numBronze;
	char title[128];
	char description[1024];
} OrbisNpTrophyGameDetails;

typedef struct OrbisNpTrophyGameData 
{
	size_t size;
	uint32_t unlockedTrophies;
	uint32_t unlockedPlatinum;
	uint32_t unlockedGold;
	uint32_t unlockedSilver;
	uint32_t unlockedBronze;
	uint32_t progressPercentage;
} OrbisNpTrophyGameData;

typedef struct OrbisNpTrophyGroupDetails 
{
	size_t size;
	int32_t groupId;
	uint32_t numTrophies;
	uint32_t numPlatinum;
	uint32_t numGold;
	uint32_t numSilver;
	uint32_t numBronze;
	char title[128];
	char description[1024];
} OrbisNpTrophyGroupDetails;

typedef struct OrbisNpTrophyGroupData
{
	size_t size;
	int32_t groupId;
	uint32_t unlockedTrophies;
	uint32_t unlockedPlatinum;
	uint32_t unlockedGold;
	uint32_t unlockedSilver;
	uint32_t unlockedBronze;
	uint32_t progressPercentage;
	uint8_t UNK00[4];
} OrbisNpTrophyGroupData;

// 
typedef struct OrbisNpTrophyDetails
{
	size_t size;
	int32_t trophyId;
	int32_t trophyGrade;
	int32_t groupId;
	bool hidden;
	char Unk02[3];
	char name[128];
	char description[1024];
} OrbisNpTrophyDetails;

// 
typedef struct OrbisNpTrophyData 
{
	size_t size;
	int32_t trophyId;
	bool unlocked;
	char Unk00[3];
	OrbisRtcTick timestamp;
} OrbisNpTrophyData;

typedef struct OrbisNpTrophyScreenshotTarget 
{
	int32_t context;
	int32_t trophyId;
} OrbisNpTrophyScreenshotTarget;

/* Np Online*/
// 
typedef struct OrbisNpOnlineId 
{
	char data[16];
	char term;
	uint8_t UNK[3];
} OrbisNpOnlineId;

// 
typedef struct OrbisNpId 
{
	OrbisNpOnlineId handle;
	uint8_t Unk20[8];
	uint8_t Unk28[8];
} OrbisNpId;