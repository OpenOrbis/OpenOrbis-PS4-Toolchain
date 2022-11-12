#include <stdint.h>

typedef struct OrbisRtcTick 
{
	uint64_t Ticks;
} OrbisRtcTick;

typedef struct OrbisRtcDateTime
{
	uint16_t year;
	uint16_t month;
	uint16_t day;
	uint16_t hour;
	uint16_t minute;
	uint16_t second;
	uint32_t microsecond;
} OrbisRtcDateTime;