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
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	Graphics::Models::Color color = { 255, 255, 255 };
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(40, _scene_height - 95, 3, 50, 60, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(std::make_unique<Game::Models::Button>(40, _scene_height - 95.0f, 50, 60, t, Enums::ButtonEnum::HOME));
	std::vector<std::pair<std::string, Enums::ButtonEnum>> button_map_left{ { "", Enums::ButtonEnum::START_TUTORIAL }, { "", Enums::ButtonEnum::START_LEVEL_1 },{ "", Enums::ButtonEnum::START_LEVEL_2 }, { "", Enums::ButtonEnum::START_LEVEL_3 } };

	int i = 0;
	float w = 200;
	float h = 170;
	int counter = 0;
	for (auto b : button_map_left) {

		t = {};
		add_button(std::make_unique<Models::Button>(_scene_height / 4 * 3 - 375 + (248 * i), _scene_width / 3 - (w / 2) + 30, h, w, t, b.second));
		get_buttons().back()->set_param(counter);
		counter++;
		i++;
	}

	t = {
			std::make_shared<Graphics::Models::Sprite>(_scene_width / 2, _scene_height /4 - 50 , 3, 50, 150, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>("Highscore", color, _scene_width / 2 + 25, _scene_height / 4 - 50 , 3, 50, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
	};
	add_button(std::make_unique<Models::Button>(_scene_width / 2, _scene_height / 4 - 50, 50, 150, t, Enums::ButtonEnum::HIGHSCORE));
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
