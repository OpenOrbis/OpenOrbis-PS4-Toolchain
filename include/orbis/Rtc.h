#ifndef _SCE_RTC_H_
#define _SCE_RTC_H_

#include "_types/rtc.h"
#include <stdint.h>
#include <time.h>

#ifdef __cplusplus 
extern "C" 
{
#endif

int32_t sceRtcCheckValid(const OrbisRtcDateTime* time);
int32_t sceRtcGetTick(const OrbisRtcDateTime* time, OrbisRtcTick* tick);
int32_t sceRtcSetTick(OrbisRtcDateTime* time, const OrbisRtcTick* tick);
int32_t sceRtcTickAddDays(OrbisRtcDateTime* tick, const OrbisRtcTick* tick, int32_t add);
int32_t sceRtcTickAddHours(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int32_t add);
int32_t sceRtcTickAddMicroseconds(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int64_t add);
int32_t sceRtcTickAddMinutes(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int32_t add);
int32_t sceRtcTickAddMonths(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int32_t add);
int32_t sceRtcTickAddSeconds(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int64_t add);
int32_t sceRtcTickAddTicks(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int64_t add);
int32_t sceRtcTickAddWeeks(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int32_t add);
int32_t sceRtcTickAddYears(OrbisRtcDateTime* tick, const OrbisRtcTick* tick1, int32_t add);
int32_t sceRtcConvertLocalTimeToUtc(const OrbisRtcTick* localtime, OrbisRtcTick* utc);
int32_t sceRtcConvertUtcToLocalTime(const OrbisRtcTick* utc, OrbisRtcTick* localtime);
int32_t sceRtcGetCurrentClock(OrbisRtcDateTime* time, int32_t timezone);
int32_t sceRtcGetCurrentClockLocalTime(OrbisRtcDateTime* time);
int32_t sceRtcGetCurrentNetworkTick(OrbisRtcTick* tick);
int32_t sceRtcGetCurrentTick(OrbisRtcTick* tick);
int32_t sceRtcGetDaysInMonth(int32_t year, int32_t month);
int32_t sceRtcIsLeapYear(int32_t year);
int32_t sceRtcParseRFC3339(OrbisRtcTick* utc, const char* datetime);
int32_t sceRtcParseDateTime(OrbisRtcTick* utc, const char* datetime);
int32_t sceRtcFormatRFC3339LocalTime(char* datetime, const OrbisRtcTick* utc);
int32_t sceRtcFormatRFC3339(char* datetime, const OrbisRtcTick* utc, int32_t timezoneMinutes);
int32_t sceRtcFormatRFC2822LocalTime(char* datetime, const OrbisRtcTick* utc);
int32_t sceRtcFormatRFC2822(char* datetime, const OrbisRtcTick* utc, int32_t timezoneMinutes);
int32_t sceRtcGetDayOfWeek(int32_t year, int32_t month, int32_t day);
int32_t sceRtcGetTime_t(const OrbisRtcDateTime* rtctime, time_t* time);
int32_t sceRtcSetTime_t(OrbisRtcDateTime* rtctime, time_t time);
int32_t sceRtcGetDosTime(const OrbisRtcDateTime* time, uint32_t* dosTime);
int32_t sceRtcSetWin32FileTime(OrbisRtcDateTime* time, uint64_t win32Time);
int32_t sceRtcGetWin32FileTime(const OrbisRtcDateTime* time, uint64_t* win32Time);
int32_t sceRtcSetDosTime(OrbisRtcDateTime* Time, uint32_t dosTime);
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
