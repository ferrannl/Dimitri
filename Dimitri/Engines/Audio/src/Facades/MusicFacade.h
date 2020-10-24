#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else 
#define AUDIO_API __declspec(dllimport)
#endif
#else
#define AUDIO_API
#endif

namespace Facades {
	class AUDIO_API MusicFacade : public Interfaces::IAudioFacade {
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