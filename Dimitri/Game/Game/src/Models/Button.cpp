#include "Button.h"

namespace Game {
	namespace Models {
		Button::Button(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ButtonEnum identifier) :
			_x{ x }, _y{ y }, _height{ height }, _width{ width }, _textures{ textures }, _identifier{ identifier } {}

		bool Game::Models::Button::is_clicked(Game::Events::InputEvent object)
		{
			if (object.event_enum == Input::Enums::EventEnum::MOUSE_PRESSED_LEFT) {
				int x = std::get<0>(object.mouse_pos);
				int y = std::get<1>(object.mouse_pos);

				if (x >= get_x() && x <= get_x() + get_width() && y <= get_y() + get_height() && y >= get_y()) {
					button_visual_action();
					return true;
				}
			}
			return false;
		}

		void Button::button_visual_action()
		{
			return;
		}

		std::vector<std::shared_ptr<Graphics::Models::Texture>> Button::get_textures() const
		{
			return _textures;
		}

		float Button::get_x() const
		{
			return _x;
		}

		float Button::get_y() const
		{
			return _y;
		}

		float Button::get_height() const
		{
			return _height;
		}

		float Button::get_width() const
		{
			return _width;
		}

		void Button::set_x(float x)
		{
			_x = x;
		}

		void Button::set_y(float y)
		{
			_y = y;
		}
		Enums::ButtonEnum Button::get_identifier() const
		{
			return _identifier;
		}
	}
}
