#include "Timer.h"

Game::Models::Timer::Timer(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, const std::shared_ptr<Controllers::WindowController> window_controller) : Game::Models::IObject(x, y, z, height, width, state)
{
    _window_controller = window_controller;
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

//std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Models::Timer::get_textures()
//{
//    /*_textures.clear();
//    std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
//    _textures.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(getTicks()), color, 600, 600, 100, 200, 200, 0, path, true));
//    return _textures;*/
//}

void Game::Models::Timer::initialize_textures()
{
    std::tuple<int, int> camera_pos = _window_controller->get_graphics_controller().get()->get_camera_pos();

    int window_width_camera = _window_controller->get_graphics_controller().get()->get_window().get()->get_width() + std::get<0>(camera_pos);
    int window_width = _window_controller->get_graphics_controller().get()->get_window().get()->get_width();
    int window_height_camera = _window_controller->get_graphics_controller().get()->get_window().get()->get_height() + std::get<1>(camera_pos);
    Graphics::Models::Color color = { 255, 255, 255 };
    std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
    add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Text>(std::to_string(getTicks() / 1000.f), color, window_width_camera - (window_width / 2) - 54, window_height_camera - 60, 100, 54, 100, 0, path, true));

}
