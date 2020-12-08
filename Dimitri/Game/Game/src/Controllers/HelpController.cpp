#include "HelpController.h"
#include <src/Models/Color.h>
#include <src/Helpers/BasePathHelper.h>
#include <src/Models/Sprite.h>
using namespace Game;

Game::Controllers::HelpController::HelpController(int sceneheight, int scenewidth) :
	_scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_buttons();
}

void Game::Controllers::HelpController::load_buttons()
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(10, _scene_height - 65, 3, 30, 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	_buttons.push_back(std::make_unique<Game::Models::Button>(10, _scene_height - 65, 30, 30, t, "Home"));
}

void Game::Controllers::HelpController::update(const Game::Events::InputEvent& object)
{
	for (auto& b : _buttons)
		if (b->is_clicked(object))
			b->on_click(object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::HelpController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : _buttons) {
		for (auto& t : b->get_textures()) {
			button_textures.push_back(t);
		}
	}
	return button_textures;
}