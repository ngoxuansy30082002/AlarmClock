#include "define.h"

TimerMode mode = TIMER_REPEAT;

void setup()
{  
  MOD_GPIO_Init();
  MOD_OLED_Init();
  MOD_MODBUSRTU_Init();
  MOD_TIMER_Init(200); // 200ms
  MOD_TIMER_HandlerRegister(200, MOD_GPIO_Task, TIMER_REPEAT);
  MOD_TIMER_HandlerRegister(3000, MOD_MODBUSRTU_Task, TIMER_REPEAT);
}
void loop()
{
  MOD_TIMER_Task();
  MOD_OLED_Task();
}
