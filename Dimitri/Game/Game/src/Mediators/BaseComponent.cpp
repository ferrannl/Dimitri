#include "BaseComponent.h"
#include <utility>
#include <algorithm>

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

		std::vector<Game::Models::Button*> BaseComponent::get_buttons() const {
			std::vector<Game::Models::Button*> res;

			res.resize(_buttons.size());
			std::transform(_buttons.begin(), _buttons.end(), res.begin(),
				[](auto&& unique) { return unique.get(); });
			return res;
		}
	}
}