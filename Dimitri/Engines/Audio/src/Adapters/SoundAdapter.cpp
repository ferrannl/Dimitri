#include "SoundAdapter.h"

void Adapters::SoundAdapter::play()
{
	Mix_PlayChannel(_channel, _sound, 0);
}

void Adapters::SoundAdapter::resume()
{
	if (Mix_Paused(_channel)) {
		Mix_Resume(_channel);
	}
}

void Adapters::SoundAdapter::pause()
{
	if (Mix_Playing(_channel)) {
		Mix_Pause(_channel);
	}
}

void Adapters::SoundAdapter::stop()
{
	Mix_HaltChannel(_channel);
}