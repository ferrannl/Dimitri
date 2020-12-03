#include "Timer.h"



Utility::Time::Timer::Timer()
{
    _current_ticks = 0;
    _start_ticks = 0;
    _pause_ticks = 0;
    _started = false;
    _paused = false;
}

void Utility::Time::Timer::start()
{
    _started = true;
    _paused = false;

    _start_ticks = _current_ticks;
    _pause_ticks = 0;

}

void Utility::Time::Timer::stop()
{
    _started = false;
    _paused = false;

    _start_ticks = 0;
    _pause_ticks = 0;
}

void Utility::Time::Timer::pause()
{
    //If the timer is running and isn't already paused
    if (_started && !_paused)
    {
        //Pause the timer
        _paused = true;

        //Calculate the paused ticks
        _pause_ticks = _current_ticks - _start_ticks;
        _start_ticks = 0;
    }
}

void Utility::Time::Timer::unpause()
{
    //If the timer is running and paused
    if (_started && _paused)
    {
        //Unpause the timer
        _paused = false;

        //Reset the starting ticks
        _start_ticks = _current_ticks - _pause_ticks;

        //Reset the paused ticks
        _pause_ticks = 0;
    }
}

uint32_t Utility::Time::Timer::getTicks()
{
    //The actual timer time
    uint32_t time = 0;

    //If the timer is running
    if (_started)
    {
        //If the timer is paused
        if (_paused)
        {
            //Return the number of ticks when the timer was paused
            time = _pause_ticks;
        }
        else
        {
            //Return the current time minus the start time
            time = _current_ticks - _start_ticks;
        }
    }

    return time;
}

void Utility::Time::Timer::set_current_ticks(uint32_t current_ticks)
{
    _current_ticks = current_ticks;
}

bool Utility::Time::Timer::is_started()
{
    return _started;
}

bool Utility::Time::Timer::is_paused()
{
    //Timer is running and paused
    return _paused && _started;
}
