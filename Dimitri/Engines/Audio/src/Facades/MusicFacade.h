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

/**
* Namespace for the audio engine
*/
namespace Audio {
	/**
	* Namespace for the facades
	*/
	namespace Facades {
		/**
		* Class containing methods and references for using SDL_Mixer for music
		*/
		class AUDIO_API MusicFacade : public Interfaces::IAudioFacade {
		private:
			/**
			* The music model used by the SDL_Mixer methods
			*/
			std::unique_ptr<Mix_Music, decltype (&Mix_FreeMusic)> _music;
		public:
			MusicFacade(const std::string path);

			/**
			* Plays the music file using the SDL_Mixer methods
			*/
			void play() const;

			/**
			* Resumes the music file using the SDL_Mixer methods
			*/
			void resume() const;

			/**
			* Pauses the music file using the SDL_Mixer methods
			*/
			void pause() const;

			/**
			* Stops the music file using the SDL_Mixer methods
			*/
			void stop() const;
		};
	}
}