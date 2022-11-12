#pragma once
#include <orbis/_types/rtc.h>

/* Np Trophy */

typedef struct OrbisNpTrophyFlagArray
{
	uint32_t bits[128 >> 5];
} OrbisNpTrophyFlagArray;

typedef struct OrbisNpTrophyGameDetails 
{
	size_t size;			// This needs to be set with sizeof(OrbisNpTrophyGameDetails) or any function that takes this structure as a parameter will return a error(0x80551604)
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
	size_t size;			// This needs to be set with sizeof(OrbisNpTrophyGameData) or any function that takes this structure as a parameter will return a error(0x80551604)
	uint32_t unlockedTrophies;
	uint32_t unlockedPlatinum;
	uint32_t unlockedGold;
	uint32_t unlockedSilver;
	uint32_t unlockedBronze;
	uint32_t progressPercentage;
} OrbisNpTrophyGameData;

typedef struct OrbisNpTrophyGroupDetails 
{
	size_t size;			// This needs to be set with sizeof(OrbisNpTrophyGroupDetails) or any function that takes this structure as a parameter will return a error(0x80551604)
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
	size_t size;				// This needs to be set with sizeof(OrbisNpTrophyGroupData) or any function that takes this structure as a parameter will return a error(0x80551604)
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
	size_t size; 			// This needs to be set with sizeof(OrbisNpTrophyDetails) or any function that takes this structure as a parameter will return a error(0x80551604)
	int32_t trophyId; 		// Trophy ID, 1-XXXX(0 should be the Platinum Trophy)
	int32_t trophyGrade;	// gold/silver/bronze/Platinum
	int32_t groupId;		// group where the trophy is located(normally 0 for single group trophy packs, depending on how many trophies exists and are split into groups inside the pack this could rage from 0 - xxxx)
	bool hidden; 			// this determines if you can see the trophy before its unlocked(hidden flagged trophys will not allow you to see the description until you have unlcoked them)
	char Unk02[3]; 			// Unkown data
	char name[128]; 		// Trophy Name, EX: "UNLOCK ME"
	char description[1024]; // Description, EX: "This is what needs to be unlocked"
} OrbisNpTrophyDetails;

// 
typedef struct OrbisNpTrophyData 
{
	size_t size;			// this needs to be set with sizeof(OrbisNpTrophyData) or any function that takes this structure as a parameter will return a error(0x80551604)
	int32_t trophyId;		// Trophy ID, 1-XXXX(0 should be the Platinum Trophy)
	bool unlocked;			// flag that tells if the user has unlocked the Trophy)
	char Unk00[3];			// likely padding, not sure why they didn't make unlocked a 32-bit value and swap a single bit for it, it would make it automaticlly alligned.
	OrbisRtcTick timestamp;	// RTC time stamp of when the trophy is unlocked(this isn't fully accurate due to the RTC drifting, it can be off anywhere from +1 second to a whole minute+ behind.)
} OrbisNpTrophyData;

typedef struct OrbisNpTrophyScreenshotTarget 
{
	int32_t context;	// same context that comes form sceNpTrophyCreateContext once created.
	int32_t trophyId;	// Trophy ID, 1-XXXX(0 should be the Platinum Trophy)
} OrbisNpTrophyScreenshotTarget;

/* Np Online*/
// 
typedef struct OrbisNpOnlineId 
{
	char data[16]; 	// account name, follows PSN schema, min 3/max 16
	char term; 		// terminator, always '\0'?
	uint8_t UNK[3]; // Unkown, probably reserved/padding?
} OrbisNpOnlineId;

// 
typedef struct OrbisNpId 
{
	OrbisNpOnlineId handle;
	uint8_t Unk20[8];
	uint8_t Unk28[8];
} OrbisNpId;