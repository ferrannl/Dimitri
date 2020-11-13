#include "Button.h"

Game::Models::Button::Button(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
	initialize_textures();
}


void Game::Models::Button::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE));
	get_texture()->set_visible(true);
}
