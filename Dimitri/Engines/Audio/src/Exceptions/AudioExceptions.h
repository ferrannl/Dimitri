#pragma once
#include <string>
#include <exception>

/**
* \namespace Audio
* \brief Namespace for the audio engine
*/
namespace Audio {
	/**
	* \namespace Audio::Exceptions
	* \brief Namespace for the exceptions in the audio engine
	*/
	namespace Exceptions {
		/**
		* Is thrown when an audio name is not unique
		*/
		struct AudioNameNotUnique : public std::exception {
			const char* get() const throw () {
				return "Audio is not added, the name of the audio is not unique";
			}
		};

		/**
		* Is thrown when an path is not valid
		*/
		struct AudioNotFound : public std::exception {
			const char* get() const throw () {
				return "Audio not found";
			}
		};

		/**
		* Is thrown when the SDL initialization fails
		*/
		struct SDLAudioInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize SDL";
			}
		};

		/**
		* Is thrown when the SDL_mixer initialization fails
		*/
		struct SDLMixerInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize SDL Mixer";
			}
		};

		/**
		* Is thrown when the audio file cannot be loaded
		*/
		struct LoadAudioFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot load audio";
			}
		};
	}
}