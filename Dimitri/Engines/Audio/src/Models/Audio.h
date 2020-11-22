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
		class AUDIO_API Audio {
		private:
			/**
			* \brief The name of the Audio
			*/
			const std::string _name;

			/**
			* \brief The Audio Facade containing all methods and references to play audio
			*/
			const std::shared_ptr<Interfaces::IAudioFacade> _audio_facade;
		public:
			Audio(const std::string name, std::shared_ptr<Interfaces::IAudioFacade> audio_facade);

			/**
			* \brief Returns the name of the Audio
			*/
			std::string get_name() const;

			/**
			* \brief Returns the %Audio Facade
			*/
			std::shared_ptr<Interfaces::IAudioFacade> get_audio_facade() const;
		};
	}
}