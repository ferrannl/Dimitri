#include "Button.h"

Game::Models::Button::Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height) : Game::Models::IInteractable(x, y, z, height, width, state)
{
	_scene_height = scene_height;
	initialize_textures();
}

void Game::Models::Button::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}

void Game::Models::Button::update(const Game::Events::InputEvent& object)
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
