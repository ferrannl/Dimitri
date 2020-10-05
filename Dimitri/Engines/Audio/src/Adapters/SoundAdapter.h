#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Interfaces/IAudioAdapter.h"

namespace Adapters {
	class __declspec(dllexport) SoundAdapter : public Interfaces::IAudioAdapter{
	private:
        
	public:
        SoundAdapter(const char* path) : Interfaces::IAudioAdapter(path) {
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
		}
        void play();
        void resume();
        void pause();
        void stop();
	};
}