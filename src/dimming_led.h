#ifndef dimming_led_h /* include guards */
#define dimming_led_h
#define dimming_time 1 // minutes
#include "define.h"

void led_init();
void dim_led(int led_pin, int dim_time);
void turn_off_led();
bool isDimming();

#endif /* MOD_GPIO_H */