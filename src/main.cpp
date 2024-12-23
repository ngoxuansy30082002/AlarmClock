#include "define.h"

void setup()
{
  Serial.begin(9600);
  led_init();
  MOD_GPIO_Init();
  MOD_OLED_Init();
  MOD_RTC_Init();
  MOD_ADC_Init();
  MOD_MODBUSRTU_Init();
  MOD_TIMER_Init(200); // 200ms
  // MOD_TIMER_HandlerRegister(200, MOD_GPIO_Task, TIMER_REPEAT);
  MOD_TIMER_HandlerRegister(3000, MOD_MODBUSRTU_Task, TIMER_REPEAT);
  MOD_TIMER_HandlerRegister(1000, MOD_RTC_Task, TIMER_ONCE);
  MOD_TIMER_HandlerRegister(30000, MOD_RTC_Task, TIMER_REPEAT);
  MOD_TIMER_HandlerRegister(3000, MOD_ADC_Task, TIMER_REPEAT);
}
void loop()
{
  MOD_TIMER_Task();
  MOD_OLED_Task();
  dim_led();
}

