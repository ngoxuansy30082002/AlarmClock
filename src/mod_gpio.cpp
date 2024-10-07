#include "mod_gpio.h"

volatile mod_gpio_data modGpioDt;

#define DEBOUNCE_DELAY 150 // Thời gian debounce (ms)

// Khai báo biến lưu thời gian lần nhấn cuối
volatile unsigned long lastInterruptTimeMode = 0;
volatile unsigned long lastInterruptTimeUp = 0;
volatile unsigned long lastInterruptTimeDown = 0;
volatile unsigned long lastInterruptTimeNext = 0;

void IRAM_ATTR _handleInterruptBtnMode()
{
    unsigned long currentTime = millis();
    if (currentTime - lastInterruptTimeMode > DEBOUNCE_DELAY)
    {
        switch (modGpioDt.mode)
        {
        case MODE_NORMAL:
            modGpioDt.mode = MODE_MENU;
            break;
        case MODE_MENU:
            modGpioDt.mode = MODE_SET_TIME;
            break;
        case MODE_SET_TIME:
            modGpioDt.mode = MODE_NORMAL;
            break;
        default:
            break;
        }
        lastInterruptTimeMode = currentTime; // Cập nhật thời gian lần nhấn nút
    }
}

void IRAM_ATTR _handleInterruptBtnUp()
{
    unsigned long currentTime = millis();
    if (currentTime - lastInterruptTimeUp > DEBOUNCE_DELAY)
    {
        if (modGpioDt.mode == MODE_SET_TIME)
        {
            if (modGpioDt.timeType == MINUTE)
            {
                modGpioDt.minute++;
                if (modGpioDt.minute >= 60)
                {
                    modGpioDt.minute = 0;
                }
            }
            else
            {
                modGpioDt.hour++;
                if (modGpioDt.hour >= 24)
                {
                    modGpioDt.hour = 0;
                }
            }
        }
        lastInterruptTimeUp = currentTime; // Cập nhật thời gian lần nhấn nút
    }
}

void IRAM_ATTR _handleInterruptBtnDown()
{
    unsigned long currentTime = millis();
    if (currentTime - lastInterruptTimeDown > DEBOUNCE_DELAY)
    {
        if (modGpioDt.mode == MODE_SET_TIME)
        {
            if (modGpioDt.timeType == MINUTE)
            {
                modGpioDt.minute--;
                if (modGpioDt.minute < 0)
                {
                    modGpioDt.minute = 59;
                }
            }
            else
            {
                modGpioDt.hour--;
                if (modGpioDt.hour < 0)
                {
                    modGpioDt.hour = 23;
                }
            }
        }
        lastInterruptTimeDown = currentTime; // Cập nhật thời gian lần nhấn nút
    }
}

void IRAM_ATTR _handleInterruptBtnNext()
{
    unsigned long currentTime = millis();
    if (currentTime - lastInterruptTimeNext > DEBOUNCE_DELAY)
    {
        modGpioDt.timeType = (time_type_t)(modGpioDt.timeType ^ 1);
        lastInterruptTimeNext = currentTime; // Cập nhật thời gian lần nhấn nút
    }
}

void MOD_GPIO_Init()
{
    pinMode(PIN_BTN_MODE, INPUT_PULLUP);
    pinMode(PIN_BTN_UP, INPUT_PULLUP);
    pinMode(PIN_BTN_DOWN, INPUT_PULLUP);
    pinMode(PIN_BTN_NEXT, INPUT_PULLUP);

    attachInterrupt(PIN_BTN_MODE, _handleInterruptBtnMode, FALLING);
    attachInterrupt(PIN_BTN_UP, _handleInterruptBtnUp, FALLING);
    attachInterrupt(PIN_BTN_DOWN, _handleInterruptBtnDown, FALLING);
    attachInterrupt(PIN_BTN_NEXT, _handleInterruptBtnNext, FALLING);

    modGpioDt.mode = MODE_NORMAL;
    // pinMode(LED_PIN, OUTPUT);
}
void MOD_GPIO_Task()
{
    char str[100];
    sprintf(str, "mode: %u, timeType: %u, hour: %u, minute: %u, ", modGpioDt.mode, modGpioDt.timeType, modGpioDt.hour, modGpioDt.minute);
    Serial.println(str);
}