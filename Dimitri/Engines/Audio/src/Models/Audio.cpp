#include "Audio.h"

Models::Audio::Audio(std::string* name, Interfaces::IAudioFacade* audio_facade) : _name{ name }, _audio_facade{ audio_facade }{}

std::shared_ptr<std::string> Models::Audio::get_name()
{
	return _name;
}

std::shared_ptr <Interfaces::IAudioFacade> Models::Audio::get_audio_facade()
{
	return _audio_facade;
}

Models::Audio::~Audio()
{
	_name = nullptr;
	_audio_facade = nullptr;
}
