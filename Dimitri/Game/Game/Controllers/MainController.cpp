#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_unique<WindowController>();
	_input_controller = std::make_shared<Controllers::InputController>();
	_audio_controller = std::make_shared<Controllers::AudioController>();
	loadLevel("level1","/assets/audio/beat.wav");
	loadLevel("level2","/assets/audio/billy.wav");
	_input_controller->poll_events();
}

void Controllers::MainController::loadLevel(const std::string audio_name, const std::string path)
{
	_audio_controller->add_music(audio_name, path);
	_audio_controller->play_audio(audio_name);
	SDL_Delay(5000);
	_audio_controller->stop_audio(audio_name);
}
