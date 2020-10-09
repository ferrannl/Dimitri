#include "AudioController.h"

std::shared_ptr<Models::Audio> Controllers::AudioController::get_audio_by_name(const std::string name) const
{
	for (std::shared_ptr<Models::Audio> audio : *_audios) {
		if (name.compare(audio->get_name()) == 0) {
			return (audio);
		}
	}
	return nullptr;
}

Controllers::AudioController::AudioController()
{
	_audios = std::make_unique<std::vector<std::shared_ptr<Models::Audio>>>();
	_channel_counter = 0;
}

void Controllers::AudioController::add_sound(const std::string name, const std::string path)
{
	_audios->push_back(std::make_shared<Models::Audio>(name, std::make_shared<Facades::SoundFacade>(path, _channel_counter)));
	_channel_counter++;
}

void Controllers::AudioController::add_music(const std::string name, const std::string path)
{
	_audios->push_back(std::make_shared<Models::Audio>(name, std::make_shared<Facades::MusicFacade>(path)));
}

void Controllers::AudioController::play_audio(const std::string name) const
{
	get_audio_by_name(name)->get_audio_facade()->play();
}

void Controllers::AudioController::resume_audio(const std::string name) const
{
	get_audio_by_name(name)->get_audio_facade()->resume();
}

void Controllers::AudioController::pause_audio(const std::string name) const
{
	get_audio_by_name(name)->get_audio_facade()->pause();
}

void Controllers::AudioController::stop_audio(const std::string name) const
{
	get_audio_by_name(name)->get_audio_facade()->stop();
}
