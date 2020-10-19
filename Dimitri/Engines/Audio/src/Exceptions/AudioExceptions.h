#pragma once
#include <string>
#include <exception>
namespace Audio {
	namespace Exceptions {
		struct AudioNameNotUnique : public std::exception {
			const char* get() const throw () {
				return "Audio is not added, the name of the audio is not unique";
			}
		};

		struct AudioNotFound : public std::exception {
			const char* get() const throw () {
				return "Audio not found";
			}
		};

		struct SDLAudioInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize SDL";
			}
		};

		struct SDLMixerInitFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot initialize SDL Mixer";
			}
		};

		struct LoadAudioFailed : public std::exception {
			const char* get() const throw () {
				return "Cannot load audio";
			}
		};

	}
}