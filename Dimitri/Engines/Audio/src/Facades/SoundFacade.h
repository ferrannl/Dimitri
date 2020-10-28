#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"
#include <SDL.h>
#include <SDL_mixer.h>

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else 
#define AUDIO_API __declspec(dllimport)
#endif
#else
#define AUDIO_API
#endif

//void Mix_FreeChunk(Mix_Chunk* chunk);
struct Mix_Chunk;

namespace Audio {
	namespace Facades {
		class AUDIO_API SoundFacade : public Interfaces::IAudioFacade {
		private:
			std::unique_ptr<Mix_Chunk, decltype (&Mix_FreeChunk)> _sound;
			const int _channel;
		public:
			SoundFacade(const std::string path, int channel);
			void play() const;
			void resume() const;
			void pause() const;
			void stop() const;
		};
	}
}