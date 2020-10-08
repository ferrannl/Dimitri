#include "Audio.h"

Models::Audio::Audio(const std::string name, std::shared_ptr <Interfaces::IAudioFacade> audio_facade) : _name{ name }, _audio_facade{ audio_facade }{}

std::string Models::Audio::get_name() const
{
	return _name;
}

std::shared_ptr <Interfaces::IAudioFacade> Models::Audio::get_audio_facade() const
{
	return _audio_facade;
}

Models::Audio::~Audio() {}
