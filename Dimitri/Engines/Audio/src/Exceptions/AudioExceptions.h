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
		* \struct AudioNameNotUnique
		* \brief Exception thrown if an %Audio name is not unique
		*/
		struct AudioNameNotUnique : public std::exception {
			const char* get() const throw () {
				return "Audio is not added, the name of the audio is not unique";
			}
		};

		/**
		* \struct AudioNotFound
		* \brief Exception thrown if %Audio can not be found
		*/
		struct AudioNotFound : public std::exception {
			const char* get() const throw () {
				return "Audio not found";
			}
		};

		/**
		* \struct SDLAudioInitFailed
		* \brief Exception thrown if the SDL initialization fails
		*/
		struct SDLAudioInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize SDL";
			}
		};

		/**
		* \struct SDLMixerInitFailed
		* \brief Exception thrown if the SDL_mixer initialization fails
		*/
		struct SDLMixerInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize SDL Mixer";
			}
		};

		/**
		* \struct LoadAudioFailed
		* \brief Exception thrown if %Audio cannot be loaded
		*/
		struct LoadAudioFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot load audio";
			}
		};
	}
}