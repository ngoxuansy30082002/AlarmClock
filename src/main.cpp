#include "define.h"

TimerMode mode = TIMER_REPEAT;

void callback1()
{
  Serial.println("Callback 1 triggered!");
}

// Callback function 2
void callback2()
{
  Serial.println("Callback 2 triggered!");
}

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  MOD_GPIO_Init();
  MOD_TIMER_Init(200); // 200ms
  MOD_TIMER_HandlerRegister(5000, callback1, TIMER_REPEAT);
  MOD_TIMER_HandlerRegister(3000, callback2, TIMER_REPEAT);
}

void loop()
{
  MOD_TIMER_Task();
}
