#include "StartButton.h"

Game::Models::Buttons::StartButton::StartButton(int x, int y, int z, int height, int width, Game::Enums::StateEnum state, int scene_height, std::shared_ptr<Managers::LevelManager> level_manager) : Game::Models::Button(x,y,z,height,width,state,scene_height)
{
	_level_manager = level_manager;
	initialize_textures();
}

void Game::Models::Buttons::StartButton::initialize_textures()
{
	add_texture(Game::Enums::StateEnum::RIGHT, std::make_shared<Graphics::Models::Sprite>(0, 0, 2, 150, 75, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/buttons.png" }, Graphics::Enums::FlipEnum::NONE, true));
	get_texture()->set_visible(true);
}

void Game::Models::Buttons::StartButton::interact()
{
	_level_manager->load_level();
}
