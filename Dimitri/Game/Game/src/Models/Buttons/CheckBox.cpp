#include "CheckBox.h"

Game::Models::Buttons::CheckBox::CheckBox(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, const std::shared_ptr<Check> check, int check_code) : _check{ check }, _check_code{ check_code }, Game::Models::Button(x, y, z, height, width, state, scene_height)
{
	_check_sprite = std::make_shared<Graphics::Models::Sprite>(x, y, z+1, height + 30, width + 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/check.png" }, Graphics::Enums::FlipEnum::NONE, false);
	add_texture(Game::Enums::StateEnum::LEFT, _check_sprite);
}

void Game::Models::Buttons::CheckBox::interact()
{
	if (_check_sprite->is_visible()) {
		_check_sprite->set_visible(false);
	}
	else {
		_check_sprite->set_visible(true);
	}
	_check->check(_check_code);
}