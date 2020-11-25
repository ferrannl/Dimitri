#pragma once
#include <SDL.h>
#include <stdint.h>
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
			Timer();
			void start();
			void stop();

			uint32_t getTicks();

			bool is_started();
			
		private:
			Uint32 _pause_ticks;
			uint32_t _start_ticks;
			
			bool _started;
			bool _paused;
		};

	}
}
