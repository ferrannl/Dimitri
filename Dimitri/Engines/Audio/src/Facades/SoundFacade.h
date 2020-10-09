#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Interfaces/IAudioFacade.h"

namespace Facades {
	class __declspec(dllexport) SoundFacade : public Interfaces::IAudioFacade {
	private:
		Mix_Chunk* _sound = NULL;
		int _channel;
	public:
		SoundFacade(const char* path, int channel) : Interfaces::IAudioFacade(path), _channel{ channel }  {
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
		void play();
		void resume();
		void pause();
		void stop();
	};
}