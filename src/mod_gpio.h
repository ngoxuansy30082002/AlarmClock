#ifndef MOD_GPIO_H /* include guards */
#define MOD_GPIO_H

#include "define.h"

typedef enum
{
    MODE_HOME = 0,
    MODE_MENU,
    MODE_SET_CUR_TIME,
    MODE_SET_ALARM_TIME,
} mod_t;

typedef enum
{
    HOUR = 0,
    MINUTE,
} time_type_t;

typedef struct
{
    mod_t mode;
    time_type_t timeType;
    int hour;
    int minute;
} mod_gpio_data;

void MOD_GPIO_Init();
void MOD_GPIO_Task();

extern volatile mod_gpio_data modGpioDt;

#endif /* MOD_GPIO_H */