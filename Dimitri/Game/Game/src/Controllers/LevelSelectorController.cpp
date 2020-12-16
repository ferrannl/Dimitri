#include "LevelSelectorController.h"
#include <src\Helpers\BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Mediators/CommandMediator.h"

Game::Controllers::LevelSelectorController::LevelSelectorController(int sceneheight, int scenewidth) :
	Mediators::BaseComponent("LevelSelectorController"), _scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_buttons();
}

void Game::Controllers::LevelSelectorController::load_buttons()
{
	Graphics::Models::Color color = { 255, 255, 255 };
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(10, _scene_height - 65, 3, 30, 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(std::make_unique<Game::Models::Button>(10, _scene_height - 65.0f, 30, 30, t, Enums::ButtonEnum::HOME));
}

void Game::Controllers::LevelSelectorController::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::LevelSelectorController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : get_buttons()) {
		for (auto& t : b->get_textures()) {
			button_textures.push_back(t);
		}
	}
	return button_textures;
}
