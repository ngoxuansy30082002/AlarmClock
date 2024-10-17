#include "mod_modbusRTU.h"

mod_mbRTU_data modMbRtuDt;
ModbusMaster node;

static inline void Tx_Tris()
{
    digitalWrite(PIN_MBRTU_TRIS, 1);
}

static inline void Rx_Tris()
{
    digitalWrite(PIN_MBRTU_TRIS, 0);
}

void MOD_MODBUSRTU_Init()
{
    Serial.begin(9600);
    pinMode(PIN_MBRTU_TRIS, OUTPUT);
    node.preTransmission(Tx_Tris); // Callback for configuring RS-485 Transreceiver correctly
    node.postTransmission(Rx_Tris);
    modMbRtuDt.tempSensor.addrReg = TEMP_SS_REG_ADDR;
    modMbRtuDt.tempSensor.addrSlave = TEMP_SS_ADDR;
    modMbRtuDt.humSensor.addrReg = HUM_SS_REG_ADDR;
    modMbRtuDt.humSensor.addrSlave = HUM_SS_ADDR;
};
void MOD_MODBUSRTU_Task()
{
    uint8_t result;

    node.begin(modMbRtuDt.tempSensor.addrSlave, Serial);

    result = node.readHoldingRegisters(modMbRtuDt.tempSensor.addrReg, 1);

    if (result == node.ku8MBSuccess)
    {
        modMbRtuDt.tempSensor.value = node.getResponseBuffer(0);
        MOD_OLED_wakeUp();
    }

    node.begin(modMbRtuDt.humSensor.addrSlave, Serial);

    result = node.readHoldingRegisters(modMbRtuDt.humSensor.addrReg, 1);

    if (result == node.ku8MBSuccess)
    {
        modMbRtuDt.humSensor.value = node.getResponseBuffer(0);
        MOD_OLED_wakeUp();
    }
};