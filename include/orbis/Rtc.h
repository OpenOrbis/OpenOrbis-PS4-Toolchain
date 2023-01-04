/**
 * @package sce_rtc
 * Documentation for the orbis Real Time Clock. by CrazyVoid
 * Updated 4/13/2019
 */

#ifndef _SCE_RTC_H_
#define _SCE_RTC_H_

#include "_types/rtc.h"
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus 
extern "C" {
#endif

/**
  * Standard method to verify timestamp is valid or not.
  * @param input is the time table you want to verify.
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcCheckValid(OrbisRtcDateTime *input);

/**
  * Returns the current tick of the Real Time Clock.
  * @param outOrbisRtcDateTime output a current time table.
  * @param outTick is the current tick of the rtc.
  * @return 0 = Valid and Negatives values are error codes. 
  */
int sceRtcGetTick(const OrbisRtcDateTime *outOrbisRtcDateTime, OrbisRtcTick *outTick);

/**
  * Set the Real Time Clock by given param inputTick
  * @param inputOrbisRtcDateTime the table the tick is stored to.
  * @param inputTick is the tick you wish to supply to SceRtcSetTick
  * @return 0 = Valid and Negatives values are error codes. 
  */
int sceRtcSetTick(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick);

/**
  * Adds Days to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param days
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddDays(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int days);

/**
  * Adds hours to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param hours
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddHours(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int hours);

/**
  * Add Micro Seconds to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param msecs
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddMicroseconds(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t msecs);

/**
  * Add Minutes to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param mins
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddMinutes(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int mins);

/**
  * Add Months to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param months
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddMonths(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int months);

/**
  * Add seconds to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param seconds
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddSeconds(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t seconds);

/**
  * Add ticks to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param ticks
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddTicks(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t ticks);

/**
  * Add weaks to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param weeks
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddWeeks(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int weeks);

/**
  * Add years to RTC Clock
  * @param inputOrbisRtcDateTime
  * @param inputTick
  * @param years
  * @return 0 = Valid and Negatives values are error codes.
  */
int sceRtcTickAddYears(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int years);
int sceRtcConvertLocalTimeToUtc(OrbisRtcTick*, OrbisRtcTick*);
int sceRtcConvertUtcToLocalTime(OrbisRtcTick*, OrbisRtcTick*);
int sceRtcGetCurrentClock(OrbisRtcDateTime*);
int sceRtcGetCurrentClockLocalTime(OrbisRtcDateTime*);
int sceRtcGetCurrentNetworkTick(OrbisRtcTick*);
int sceRtcGetCurrentTick(OrbisRtcTick*);
int sceRtcGetDaysInMonth(int year, int month);
int sceRtcIsLeapYear(int year);
int sceRtcParseRFC3339(OrbisRtcTick*, const char*);
int sceRtcParseDateTime(OrbisRtcTick*, const char*);
int sceRtcFormatRFC3339LocalTime(char*, OrbisRtcTick*);
int sceRtcFormatRFC3339(char*, OrbisRtcTick*, int);
int sceRtcFormatRFC2822LocalTime(char*, OrbisRtcTick*);
int sceRtcFormatRFC2822(char*, OrbisRtcTick*, int);
int sceRtcGetDayOfWeek(int y, int m, int d);
int sceRtcGetTime_t(OrbisRtcDateTime*, time_t*);
int sceRtcSetTime_t(OrbisRtcDateTime*, time_t);
int sceRtcGetDosTime(OrbisRtcDateTime*, unsigned int*);
int sceRtcSetWin32FileTime(OrbisRtcDateTime*, uint64_t);
int sceRtcGetWin32FileTime(OrbisRtcDateTime*, uint64_t*);
int sceRtcSetDosTime(OrbisRtcDateTime*, unsigned int);

unsigned int sceRtcGetTickResolution();
int sceRtcGetCurrentDebugNetworkTick();
int sceRtcGetCurrentAdNetworkTick();
int sceRtcCompareTick();
int sceRtcSetConf();
int sceRtcSetCurrentTick();

#ifdef __cplusplus
}
#endif
#endif
