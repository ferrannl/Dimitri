#include "MusicFacade.h"

Facades::MusicFacade::MusicFacade(const char* path) : Interfaces::IAudioFacade(path) {
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
	_music = Mix_LoadMUS(_path);
	if (_music == NULL)
	{
		//printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Facades::MusicFacade::play() const
{
	Mix_PlayMusic(_music, -1);
}

void Facades::MusicFacade::resume() const
{
	if (Mix_PausedMusic) {
		Mix_ResumeMusic();
	}
}

void Facades::MusicFacade::pause() const
{
	if (Mix_PlayingMusic) {
		Mix_PauseMusic();
	}
}

void Facades::MusicFacade::stop() const
{
	Mix_HaltMusic();
}

Facades::MusicFacade::~MusicFacade()
{
	delete _music;
}
