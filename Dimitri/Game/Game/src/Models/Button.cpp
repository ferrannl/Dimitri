#include "Button.h"

namespace Game {
	namespace Models {
		Button::Button(int x, int y, int z, int height, int width,Enums::StateEnum state, int scene_height, const std::string& identifier) : IInteractable(x, y, z, height, width, state), Mediators::BaseComponent(identifier)
		{
			_scene_height = scene_height;
			initialize_textures();
		}

		void Button::initialize_textures()
		{
			add_texture(Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true));
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