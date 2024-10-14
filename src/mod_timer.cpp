#include "mod_timer.h"

mod_timer_data modTimerDt;
hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer()
{
    portENTER_CRITICAL_ISR(&timerMux);
    modTimerDt.sleepFlag = false;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void MOD_TIMER_Init(uint32_t timerVal)
{
    modTimerDt.timerVal = timerVal;
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, timerVal * 1000, true); // 200ms interval
    timerAlarmEnable(timer);
    modTimerDt.sleepFlag = true;
    modTimerDt.timerEntries.clear(); // Initialize an empty timer entry list
}

void MOD_TIMER_Task()
{
    if (modTimerDt.sleepFlag)
        return;

    portENTER_CRITICAL(&timerMux);
    for (auto it = modTimerDt.timerEntries.begin(); it != modTimerDt.timerEntries.end();)
    {
        it->remainingTime -= modTimerDt.timerVal;
        if (it->remainingTime == 0)
        {
            it->callback();
            if (it->mode == TIMER_ONCE)
                it = modTimerDt.timerEntries.erase(it);
            else if (it->mode == TIMER_REPEAT)
            {
                it->remainingTime = it->interval;
                ++it;
            }
        }
        else
            ++it;
    }
    modTimerDt.sleepFlag = true;
    portEXIT_CRITICAL(&timerMux);
}

// Register a new timer callback
bool MOD_TIMER_HandlerRegister(uint32_t time, TimerCallback callback, TimerMode mode)
{
    if (time % modTimerDt.timerVal != 0)
        return false;

    portENTER_CRITICAL(&timerMux);
    TimerEntry entry = {time, time, callback, mode};
    modTimerDt.timerEntries.push_back(entry); // Add the new timer entry
    portEXIT_CRITICAL(&timerMux);
    return true;
}
