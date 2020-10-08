#include "SoundFacade.h"

Facades::SoundFacade::SoundFacade(const char* path, int channel) : Interfaces::IAudioFacade(path), _channel{ channel }  {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		//printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		//printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	_sound = Mix_LoadWAV(path);
	if (_sound == NULL)
	{
		//printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Facades::SoundFacade::play() const
{
	Mix_PlayChannel(_channel, _sound, 0);
}

void Facades::SoundFacade::resume() const
{
	if (Mix_Paused(_channel)) {
		Mix_Resume(_channel);
	}
}

void Facades::SoundFacade::pause() const
{
	if (Mix_Playing(_channel)) {
		Mix_Pause(_channel);
	}
}

void Facades::SoundFacade::stop() const
{
	Mix_HaltChannel(_channel);
}

Facades::SoundFacade::~SoundFacade()
{
	delete _sound;
}
