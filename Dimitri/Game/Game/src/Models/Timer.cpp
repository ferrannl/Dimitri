#include "Timer.h"

Game::Models::Timer::Timer()
{
	_start_ticks = 0;
	_started = false;
}

void Game::Models::Timer::start()
{
	_started = true;
    _paused = false;    

	_start_ticks = SDL_GetTicks();
    _pause_ticks = 0;   

}

void Game::Models::Timer::stop()
{
	_started = false;
	_paused = false;
}

uint32_t Game::Models::Timer::getTicks()
{
    //The actual timer time
    Uint32 time = 0;

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
            time = SDL_GetTicks() - _start_ticks;
        }
    }

    return time;
}

bool Game::Models::Timer::is_started()
{
    return mStarted;
}
