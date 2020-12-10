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
			/**
			* \brief The identifier of this component
			*/
			std::string _identifier;
		public:
			BaseComponent(const std::string& identifier) : _identifier{ identifier } {}
			virtual ~BaseComponent() = 0;
			BaseComponent(BaseComponent const& other) = default;
			BaseComponent& operator=(BaseComponent const& other) = default;
			BaseComponent(BaseComponent && that) noexcept = default;
			BaseComponent& operator=(BaseComponent && that) noexcept = default;

			/**
			* \brief Return the identifier
			*/
			std::string get_identifier() const { return _identifier; }
		};
	}
}