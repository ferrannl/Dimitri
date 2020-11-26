#pragma once

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
		* \class Check
		* \brief Class contains the data of the check
		*/
		class Check  {
		public:

			/**
			* \brief defines virtual method check which calls back click with code
			*/
			virtual void check(int check_code) = 0;
		};
	}
}