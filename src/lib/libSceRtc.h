#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void sceRtcCheckValid();
void sceRtcCompareTick();
void sceRtcConvertLocalTimeToUtc();
void sceRtcConvertUtcToLocalTime();
void sceRtcEnd();
void sceRtcFormatRFC2822();
void sceRtcFormatRFC2822LocalTime();
void sceRtcFormatRFC3339();
void sceRtcFormatRFC3339LocalTime();
void sceRtcGetCurrentAdNetworkTick();
void sceRtcGetCurrentClock();
void sceRtcGetCurrentClockLocalTime();
void sceRtcGetCurrentDebugNetworkTick();
void sceRtcGetCurrentNetworkTick();
void sceRtcGetCurrentRawNetworkTick();
void sceRtcGetCurrentTick();
void sceRtcGetDayOfWeek();
void sceRtcGetDaysInMonth();
void sceRtcGetDosTime();
void sceRtcGetTick();
void sceRtcGetTickResolution();
void sceRtcGetTime_t();
void sceRtcGetWin32FileTime();
void sceRtcInit();
void sceRtcIsLeapYear();
void sceRtcParseDateTime();
void sceRtcParseRFC3339();
void sceRtcSetConf();
void sceRtcSetCurrentAdNetworkTick();
void sceRtcSetCurrentDebugNetworkTick();
void sceRtcSetCurrentNetworkTick();
void sceRtcSetCurrentTick();
void sceRtcSetDosTime();
void sceRtcSetTick();
void sceRtcSetTime_t();
void sceRtcSetWin32FileTime();
void sceRtcTickAddDays();
void sceRtcTickAddHours();
void sceRtcTickAddMicroseconds();
void sceRtcTickAddMinutes();
void sceRtcTickAddMonths();
void sceRtcTickAddSeconds();
void sceRtcTickAddTicks();
void sceRtcTickAddWeeks();
void sceRtcTickAddYears();
