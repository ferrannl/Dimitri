#include "CreditsController.h"
#include <src/Models/Color.h>
#include <src/Helpers/BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Mediators/CommandMediator.h"
using namespace Game;

Game::Controllers::CreditsController::CreditsController(int sceneheight, int scenewidth) :
	Mediators::BaseComponent("CreditsController"), _scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_buttons();
}

void Game::Controllers::CreditsController::load_buttons()
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(10, _scene_height - 45, 3, 30, 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(Game::Models::Button{ 10, _scene_height - 45.0f, 30, 30, t, "Home" });
}

void Game::Controllers::CreditsController::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::CreditsController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : get_buttons()) {
		for (auto& t : b->get_textures()) {
			button_textures.push_back(t);
		}
	}
	return button_textures;
}