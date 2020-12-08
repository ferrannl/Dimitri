#include "Button.h"

namespace Game {
	namespace Models {
		Button::Button(int x, int y, int z, int height, int width, Enums::DirectionEnum state, int scene_height, Graphics::Models::Center center, const std::string& identifier, Game::Enums::ButtonEnum type) :
			Interactable(x, y, z, height, width, state, center), Mediators::BaseComponent(identifier) {
			_scene_height = scene_height;
			_type = type;
		}

		void Button::initialize_textures()
		{
			_animatestate = Enums::AnimateEnum::IDLE1;
			add_texture(Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true, _center));
			get_texture()->set_visible(true);
		}

		void Button::update(const Events::InputEvent& object)
		{
			switch (object.event_enum) {
			case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:

				int x = std::get<0>(object.mouse_pos);
				int y = _scene_height - std::get<1>(object.mouse_pos);

				if (x >= get_x() && x <= get_x() + get_width() && y <= get_y() + get_height() && y >= get_y())
				{
					interact();
				}
			}
		}
	}
}

Game::Enums::ButtonEnum Game::Models::Button::get_type()
{
	return _type;
}
