#include "Switch.h"

Game::Models::Switch::Switch(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IInteractable(x, y, z, height, width, state)
{
	initialize_textures();
}

void Game::Models::Switch::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::NONE));
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::HORIZONTAL));
	get_texture()->set_visible(true);
}

void Game::Models::Switch::interact()
{
	if (_state == Game::Enums::StateEnum::LEFT) {
		set_state(Game::Enums::StateEnum::RIGHT);
	}
	else {
		set_state(Game::Enums::StateEnum::LEFT);
	}
}
