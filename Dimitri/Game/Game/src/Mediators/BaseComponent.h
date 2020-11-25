#pragma once
#include <string>

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game::Mediators
	* \brief Namespace for the mediator pattern
	*/
	namespace Mediators {
		/**
		* \class BaseComponent
		* \brief Class contains the method to identify itself
		*/
		class BaseComponent {
		private:
			std::string _identifier;
		public:
			BaseComponent(const std::string& identifier) : _identifier{ identifier } {}

			/**
			* \brief Return the identifier
			*/
			std::string get_identifier() const { return _identifier; }
		};
	}
}