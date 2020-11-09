#include "Wall.h"

Game::Models::Wall::Wall(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
	initialize_textures();
}

void Game::Models::Wall::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::HORIZONTAL, std::make_shared<Graphics::Models::Sprite>(0, 0, 1, 75, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground.png" }, Graphics::Enums::FlipEnum::NONE));
	add_texture(Game::Enums::StateEnum::VERTICAL, std::make_shared<Graphics::Models::Sprite>(0, 0, 1, 75, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground.png" }, Graphics::Enums::FlipEnum::VERTICAL));
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 1, 75, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::NONE));
	add_texture(Game::Enums::StateEnum::LEFT, std::make_shared<Graphics::Models::Sprite>(0, 0, 1, 75, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" }, Graphics::Enums::FlipEnum::HORIZONTAL));
	get_texture()->set_visible(true);
}
