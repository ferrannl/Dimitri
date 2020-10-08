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
		SoundFacade(const char* path, int channel);
		void play();
		void resume();
		void pause();
		void stop();
	};
}