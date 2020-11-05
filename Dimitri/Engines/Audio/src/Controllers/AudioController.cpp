#include "AudioController.h"
using namespace Audio;

Controllers::AudioController::AudioController()
{
	_audios = std::vector<std::shared_ptr<Models::Audio>>();
	_channel_counter = 0;
}

std::shared_ptr<Models::Audio> Controllers::AudioController::get_audio_by_name(const std::string name) const
{
	for (std::shared_ptr<Models::Audio> audio : _audios) {
		if (name.compare(audio->get_name()) == 0) {
			return (audio);
		}
	}
	throw Exceptions::AudioNotFound();
}

void Controllers::AudioController::add_sound(const std::string name, const std::string path)
{
	try {
		if (!name_exists(name)) {
			try {
				_audios.push_back(std::make_shared<Models::Audio>(name, std::make_shared<Facades::SoundFacade>(path, _channel_counter)));
				_channel_counter++;
			}
			catch (Exceptions::LoadAudioFailed e) {
				std::cout << e.get() << ": " << name << std::endl;
			}
		}
		else {
			throw Exceptions::AudioNameNotUnique();
		}
	}
	catch (Exceptions::AudioNameNotUnique e) {
		std::cout << e.get() << std::endl;
	}
}

void Controllers::AudioController::add_music(const std::string name, const std::string path)
{
	try {
		if (!name_exists(name)) {
			try {
				_audios.push_back(std::make_shared<Models::Audio>(name, std::make_shared<Facades::MusicFacade>(path)));
			}
			catch (Exceptions::LoadAudioFailed e) {
				std::cout << e.get() << ": " << name << std::endl;
			}
		}
		else {
			throw Exceptions::AudioNameNotUnique();
		}
	}
	catch (Exceptions::AudioNameNotUnique e) {
		std::cout << e.get() << std::endl;
	}
}

bool Controllers::AudioController::name_exists(const std::string name)
{
	for (std::shared_ptr<Models::Audio> audio : _audios) {
		if (name.compare(audio->get_name()) == 0) {
			return true;
		}
	}
	return false;
}

void Controllers::AudioController::play_audio(const std::string name) const
{
	try {
		get_audio_by_name(name)->get_audio_facade()->play();
	}
	catch (Exceptions::AudioNotFound e) {
		std::cout << e.get() << ": " << name << std::endl;
	}
}

void Controllers::AudioController::resume_audio(const std::string name) const
{
	try {
		get_audio_by_name(name)->get_audio_facade()->resume();
	}
	catch (Exceptions::AudioNotFound e) {
		std::cout << e.get() << ": " << name << std::endl;
	}
}

void Controllers::AudioController::pause_audio(const std::string name) const
{
	try {
		get_audio_by_name(name)->get_audio_facade()->pause();
	}
	catch (Exceptions::AudioNotFound e) {
		std::cout << e.get() << ": " << name << std::endl;
	}
}

void Controllers::AudioController::stop_audio(const std::string name) const
{
	try {
		get_audio_by_name(name)->get_audio_facade()->stop();
	}
	catch (Exceptions::AudioNotFound e) {
		std::cout << e.get() << ": " << name << std::endl;
	}
}
