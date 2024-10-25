#ifndef MOD_OLED_H /* include guards */
#define MOD_OLED_H
#include "define.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

typedef enum
{
    OLED_INIT = 0,
    OLED_DISPLAY_HOME,
    OLED_DISPLAY_MENU,
    OLED_DISPLAY_SET_CUR_TIME,
    OLED_DISPLAY_SET_ALARM_TIME,
    OLED_DISPLAY_BATTERY_LOW,
    OLED_DISPLAY_ALARM
} OLED_display_state_t;

typedef struct
{
    bool sleepFlag;
    OLED_display_state_t state;
} mod_oled_data;

void MOD_OLED_Init();
void MOD_OLED_Task();
void MOD_OLED_EnterState(OLED_display_state_t state);
void MOD_OLED_wakeUp();
extern mod_oled_data modOledDt;

#endif /* MOD_OLED_H */