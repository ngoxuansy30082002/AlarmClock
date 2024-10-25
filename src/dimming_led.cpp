#include "define.h"

dimm_LED_Data dimmLed_Dt;

const int pwmChannel = PIN_DIMM_LED; // PWM channel (0-15)
const int pwmFrequency = 5000;       // Frequency in Hz (adjustable, typically 5000)
const int pwmResolution = 8;         // Resolution (8-bit: 0-255)
int delayTime = 0;
unsigned long previous = 0;

void led_init()
{
    pinMode(PIN_DIMM_LED, OUTPUT);
    ledcSetup(pwmChannel, pwmFrequency, pwmResolution);
    ledcAttachPin(PIN_DIMM_LED, pwmChannel);
}

void dim_led()
{
    static bool isIncrease = true;

    if (dimmLed_Dt.isDimming == false)
        return;

    if (dimmLed_Dt.duty == 255)
        isIncrease = false;
    else if (dimmLed_Dt.duty == 0)
        isIncrease = true;

    unsigned long current = millis();
    if (current - previous >= delayTime)
    {
        previous = current;
        if (isIncrease)
            dimmLed_Dt.duty++;
        else
            dimmLed_Dt.duty--;
    }
    ledcWrite(PIN_DIMM_LED, dimmLed_Dt.duty);
}

void turn_off_led()
{
    ledcWrite(PIN_DIMM_LED, 0);
}
void startDimming()
{
    dimmLed_Dt.isDimming = true;
    dimmLed_Dt.duty = 0;
}
