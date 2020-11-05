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
		* Class containing methods and references for using SDL_Mixer for sound
		*/
		class AUDIO_API SoundFacade : public Interfaces::IAudioFacade {
		private:
			/**
			* The sound model used by the SDL_Mixer methods
			*/
			std::unique_ptr<Mix_Chunk, decltype (&Mix_FreeChunk)> _sound;

			/**
			* The channel of the current sound file
			*/
			const int _channel;
		public:
			SoundFacade(const std::string path, int channel);

			/**
			* Plays the sound file using the SDL_Mixer methods
			*/
			void play() const;

			/**
			* Resumes the sound file using the SDL_Mixer methods
			*/
			void resume() const;

			/**
			* Pauses the sound file using the SDL_Mixer methods
			*/
			void pause() const;

			/**
			* Stops the sound file using the SDL_Mixer methods
			*/
			void stop() const;
		};
	}
}