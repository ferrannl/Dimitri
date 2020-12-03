#pragma once
#include <cstdint>

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define UTILITY_API
#endif

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Utility {
	/**
	* \namespace Game::Models
	* \brief Namespace for the models in the game
	*/
	namespace Time {
		/**
		* \class Timer
		* \brief Class contains the data of the Timer
		*/
		class UTILITY_API Timer {
		public:
			Timer();
			void start();
			void stop();
			void pause();
			void unpause();

			uint32_t getTicks();
			void set_current_ticks(uint32_t current_ticks);

			bool is_started();
			bool is_paused();

		private:
			uint32_t _current_ticks;
			uint32_t _pause_ticks;
			uint32_t _start_ticks;

			bool _started;
			bool _paused;
		};

	}
}
