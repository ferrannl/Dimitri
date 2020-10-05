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

void Controllers::AudioController::add_sound(std::string* name, const char* path)
{
	_audios->push_back(new Models::Audio(name, new Adapters::SoundAdapter(path)));
}

void Controllers::AudioController::add_music(std::string* name, const char* path)
{
	_audios->push_back(new Models::Audio(name, new Adapters::MusicAdapter(path)));
}

void Controllers::AudioController::play_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_adapter()->play();
}

void Controllers::AudioController::resume_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_adapter()->resume();

}

void Controllers::AudioController::pause_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_adapter()->pause();
}

void Controllers::AudioController::stop_audio(std::string* name)
{
	Models::Audio* audio = get_audio_by_name(name);
	audio->get_audio_adapter()->stop();
}