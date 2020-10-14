#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"

namespace Facades {
	class __declspec(dllexport) MusicFacade : public Interfaces::IAudioFacade {
	private:
		std::unique_ptr<Mix_Music, decltype (&Mix_FreeMusic)> _music;
	public:
		MusicFacade(const std::string path);
		void play() const;
		void resume() const;
		void pause() const;
		void stop() const;
	};
}