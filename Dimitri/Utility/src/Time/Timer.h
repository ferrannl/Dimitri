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
		private:
			/**
			* \brief The current ticks of a timer
			*/
			uint32_t _current_ticks;
			/**
			* \brief The pause ticks of a timer
			*/
			uint32_t _pause_ticks;
			/**
			* \brief The start ticks of a timer
			*/
			uint32_t _start_ticks;

			bool _started;
			bool _paused;

		public:
			Timer();

			/**
			* \brief Method to start the timer
			*/
			void start();

			/**
			* \brief Method to stop the timer
			*/
			void stop();

			/**
			* \brief Method to pause the timer
			*/
			void pause();

			/**
			* \brief Method to unpause the timer
			*/
			void unpause();

			/**
			* \brief Gets the current ticks from a level
			*/
			uint32_t getTicks();

			/**
			* \brief Sets the current ticks based on SDL ticks
			*/
			void set_current_ticks(uint32_t current_ticks);

			/**
			* \brief Returns if the timer is started or not
			*/
			bool is_started();

			/**
			* \brief Returns if the timer is paused or not
			*/
			bool is_paused();

		};
	}
}
