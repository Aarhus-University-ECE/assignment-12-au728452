#include "duration.h"
#include <stdio.h>
#include <assert.h>

/*Constructor with default values*/
duration::duration()
{
    time = 0;
    alarm = 0;
    alarmHasBeenSet = false;
}

/*Constructor with variable time attribute*/
duration::duration(int t)
{
    assert(t >= 0);

    time = t;
    alarm = 0;
    alarmHasBeenSet = false;
}

/*Function that will return the value of time for duration object*/
int duration ::getDuration()
{
    /*Pre-condition*/
    assert(time >= 0);

    return time;
}

/*Function that increments time attribute by 1
Updated to boolean function per assignment g
Updated to call chackAndUpdateAlarm function per
assignment i*/
bool duration ::tick()
{
    time++;

    return checkAndUpdateAlarm();
}

/*Function that increments time attribute by variable
dt value
Updated to boolean function per assignment g
Updated to call chackAndUpdateAlarm function per
assignment i*/
bool duration ::tick(int dt)
{
    assert(dt > 0);

    time += dt;

    return checkAndUpdateAlarm();
}

/*Function called by tick() and tick(int dt)
Checks if alarm should be reset, when tick
functions are called*/
bool duration ::checkAndUpdateAlarm()
{
    if (time > alarm)
    {
        alarm = 0;
        alarmHasBeenSet = false;
        return true;
    }
    else
    {
        return false;
    }
}

/*Function that gives alarm attribute a value t
and will update the alarmHasBeenSet attribute to true
if alarm is larger than the current time
Functionality updated to rule out previous time inputs
as per assignment h*/
void duration ::setAlarm(int t)
{
    assert(t > 0);

    alarm = t;

    assert(alarm > time);

    alarmHasBeenSet = true;

    return;
}

/*Function used to check if assignment i
was done correctly*/
int duration ::getAlarm()
{
    return alarm;
}

/*Destructor*/
duration::~duration() {}
