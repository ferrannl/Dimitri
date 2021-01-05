#pragma once
#include <string>
#include <vector>
#include <memory>
#include "../Models/Button.h"
#include "../Models/CheckButton.h"

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

			/**
			* \brief A list of the buttons
			*/
			std::vector<std::unique_ptr<Game::Models::Button>> _buttons;
		public:
			BaseComponent(const std::string& identifier) : _identifier{ identifier } {}
			virtual ~BaseComponent() = 0;
			BaseComponent(BaseComponent const& other) = default;
			BaseComponent& operator=(BaseComponent const& other) = default;
			BaseComponent(BaseComponent&& that) noexcept = default;
			BaseComponent& operator=(BaseComponent&& that) noexcept = default;

			/**
			* \brief Returns the identifier
			*/
			const std::string& get_identifier() const;

			/**
			* \brief Add a button to the buttons
			*/
			void add_button(std::unique_ptr<Game::Models::Button> b);

			/**
			* \brief Returns the buttons
			*/
			virtual std::vector<Game::Models::Button*> get_buttons() const;
		};
	}
}