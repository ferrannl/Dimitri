#include "AudioController.h"

Models::Audio* Controllers::AudioController::get_audio_by_name(std::string* name)
{
	for (std::vector<Models::Audio*> ::iterator it = _audios->begin(); it != _audios->end(); it++) {
		auto temp = name->compare(*(*it)->get_name());
		if (name->compare(*(*it)->get_name()) == 0) {
			return (*it);
		}
	}

	return nullptr;
}

Controllers::AudioController::AudioController()
{
	_audios = new std::vector<Models::Audio*>();
	_channel_counter = 0;
}

void Controllers::AudioController::add_sound(std::string* name, const char* path)
{
	_audios->push_back(new Models::Audio(name, new Facades::SoundFacade(path, _channel_counter)));
	_channel_counter++;
}

void Controllers::AudioController::add_music(std::string* name, const char* path)
{
	_audios->push_back(new Models::Audio(name, new Facades::MusicFacade(path)));
}

void Controllers::AudioController::play_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_facade()->play();
}

void Controllers::AudioController::resume_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_facade()->resume();

}

void Controllers::AudioController::pause_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_facade()->pause();
}

void Controllers::AudioController::stop_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_facade()->stop();
}