/**
 * @package sce_rtc
 * Documentation for the orbis Real Time Clock. by CrazyVoid
 * Updated 4/13/2019
 */

#ifndef _SCE_RTC_H_
#define _SCE_RTC_H_

#include <stdint.h>

#ifdef __cplusplus 
extern "C" {
#endif

/*! \struct RealTick
	\brief a tick to supply to orbis rtc functions.
	RealTick is just an uint64_t value used to represent tick value. 
*/
typedef struct RealTick {
	uint64_t mytick;
} RealTick;

/*! \struct TimeTable
	\brief TimeTable is an struct used to store time information. from year to microseconds.
	The struct has entrys for (year, month, day, hour, minute, second, microsecond)
*/
typedef struct TimeTable {
	uint16_t year;
	uint16_t month;
	uint16_t day;
	uint16_t hour;
	uint16_t minute;
	uint16_t second;
	uint16_t microsecond;
} TimeTable;

/**
  * Standard method to verify timestamp is valid or not.
  * @param input is the time table you want to verify.
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcCheckValid(TimeTable *input);

/**
  * Returns the current tick of the Real Time Clock.
  * @param outTimeTable output a current time table.
  * @param outTick is the current tick of the rtc.
  * @return 0 = Valid and Negatives values are error codes. 
  */
int32_t sceRtcGetTick(const TimeTable *outTimeTable, RealTick *outTick);

/**
  * Set the Real Time Clock by given param inputTick
  * @param inputTimeTable the table the tick is stored to.
  * @param inputTick is the tick you wish to supply to SceRtcSetTick
  * @return 0 = Valid and Negatives values are error codes. 
  */
int32_t sceRtcSetTick(TimeTable *inputTimeTable, RealTick *inputTick);

/**
  * Adds Days to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param days
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddDays(TimeTable *inputTimeTable, RealTick *inputTick, int32_t days);

/**
  * Adds hours to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param hours
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddHours(TimeTable *inputTimeTable, RealTick *inputTick, int32_t hours);

/**
  * Add Micro Seconds to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param msecs
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddMicroseconds(TimeTable *inputTimeTable, RealTick *inputTick, int64_t msecs);

/**
  * Add Minutes to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param mins
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddMinutes(TimeTable *inputTimeTable, RealTick *inputTick, int32_t mins);

/**
  * Add Months to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param months
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddMonths(TimeTable *inputTimeTable, RealTick *inputTick, int32_t months);

/**
  * Add seconds to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param seconds
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddSeconds(TimeTable *inputTimeTable, RealTick *inputTick, int64_t seconds);

/**
  * Add ticks to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param ticks
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddTicks(TimeTable *inputTimeTable, RealTick *inputTick, int64_t ticks);

/**
  * Add weaks to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param weeks
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddWeeks(TimeTable *inputTimeTable, RealTick *inputTick, int32_t weeks);

/**
  * Add years to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param years
  * @return 0 = Valid and Negatives values are error codes.
  */
int32_t sceRtcTickAddYears(TimeTable *inputTimeTable, RealTick *inputTick, int32_t years);

// These two functions are internal to the prx i think. -cv
// Unused Functions ? will remain commented for now!
//void sceRtcInit();
// Unused Function? will remain commented for now
//void sceRtcEnd();

// All functions below need reversed and prototypes and comments filled in.
// As of right now these functions might react unexpected until reversed and documented

// Undocumented Function... Need to reverse
void sceRtcCompareTick();

// Undocumented Function... Need to reverse
void sceRtcConvertLocalTimeToUtc();

// Undocumented Function... Need to reverse
void sceRtcConvertUtcToLocalTime();

// Undocumented Function... Need to reverse
void sceRtcFormatRFC2822();

// Undocumented Function... Need to reverse
void sceRtcFormatRFC2822LocalTime();

// Undocumented Function... Need to reverse
void sceRtcFormatRFC3339();

// Undocumented Function... Need to reverse
void sceRtcFormatRFC3339LocalTime();

// Undocumented Function... Need to reverse
void sceRtcGetCurrentAdNetworkTick();

// Undocumented Function... Need to reverse
void sceRtcGetCurrentClock();

// 0x0        = OK
// 0x80B50002 = pointer is invalid
// needs more RE to fully understand
int32_t sceRtcGetCurrentClockLocalTime(TimeTable*);

// Undocumented Function... Need to reverse
void sceRtcGetCurrentDebugNetworkTick();

// Undocumented Function... Need to reverse
void sceRtcGetCurrentNetworkTick();

// Undocumented Function... Need to reverse
void sceRtcGetCurrentTick();

// Undocumented Function... Need to reverse
void sceRtcGetDayOfWeek();

// Undocumented Function... Need to reverse
void sceRtcGetDaysInMonth();

// Undocumented Function... Need to reverse
void sceRtcGetDosTime();

// Undocumented Function... Need to reverse
void sceRtcGetTickResolution();

// Undocumented Function... Need to reverse
void sceRtcGetTime_t();

// Undocumented Function... Need to reverse
void sceRtcGetWin32FileTime();

// Undocumented Function... Need to reverse
void sceRtcIsLeapYear();

// Undocumented Function... Need to reverse
void sceRtcParseDateTime();

// Undocumented Function... Need to reverse
void sceRtcParseRFC3339();

// Undocumented Function... Need to reverse
void sceRtcSetConf();

// Undocumented Function... Need to reverse
void sceRtcSetCurrentTick();

// Undocumented Function... Need to reverse
void sceRtcSetDosTime();

// Undocumented Function... Need to reverse
void sceRtcSetTime_t();

// Undocumented Function... Need to reverse
void sceRtcSetWin32FileTime();

#ifdef __cplusplus
}
#endif
#endif
