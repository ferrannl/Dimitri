#pragma once
#include <string>
#include <memory>
#include "../Exceptions/AudioExceptions.h"
#include <iostream>
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

/**
* \namespace Audio
* \brief Namespace for the audio engine
*/
namespace Audio {
	/**
	* \namespace Audio::Interfaces
	* \brief Namespace for the interfaces in the audio engine
	*/
	namespace Interfaces {
		/**
		* Containing all the necesary methods an attributes that every sound/music facade should have
		*/
		class AUDIO_API IAudioFacade {
		protected:
			/**
			* Path for locating the sound file
			*/
			const std::string _path;
		public:
			IAudioFacade(const std::string path);

			/**
			* Plays audio
			*/
			virtual void play() const = 0;

			/**
			* Resumes audio
			*/
			virtual void resume() const = 0;

			/**
			* Pauses audio
			*/
			virtual void pause() const = 0;

			/**
			* Stops audio
			*/
			virtual void stop() const = 0;
		};
	}
}