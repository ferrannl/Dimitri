#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Interfaces/IAudioFacade.h"

namespace Facades {
	class __declspec(dllexport) MusicFacade : public Interfaces::IAudioFacade {
	private:
		Mix_Music* _music = NULL;
	public:
		MusicFacade(const char* path) : Interfaces::IAudioFacade(path) {
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
		void play();
		void resume();
		void pause();
		void stop();
	};
}