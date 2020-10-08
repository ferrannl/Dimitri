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
		void play() const;
		void resume() const;
		void pause() const;
		void stop() const;

		// forbid copying and moving
		MusicFacade(const MusicFacade& music_facade) = delete;
		MusicFacade& operator=(const MusicFacade& music_facade) = delete;
		MusicFacade(MusicFacade&& music_facade) = delete;
		MusicFacade& operator=(MusicFacade&& music_facade) = delete;

		~MusicFacade();
	};
}