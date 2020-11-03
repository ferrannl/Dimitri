#include "Switch.h"

Game::Models::Switch::Switch(int x, int y, int z, int height, int width) : Game::Models::IInteractable(x, y, z, height, width)
{
	initialize_textures();
}

void Game::Models::Switch::initialize_textures()
{
	_state = "left";
	add_texture("left", std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::NONE));
	add_texture("right", std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/switch01.png" }, Graphics::Enums::FlipEnum::HORIZONTAL));
}

void Game::Models::Switch::interact()
{
	if (_state == "left") {
		set_state("right");
	}
	else {
		set_state("left");
	}
}
