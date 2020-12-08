#include "Button.h"
#include "../Mediators/CommandMediator.h"

namespace Game {
	namespace Models {
		Button::Button(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& identifier) :
			Mediators::BaseComponent("Button::" + identifier), _x{ x }, _y{ y }, _height{ height }, _width{ width }, _textures{textures} {}

		bool Button::is_clicked(Game::Events::InputEvent object)
		{
			if (object.event_enum == Input::Enums::EventEnum::MOUSE_PRESSED_LEFT) {
				int x = std::get<0>(object.mouse_pos);
				int y = std::get<1>(object.mouse_pos);

				return x >= _x && x <= _x + _width && y <= _y + _height && y >= _y;
			}
			return false;
		}

		void Button::on_click(Game::Events::InputEvent object)
		{
			Mediators::CommandMediator::instance()->notify(*this, object);
		}

		std::vector<std::shared_ptr<Graphics::Models::Texture>> Button::get_textures() const
		{
			return _textures;
		}
	}
}