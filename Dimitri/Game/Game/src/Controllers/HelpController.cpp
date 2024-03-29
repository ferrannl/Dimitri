#include "HelpController.h"
#include <src/Models/Color.h>
#include <src/Helpers/BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Mediators/CommandMediator.h"
using namespace Game;

Game::Controllers::HelpController::HelpController(int sceneheight, int scenewidth) :
	Mediators::BaseComponent("HelpController"), _scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_buttons();
}

void Game::Controllers::HelpController::load_buttons()
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(40, _scene_height - 95, 3, 50, 60, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(std::make_unique<Game::Models::Button>(40, _scene_height - 95, 50, 60, t, Enums::ButtonEnum::HOME));

}

void Game::Controllers::HelpController::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::HelpController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : get_buttons()) {
		for (auto& t : b->get_textures()) {
			button_textures.push_back(t);
		}
	}
	return button_textures;
}