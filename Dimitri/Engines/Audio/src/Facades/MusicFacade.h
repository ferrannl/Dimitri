#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Interfaces/IAudioFacade.h"

namespace Facades {
	class __declspec(dllexport) MusicFacade : public Interfaces::IAudioFacade {
	private:
		Mix_Music* _music = NULL;
	public:
		MusicFacade(const char* path);
		void play();
		void resume();
		void pause();
		void stop();
	};
}