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
		*	Contains code to controller audio engine
		*/
		class AudioController {
		private:
			/**
			*	Audio controller to interact with audio engine
			*/
			std::unique_ptr<Audio::Controllers::AudioController> _audio_controller;
		public:
			AudioController();
			/**
			*	Add Music
			*/
			void add_music(const std::string name, const std::string song_path);
			/**
			*	Add Sound
			*/
			void add_sound(const std::string name, const std::string song_path);

			/**
			*	Play Audio by name
			*/
			void play_audio(const std::string name);
			/**
			*	Pause Audio by name
			*/
			void pause_audio(const std::string name);
			/**
			*	Resume Audio by name
			*/
			void resume_audio(const std::string name);
			/**
			*	Stop Audio by name
			*/
			void stop_audio(const std::string name);
		};
	}
}
