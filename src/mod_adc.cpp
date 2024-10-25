#include "mod_adc.h"

mod_adc_data modAdc_Dt;

void MOD_ADC_Init()
{
    adcAttachPin(PIN_ADC_MEASURE);

    // Set ADC parameters
    analogReadResolution(12);                           // Set ADC resolution
    analogSetClockDiv(1);                               // Set ADC clock divider
    analogSetAttenuation(ADC_11db);                     // Set global attenuation level
    analogSetPinAttenuation(PIN_ADC_MEASURE, ADC_11db); // Set attenuation for the specific pin
}
void MOD_ADC_Task()
{
    int miliVoltage = analogReadMilliVolts(PIN_ADC_MEASURE);
    modAdc_Dt.percentBat = map(miliVoltage, 2000, 2500, 0, 100);
    if (modAdc_Dt.percentBat >= 100)
        modAdc_Dt.percentBat = 99;
    if (modAdc_Dt.percentBat <= 0)
        modAdc_Dt.percentBat = 0;
    if (modAdc_Dt.percentBat < 10)
        MOD_OLED_EnterState(OLED_DISPLAY_BATTERY_LOW);
    if (modAdc_Dt.percentBat >= 10 && modOledDt.state == OLED_DISPLAY_BATTERY_LOW)
        MOD_OLED_EnterState(OLED_DISPLAY_HOME);

    MOD_OLED_wakeUp();
}