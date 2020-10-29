#include "MainController.h"
using namespace Game;
Controllers::MainController::MainController()
{
	_window_controller = std::make_unique<WindowController>();
	_input_controller = std::make_shared<Controllers::InputController>();
	_audio_controller = std::make_shared<Controllers::AudioController>();
	load_music_for_level("level1","/assets/audio/beat.wav");
	load_music_for_level("level2","/assets/audio/billy.wav");
	_input_controller->poll_events();
}

void Controllers::MainController::load_music_for_level(const std::string audio_name, const std::string path)
{
	_audio_controller->add_music(audio_name, path);
	_audio_controller->play_audio(audio_name);
	sleep_for(5000ms);
	_audio_controller->stop_audio(audio_name);
}
