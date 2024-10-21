#ifndef MOD_RTC_H /* include guards */
#define MOD_RTC_H

#include "define.h"

typedef struct
{
    struct
    {
        int hour;
        int minute;
    } cur_Time;
    struct
    {
        int hour;
        int minute;
    } alarm_Time;
} mod_RTC_Data;

void MOD_RTC_Init();
void MOD_RTC_Task();
void MOD_RTC_SetCustomDateTime();
extern mod_RTC_Data modRtc_Dt;

#endif /* MOD_RTC_H */