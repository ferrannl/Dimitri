#include "Audio.h"

std::string* Models::Audio::get_name()
{
	return _name;
}

Interfaces::IAudioAdapter* Models::Audio::get_audio_adapter()
{
	return _audio_adapter;
}
