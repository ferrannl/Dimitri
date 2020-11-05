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
* Namespace for the audio engine
*/
namespace Audio {
	/**
	* Namespace for the controllers
	*/
	namespace Controllers {
		/**
		* Class containing the methods for using audio in the game
		*/
		class AUDIO_API AudioController {
		private:
			/**
			* A list where the audio models are stored which are being used
			*/
			std::vector<std::shared_ptr<Models::Audio>> _audios;

			/**
			* Returns an audio file by name from the _audios list
			*/
			std::shared_ptr<Models::Audio> get_audio_by_name(const std::string name) const;

			/**
			* Counts the amount of channels that currently are being used
			*/
			int _channel_counter;

			/**
			* returns an bool value which represents if the name for an audio model already exists
			*/
			bool name_exists(const std::string name);
		public:
			AudioController();

			/**
			* Adds sound effects to the _audios list
			*/
			void add_sound(const std::string name, const std::string path);

			/**
			* Adds music to the _audios list
			*/
			void add_music(const std::string name, const std::string path);


			/**
			* Plays the audio model by the given name
			*/
			void play_audio(const std::string name) const;


			/**
			* Resumes the audio model by the given name
			*/
			void resume_audio(const std::string name) const;


			/**
			* Pauses the audio model by the given name
			*/
			void pause_audio(const std::string name) const;

			/**
			* Stops the audio model by the given name
			*/
			void stop_audio(const std::string name) const;
		};
	}
}