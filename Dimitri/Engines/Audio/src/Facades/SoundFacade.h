#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include "../Interfaces/IAudioFacade.h"

namespace Facades {
	class __declspec(dllexport) SoundFacade : public Interfaces::IAudioFacade {
	private:
		Mix_Chunk* _sound = NULL;
		const int _channel;
	public:
		SoundFacade(const char* path, int channel);
		void play() const;
		void resume() const;
		void pause() const;
		void stop() const;

		// forbid copying and moving
		SoundFacade(const SoundFacade& sound_facade) = delete;
		SoundFacade& operator=(const SoundFacade& sound_facade) = delete;
		SoundFacade(SoundFacade&& sound_facade) = delete;
		SoundFacade& operator=(SoundFacade&& sound_facade) = delete;

		~SoundFacade();
	};
}