#pragma once
#include <src\Controllers\AudioController.h>
#include <iostream>
#include <src\Helpers\BasePathHelper.h>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Controllers
	* \brief Namespace for the controllers in the game
	*/
	namespace Controllers {
		/**
		* \class AudioController
		* \brief Class contains the methods to use the audio engine
		*/
		class AudioController {
		private:
			/**
			* \brief An instance of the AudioController to interact with audio engine
			*/
			std::unique_ptr<Audio::Controllers::AudioController> _audio_controller;
		public:
			AudioController();

			/**
			* \brief Adds music
			*/
			void add_music(const std::string name, const std::string song_path, int volume = 50);

			/**
			* \brief Adds sound
			*/
			void add_sound(const std::string name, const std::string song_path, int volume = 50);

			/**
			* \brief Play Audio by name
			*/
			void play_audio(const std::string name);

			/**
			* \brief Pause Audio by name
			*/
			void pause_audio(const std::string name);

			/**
			* \brief Resume Audio by name
			*/
			void resume_audio(const std::string name);

			/**
			* \brief Stop Audio by name
			*/
			void stop_audio(const std::string name);

			/**
			* \brief Sets the volume of the Audio
			*/
			void set_volume(const std::string& name, int vol);

			/**
			* \brief Returns if the Audio is playing
			*/
			bool is_playing(const std::string name);
		};
	}
}
