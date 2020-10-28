#include "AudioController.h"
#include "../../Utility/src/Helpers/BasePathHelper.h"
using namespace Game;

Controllers::AudioController::AudioController() 
{
	_audio_controller = std::make_unique<Audio::Controllers::AudioController>();
}

void Controllers::AudioController::add_music()
{

}

void Controllers::AudioController::play_music()
{
	const std::string name = std::string("music");
	_audio_controller->add_music(name, Utility::Helpers::get_base_path() + std::string{ "/assets/audio/beat.wav" }.c_str());
	_audio_controller->play_audio(name);
}

void Controllers::AudioController::pause_music()
{

}
