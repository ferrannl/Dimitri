#include "HomeController.h"
using namespace Game;

void Game::Controllers::HomeController::init_buttons()
{
	_buttons.push_back(std::make_shared<Game::Models::Buttons::StartButton>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 150, 1, 50, 70, Game::Enums::StateEnum::RIGHT, _scene_height));
	_buttons.push_back(std::make_shared<Game::Models::Buttons::ExitButton>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 225, 1, 50, 70, Game::Enums::StateEnum::RIGHT, _scene_height));
}

Game::Controllers::HomeController::HomeController(int sceneheight, int scenewidth)
{
	_scene_height = sceneheight;
	_scene_width = scenewidth;
	init_buttons();
}

void Game::Controllers::HomeController::update(const Game::Events::InputEvent& object)
{
	for (auto& b : _buttons)
		b->update(object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::HomeController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : _buttons) {
		button_textures.push_back(b->get_texture());
	}
	return button_textures;
}