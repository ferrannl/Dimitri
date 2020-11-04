#pragma once
#include <string>
#include "../Interfaces/IAudioFacade.h"
#include <memory>

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
	* Namespace for the models
	*/
	namespace Models {
		/**
		* The audio model that can be used by the game to play audio files
		*/
		class AUDIO_API Audio {
		private:
			/**
			* The name of the audio
			*/
			const std::string _name;

			/**
			* The audio facade containing all methods and references to play audio with SDL_Mixer
			*/
			const std::shared_ptr<Interfaces::IAudioFacade> _audio_facade;
		public:
			Audio(const std::string name, std::shared_ptr < Interfaces::IAudioFacade> audio_facade);

			/**
			* Returns the name of the model
			*/
			std::string get_name() const;

			/**
			* Returns the audio facade
			*/
			std::shared_ptr<Interfaces::IAudioFacade> get_audio_facade() const;
		};
	}
}