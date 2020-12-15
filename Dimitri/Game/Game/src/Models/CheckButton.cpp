#include "CheckButton.h"

Game::Models::CheckButton::CheckButton(float x, float y, float height, float width, const std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, Enums::ButtonEnum identifier) : Game::Models::Button(x, y, height, width, textures, identifier)
{
	_check_sprite = textures.at(1);
}

void Game::Models::CheckButton::button_visual_action()
{
	if (_check_sprite->is_visible()) {
		_check_sprite->set_visible(false);
	}
	else {
		_check_sprite->set_visible(true);
	}
}