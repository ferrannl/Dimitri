#include "ExitButton.h"

Game::Models::Buttons::ExitButton::ExitButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height) : Game::Models::IButton(x, y, z, height, width, state, scene_height, Game::Enums::ButtonEnum::EXIT)
{
	initialize_textures();
}

void Game::Models::Buttons::ExitButton::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}

void Game::Models::Buttons::ExitButton::interact()
{
	exit(0);
}