#include "Button.h"

Game::Models::Button::Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, Game::Enums::ButtonEnum type) : Game::Models::IInteractable(x, y, z, height, width, state)
{
	_type = type;
	_scene_height = scene_height;
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

Game::Enums::ButtonEnum Game::Models::Button::get_type()
{
	return _type;
}
