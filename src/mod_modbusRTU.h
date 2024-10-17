#ifndef MOD_MODBUSRTU_H /* include guards */
#define MOD_MODBUSRTU_H
#include "define.h"

#define MBRTU_MAX_SLAVE_NUM 10
#define TEMP_SS_ADDR 1
#define TEMP_SS_REG_ADDR 0
#define HUM_SS_ADDR 2
#define HUM_SS_REG_ADDR 0

typedef struct
{
    uint16_t addrSlave;
    uint16_t addrReg;
    uint16_t value;
} mb_data_entry;
typedef struct
{
    mb_data_entry tempSensor;
    mb_data_entry humSensor;
} mod_mbRTU_data;

void MOD_MODBUSRTU_Init();
void MOD_MODBUSRTU_Task();
extern mod_mbRTU_data modMbRtuDt;

#endif /* MOD_MODBUSRTU_H */
