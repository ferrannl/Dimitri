#include "CheckButton.h"

Game::Models::CheckButton::CheckButton(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ButtonEnum identifier) : Game::Models::Button(x, y, height, width, textures, identifier)
{
	_check_sprite = textures.at(1);
}

bool Game::Models::CheckButton::is_clicked(Game::Events::InputEvent object)
{
	if (object.event_enum == Input::Enums::EventEnum::MOUSE_PRESSED_LEFT) {
		int x = std::get<0>(object.mouse_pos);
		int y = std::get<1>(object.mouse_pos);

		if (x >= get_x() && x <= get_x() + get_width() && y <= get_y() + get_height() && y >= get_y()) {
			if (_check_sprite->is_visible()) {
				_check_sprite->set_visible(false);
			}
			else {
				_check_sprite->set_visible(true);
			}
			return true;
		}
	}
	return false;
}