#include "AudioController.h"
using namespace Game;
Controllers::AudioController::AudioController()
{
	_audio_controller = std::make_unique<Audio::Controllers::AudioController>();
}

void Controllers::AudioController::add_music(const std::string name, const std::string song_path)
{
	_audio_controller->add_music(name, Utility::Helpers::get_base_path() + song_path.c_str());
}

void Controllers::AudioController::add_sound(const std::string name, const std::string song_path)
{
	_audio_controller->add_sound(name, Utility::Helpers::get_base_path() + song_path.c_str());
}

void Controllers::AudioController::play_audio(const std::string name)
{
	_audio_controller->play_audio(name);
}

void Controllers::AudioController::pause_audio(const std::string name)
{
	_audio_controller->pause_audio(name);
}

void Controllers::AudioController::stop_audio(const std::string name)
{
	_audio_controller->stop_audio(name);
}

void Controllers::AudioController::resume_audio(const std::string name)
{
	_audio_controller->resume_audio(name);
}
