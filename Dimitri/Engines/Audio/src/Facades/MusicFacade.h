#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"
#include <functional>

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else 
#define AUDIO_API __declspec(dllimport)
#endif
#else
#define AUDIO_API
#endif
//void Mix_FreeMusic(Mix_Music* music);
typedef struct _Mix_Music Mix_Music;

namespace Audio {
	namespace Facades {
		/*struct Deleter {
			void operator() (Mix_Music* music) const { Mix_FreeMusic(music); }
		};*/
		using x = std::function<void(Mix_Music*)>;
		//extern x del;
		class AUDIO_API MusicFacade : public Interfaces::IAudioFacade {
		private:
			std::unique_ptr<Mix_Music, void(*)(Mix_Music*)> _music;
		public:
			MusicFacade(const std::string path);
			void play() const;
			void resume() const;
			void pause() const;
			void stop() const;
		};
	}
}