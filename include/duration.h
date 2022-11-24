#ifndef _DURATION_CLASS_H_
#define _DURATION_CLASS_H_

/*Class that logically is equivalent to if you wanted to record various times*/
class duration
{
    /*Private attributes that can not be accessed directly*/
private:
    /*attribute that stores an integer value for time passed in duration*/
    int time;
    /*attribute that stores a certain value that acts as an alarm, for when a certain time is reached*/
    int alarm;
    /*Attribute that stores whether or not we actuall have an alarm set*/
    bool alarmHasBeenSet;

    /*Public funtions and attributes, that can be used by user*/
public:
    /*Constructors*/
    duration();
    duration(int t);

    /*Destructor*/
    ~duration();

    /*Function that returns the time of a certain duration*/
    int getDuration();

    /*Functions that increment time by different values*/
    bool tick();
    bool tick(int dt);

    /*Function that gives value to alarm attribute and changes value of alarmHasBeenSet*/
    void setAlarm(int t);

    /*Function that checks if time has surpassed the value of alarm*/
    bool checkAndUpdateAlarm();

    // For testing purposes for checkAndUpdateAlarm
    /*Function that returns the alarm set for a certain duration*/
    int getAlarm();
};

#endif