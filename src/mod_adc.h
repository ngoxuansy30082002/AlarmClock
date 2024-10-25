#ifndef MOD_ADC_H
#define MOD_ADC_H

#include "define.h"

typedef struct
{
    int percentBat;
} mod_adc_data;

void MOD_ADC_Init();
void MOD_ADC_Task();

extern mod_adc_data modAdc_Dt;

#endif
