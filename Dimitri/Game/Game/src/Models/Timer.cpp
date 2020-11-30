#include "Timer.h"

Game::Models::Timer::Timer(const std::shared_ptr<Controllers::WindowController> window_controller) : _window_controller(window_controller)
{
	_start_ticks = 0;
    _pause_ticks = 0;
	_started = false;
    _paused = false;
}

void Game::Models::Timer::start()
{
	_started = true;
    _paused = false;    

    _start_ticks = _window_controller->get_graphics_controller()->get_window()->get_facade()->get_ticks();
    _pause_ticks = 0;   

}

void Game::Models::Timer::stop()
{
	_started = false;
	_paused = false;

    _start_ticks = 0;
    _pause_ticks = 0;
}

void Game::Models::Timer::pause()
{
    //If the timer is running and isn't already paused
    if (_started && !_paused)
    {
        //Pause the timer
        _paused = true;

        //Calculate the paused ticks
        _pause_ticks = _window_controller->get_graphics_controller()->get_window()->get_facade()->get_ticks() - _start_ticks;
        _start_ticks = 0;
    }
}

void Game::Models::Timer::unpause()
{
    //If the timer is running and paused
    if (_started && _paused)
    {
        //Unpause the timer
        _paused = false;

        //Reset the starting ticks
        _start_ticks = _window_controller->get_graphics_controller()->get_window()->get_facade()->get_ticks() - _pause_ticks;

        //Reset the paused ticks
        _pause_ticks = 0;
    }
}

Uint32 Game::Models::Timer::getTicks()
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
            time = _window_controller->get_graphics_controller()->get_window()->get_facade()->get_ticks() - _start_ticks;
        }
    }

    return time;
}

bool Game::Models::Timer::is_started()
{
    return _started;
}

bool Game::Models::Timer::is_paused()
{
    //Timer is running and paused
    return _paused && _started;
}

Uint32 Game::Models::Timer::get_start_ticks() {
    return _start_ticks;
}
