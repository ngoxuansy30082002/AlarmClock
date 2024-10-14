#ifndef MOD_TIMER_H
#define MOD_TIMER_H

#include "define.h"

using namespace std;

typedef function<void(void)> TimerCallback;

typedef enum
{
    TIMER_ONCE,  // Timer runs once and is removed
    TIMER_REPEAT // Timer repeats after each interval
} TimerMode;

typedef struct
{
    uint32_t remainingTime; // Time left until the callback is called
    uint32_t interval;      // Original time interval (for repeating timers)
    TimerCallback callback; // The function to call when the time expires
    TimerMode mode;         // Specifies if the timer is one-time or repeating
} TimerEntry;

typedef struct
{
    bool sleepFlag;
    vector<TimerEntry> timerEntries; // Dynamic array of timer entries
} mod_timer_data;

void MOD_TIMER_Init();
void MOD_TIMER_Task();
bool MOD_TIMER_HandlerRegister(uint32_t time, TimerCallback callback, TimerMode mode); // Register new timer

extern mod_timer_data modTimerDt;

#endif /* MOD_TIMER_H */
