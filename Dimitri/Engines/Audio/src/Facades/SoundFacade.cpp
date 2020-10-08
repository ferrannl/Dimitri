#include "SoundFacade.h"

void Facades::SoundFacade::play()
{
	Mix_PlayChannel(_channel, _sound, 0);
}

void Facades::SoundFacade::resume()
{
	if (Mix_Paused(_channel)) {
		Mix_Resume(_channel);
	}
}

void Facades::SoundFacade::pause()
{
	if (Mix_Playing(_channel)) {
		Mix_Pause(_channel);
	}
}

void Facades::SoundFacade::stop()
{
	Mix_HaltChannel(_channel);
}