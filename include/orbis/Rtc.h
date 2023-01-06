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

int sceRtcCheckValid(OrbisRtcDateTime *input);
int sceRtcGetTick(const OrbisRtcDateTime *outOrbisRtcDateTime, OrbisRtcTick *outTick);
int sceRtcSetTick(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick);
int sceRtcTickAddDays(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int days);
int sceRtcTickAddHours(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int hours);
int sceRtcTickAddMicroseconds(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t msecs);
int sceRtcTickAddMinutes(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int mins);
int sceRtcTickAddMonths(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int months);
int sceRtcTickAddSeconds(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t seconds);
int sceRtcTickAddTicks(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t ticks);
int sceRtcTickAddWeeks(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int weeks);
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
