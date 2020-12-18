#pragma once
#include <string>
#include "../Interfaces/IAudioFacade.h"
#include <memory>

/**
* \namespace Audio
* \brief Namespace for the audio engine
*/
namespace Audio {
	/**
	* \namespace Audio::Models
	* \brief Namespace for the models in the audio engine
	*/
	namespace Models {
		/**
		* \class Audio
		* \brief Class contains the methods to play audio files
		*/
		class Audio {
		private:
			/**
			* \brief The name of the Audio
			*/
			const std::string _name;

			/**
			* \brief The Audio Facade containing all methods and references to play audio
			*/
			const std::unique_ptr<Interfaces::IAudioFacade> _audio_facade;
		public:
			Audio(const std::string& name, std::unique_ptr<Interfaces::IAudioFacade> audio_facade);

			/**
			* \brief Returns the name of the Audio
			*/
			const std::string get_name() const;

			/**
			* \brief Returns the %Audio Facade
			*/
			const std::unique_ptr<Interfaces::IAudioFacade>& get_audio_facade() const;
		};
	}
}