#pragma once
#include "../Models/Audio.h"
#include "../Facades/SoundFacade.h"
#include "../Facades/MusicFacade.h"
#include "../Exceptions/AudioExceptions.h"
#include <iostream>
#include <vector>
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
	* \namespace Audio::Controllers
	* \brief Namespace for the controllers in the audio engine
	*/
	namespace Controllers {
		/**
		* \class AudioController
		* \brief Class contains the methods to be able to use audio files
		*/
		class AUDIO_API AudioController {
		private:
			/**
			* \brief A list containing all Audios
			*/
			std::vector<std::shared_ptr<Models::Audio>> _audios;

			/**
			* \brief Returns an Audio by name
			*/
			const std::shared_ptr<Models::Audio> get_audio_by_name(const std::string& name) const;

			/**
			* \brief Contains the amount of channels that currently are being used
			*/
			int _channel_counter;

			/**
			* \brief Returns if the name for an Audio already exists in _audios
			*/
			bool name_exists(const std::string& name) const;
		public:
			AudioController();

			/**
			* \brief Adds audio file which represents a sound effect to _audios
			*/
			void add_sound(const std::string& name, const std::string& path, int volume);

			/**
			* \brief Adds audio file which represents a music to _audios
			*/
			void add_music(const std::string& name, const std::string& path, int volume);

			/**
			* \brief Plays Audio by the given name
			*/
			void play_audio(const std::string& name) const;

			/**
			* \brief Resumes Audio by the given name
			*/
			void resume_audio(const std::string& name) const;

			/**
			* \brief Pauses Audio by the given name
			*/
			void pause_audio(const std::string& name) const;

			/**
			* \brief Stops Audio by the given name
			*/
			void stop_audio(const std::string& name) const;

			/**
			* \brief Controls the volumeo of the sound/music
			*/
			void control_volume(const std::string& name, int volume);

			/**
			* \brief Checks if the Audio by the given name is playing
			*/
			bool is_playing(const std::string& name) const;
		};
	}
}
