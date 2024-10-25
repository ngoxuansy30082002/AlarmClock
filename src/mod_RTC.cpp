#include "mod_RTC.h"

// TwoWire wire;
RTC_DS1307 rtc;
mod_RTC_Data modRtc_Dt;

void MOD_RTC_SetCustomDateTime()
{
    if (rtc.isrunning())
    {
        DateTime customDateTime(2024, 10, 21, modGpioDt.hour, modGpioDt.minute, 0);
        rtc.adjust(customDateTime);
    }
    MOD_RTC_Task();
}
void MOD_RTC_Init()
{
    Wire.begin(PIN_RTC_SDA, PIN_RTC_SCL);
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
    }
}
void MOD_RTC_Task()
{
    DateTime now = rtc.now();
    modRtc_Dt.cur_Time.hour = now.hour();
    modRtc_Dt.cur_Time.minute = now.minute();
    MOD_OLED_wakeUp(); // mới thêm vô cẩn thận chỗ này
}