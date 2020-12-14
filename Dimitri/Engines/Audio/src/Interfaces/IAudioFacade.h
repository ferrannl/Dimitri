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
		* \class IAudioFacade
		* \brief Class contains the methods to interact with an audio file
		*/
		class AUDIO_API IAudioFacade {
		protected:
			/**
			* \brief Path of the audio file
			*/
			const std::string _path;
		public:
			IAudioFacade(const std::string path);

			/**
			* \brief Plays audio file
			*/
			virtual void play() const = 0;

			/**
			* \brief Resumes audio file
			*/
			virtual void resume() const = 0;

			/**
			* \brief Pauses audio file
			*/
			virtual void pause() const = 0;

			/**
			* \brief Stops audio file
			*/
			virtual void stop() const = 0;

			/**
			* \brief Checks if the audio file is playing
			*/
			virtual bool is_playing() const = 0;
		};
	}
}