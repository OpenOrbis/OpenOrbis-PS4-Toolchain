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
	unsigned short year;
	unsigned short month;
	unsigned short day;
	unsigned short hour;
	unsigned short minute;
	unsigned short second;
	unsigned short microsecond;
} TimeTable;

/**
  * Standard method to verify timestamp is valid or not.
  * @param input is the time table you want to verify.
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcCheckValid(TimeTable *input);

/**
  * Returns the current tick of the Real Time Clock.
  * @param outTimeTable output a current time table.
  * @param outTick is the current tick of the rtc.
  * @return 0 = Valid and Negatives values are error codes. 
  */
int sceRtcGetTick(const TimeTable *outTimeTable, RealTick *outTick);

/**
  * Set the Real Time Clock by given param inputTick
  * @param inputTimeTable the table the tick is stored to.
  * @param inputTick is the tick you wish to supply to SceRtcSetTick
  * @return 0 = Valid and Negatives values are error codes. 
  */
int sceRtcSetTick(TimeTable *inputTimeTable, RealTick *inputTick);

/**
  * Adds Days to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param days
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddDays(TimeTable *inputTimeTable, RealTick *inputTick, int days);

/**
  * Adds hours to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param hours
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddHours(TimeTable *inputTimeTable, RealTick *inputTick, int hours);

/**
  * Add Micro Seconds to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param msecs
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddMicroseconds(TimeTable *inputTimeTable, RealTick *inputTick, int64_t msecs);

/**
  * Add Minutes to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param mins
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddMinutes(TimeTable *inputTimeTable, RealTick *inputTick, int mins);

/**
  * Add Months to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param months
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddMonths(TimeTable *inputTimeTable, RealTick *inputTick, int months);

/**
  * Add seconds to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param seconds
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddSeconds(TimeTable *inputTimeTable, RealTick *inputTick, int64_t seconds);

/**
  * Add ticks to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param ticks
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddTicks(TimeTable *inputTimeTable, RealTick *inputTick, int64_t ticks);

/**
  * Add weaks to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param weeks
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddWeeks(TimeTable *inputTimeTable, RealTick *inputTick, int weeks);

/**
  * Add years to RTC Clock
  * @param inputTimeTable
  * @param inputTick
  * @param years
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddYears(TimeTable *inputTimeTable, RealTick *inputTick, int years);

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

// Undocumented Function... Need to reverse
void sceRtcGetCurrentClockLocalTime();

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




#endif

#ifdef __cplusplus
}
#endif