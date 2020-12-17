#include "Audio.h"
using namespace Audio;

Models::Audio::Audio(const std::string& name, std::unique_ptr<Interfaces::IAudioFacade> audio_facade) :
	_name{ name }, _audio_facade{ std::move(audio_facade) }{}

const std::string Models::Audio::get_name() const
{
	return _name;
}

const Interfaces::IAudioFacade* Models::Audio::get_audio_facade() const
{
	return _audio_facade.get();
}
