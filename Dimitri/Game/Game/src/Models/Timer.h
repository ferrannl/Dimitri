#pragma once
#include <SDL.h>
#include <stdint.h>
#include "../Controllers/WindowController.h"
/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Models {
		/**
		* \class Timer
		* \brief Class contains the data of the Timer
		*/
		class Timer {
		public:
			Timer(const std::shared_ptr<Controllers::WindowController> window_controller);
			void start();
			void stop();
			void pause();
			void unpause();

			Uint32 getTicks();

			bool is_started();
			bool is_paused();
			Uint32 get_start_ticks();
			
		private:
			std::shared_ptr<Controllers::WindowController> _window_controller;
			Uint32 _pause_ticks;
			Uint32 _start_ticks;
			
			bool _started;
			bool _paused;
		};

	}
}
