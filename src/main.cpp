#include "mod_gpio.h"

void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  MOD_GPIO_Init();
}

void loop()
{
  MOD_GPIO_Task();
  delay(100);
}
