#include "define.h"

const int ledPin = 2;          // Pin connected to the LED
const int pwmChannel = ledPin; // PWM channel (0-15)
const int pwmFrequency = 5000; // Frequency in Hz (adjustable, typically 5000)
const int pwmResolution = 8;   // Resolution (8-bit: 0-255)
int interval = dimming_time * 60000 / 100;
unsigned long previous = 0;
int duty = 0;

void led_init()
{
    ledcSetup(pwmChannel, pwmFrequency, pwmResolution);
    ledcAttachPin(ledPin, pwmChannel);
}

void dim_led(int led_pin, int dim_time)
{
    duty = 0;
    unsigned long current = millis();
    if (current - previous >= interval)
    {
        previous = current;
        duty++;
    }
    ledcWrite(pwmChannel, duty);
}

void turn_off_led()
{
    ledcWrite(pwmChannel, 0);
}

bool isDimming(){
    if(duty >= 99){
        return true;
    }
    return false;
}
