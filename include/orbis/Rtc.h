#ifndef _SCE_RTC_H_
#define _SCE_RTC_H_

#include "_types/rtc.h"
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus 
extern "C" {
#endif

int32_t sceRtcCheckValid(OrbisRtcDateTime *input);
int32_t sceRtcGetTick(const OrbisRtcDateTime *outOrbisRtcDateTime, OrbisRtcTick *outTick);
int32_t sceRtcSetTick(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick);
int32_t sceRtcTickAddDays(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int32_t days);
int32_t sceRtcTickAddHours(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int32_t hours);
int32_t sceRtcTickAddMicroseconds(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t msecs);
int32_t sceRtcTickAddMinutes(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int32_t mins);
int32_t sceRtcTickAddMonths(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int32_t months);
int32_t sceRtcTickAddSeconds(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t seconds);
int32_t sceRtcTickAddTicks(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int64_t ticks);
int32_t sceRtcTickAddWeeks(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int32_t weeks);
int32_t sceRtcTickAddYears(OrbisRtcDateTime *inputOrbisRtcDateTime, OrbisRtcTick *inputTick, int32_t years);
int32_t sceRtcConvertLocalTimeToUtc(OrbisRtcTick*, OrbisRtcTick*);
int32_t sceRtcConvertUtcToLocalTime(OrbisRtcTick*, OrbisRtcTick*);
int32_t sceRtcGetCurrentClock(OrbisRtcDateTime*);
int32_t sceRtcGetCurrentClockLocalTime(OrbisRtcDateTime*);
int32_t sceRtcGetCurrentNetworkTick(OrbisRtcTick*);
int32_t sceRtcGetCurrentTick(OrbisRtcTick*);
int32_t sceRtcGetDaysInMonth(int32_t year, int32_t month);
int32_t sceRtcIsLeapYear(int32_t year);
int32_t sceRtcParseRFC3339(OrbisRtcTick*, const char*);
int32_t sceRtcParseDateTime(OrbisRtcTick*, const char*);
int32_t sceRtcFormatRFC3339LocalTime(char*, OrbisRtcTick*);
int32_t sceRtcFormatRFC3339(char*, OrbisRtcTick*, int32_t);
int32_t sceRtcFormatRFC2822LocalTime(char*, OrbisRtcTick*);
int32_t sceRtcFormatRFC2822(char*, OrbisRtcTick*, int32_t);
int32_t sceRtcGetDayOfWeek(int32_t y, int32_t m, int32_t d);
int32_t sceRtcGetTime_t(OrbisRtcDateTime*, time_t*);
int32_t sceRtcSetTime_t(OrbisRtcDateTime*, time_t);
int32_t sceRtcGetDosTime(OrbisRtcDateTime*, uint32_t*);
int32_t sceRtcSetWin32FileTime(OrbisRtcDateTime*, uint64_t);
int32_t sceRtcGetWin32FileTime(OrbisRtcDateTime*, uint64_t*);
int32_t sceRtcSetDosTime(OrbisRtcDateTime*, uint32_t);

uint32_t sceRtcGetTickResolution();
int32_t sceRtcGetCurrentDebugNetworkTick();
int32_t sceRtcGetCurrentAdNetworkTick();
int32_t sceRtcCompareTick();
int32_t sceRtcSetConf();
int32_t sceRtcSetCurrentTick();

#ifdef __cplusplus
}
#endif
#endif
