#ifndef dimming_led_h /* include guards */
#define dimming_led_h

#define dimming_time 1 // minutes
#include "define.h"

typedef struct
{
    int duty;
    bool isDimming;
} dimm_LED_Data;

void led_init();
void dim_led();
void turn_off_led();
void startDimming();

extern dimm_LED_Data dimmLed_Dt;

#endif /* DIMMING_LED_H */