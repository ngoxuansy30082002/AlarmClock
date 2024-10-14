#include "define.h"

TimerMode mode = TIMER_REPEAT;

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  MOD_GPIO_Init();
  MOD_TIMER_Init(200); // 200ms
  MOD_TIMER_HandlerRegister(1000, MOD_GPIO_Task, TIMER_REPEAT);
}

void loop()
{
  MOD_TIMER_Task();
}
