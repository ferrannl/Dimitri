#include "BaseComponent.h"
#include <utility>

namespace Game {
	namespace Mediators {
		BaseComponent::~BaseComponent() {}

		std::string BaseComponent::get_identifier() const
		{
			return _identifier;
		}

		void BaseComponent::add_button(Game::Models::Button b) {
			_buttons.push_back(std::make_unique<Game::Models::Button>(b));
		}

		const std::vector<std::unique_ptr<Game::Models::Button>>& BaseComponent::get_buttons() const {
			return _buttons;
		}
	}
}