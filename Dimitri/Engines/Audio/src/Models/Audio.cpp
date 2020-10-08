#include "Audio.h"

std::string* Models::Audio::get_name()
{
	return _name;
}

Models::Audio::Audio(std::string* name, Interfaces::IAudioFacade* audio_facade) : _name{ name }, _audio_facade{ audio_facade }{}

Interfaces::IAudioFacade* Models::Audio::get_audio_facade()
{
	return _audio_facade;
}
