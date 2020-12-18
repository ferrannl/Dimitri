#include "SaveGameController.h"
#include <src\Helpers\BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Mediators/CommandMediator.h"

std::string Game::Controllers::SaveGameController::get_text_for_save(Game::Models::Settings settings) const
{
	switch (settings.get_unlocked_level()) {
	case 0:
		return "New";
	default:
		return "level " + std::to_string(settings.get_unlocked_level());
	}
}

Game::Controllers::SaveGameController::SaveGameController(int sceneheight, int scenewidth) :
	Mediators::BaseComponent("SaveGameController"), _scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_buttons();
}

void Game::Controllers::SaveGameController::load_buttons()
{
	Graphics::Models::Color color = { 255, 255, 255 };
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(40, _scene_height - 95, 3, 50, 60, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(std::make_unique<Game::Models::Button>(40, _scene_height - 95, 50, 60, t, Enums::ButtonEnum::HOME));
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };

	std::vector<std::pair<std::string, Enums::ButtonEnum>> button_map_left{ { "Save1", Enums::ButtonEnum::SAVE1 }, { "Save2", Enums::ButtonEnum::SAVE2 },{ "Save3", Enums::ButtonEnum::SAVE3 } };

	std::vector<std::pair<std::string, Enums::ButtonEnum>> button_map_right{ 
		{ get_text_for_save(Game::Models::Settings(1)), Enums::ButtonEnum::NEW1 },
		{ get_text_for_save(Game::Models::Settings(2)), Enums::ButtonEnum::NEW1 },
		{ get_text_for_save(Game::Models::Settings(3)), Enums::ButtonEnum::NEW1 }
	};

	int i = 0;
	float w = 150;
	float h = 50;

	for (auto b : button_map_left) {
		w = 500;
		h = 100;

		float w_text = b.first.length() * 15;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_scene_width / 2 - (w / 2), _scene_height / 4 * 3 - (120 + (h + 25) * i), 2, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/grey_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _scene_width / 3 - (w_text / 2) + 50, (_scene_height / 4 * 3 - (120 + (h + 25) * i)) + 25, 3, h / 2, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		add_button(std::make_unique<Models::Button>(_scene_width / 3 - (w / 2) + 50, _scene_height / 4.0f * 3 - (120 + 70 * i), h, w, t, b.second));
		i++;
	}
	int j = 0;
	int counter = 1;
	for (auto b : button_map_right) {
		w = 150;
		h = 50;

		float w_text = b.first.length() * 15;
		t = {
			std::make_shared<Graphics::Models::Sprite>(((_scene_width / 3) * 2) - (w / 2) - 100, _scene_height / 4 * 3 - (95 + 125 * j), 2, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, ((_scene_width / 3) * 2) - (w_text / 2) - 100, _scene_height / 4 * 3 - (95 + 125 * j), 3, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		add_button(std::make_unique<Models::Button>(((_scene_width / 3) * 2) - (w / 2) - 100, _scene_height / 4 * 3 - (95 + 125 * j), h, w, t, b.second));
		get_buttons().back()->set_param(counter);
		counter++;

		j++;
	}

}

void Game::Controllers::SaveGameController::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::SaveGameController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : get_buttons()) {
		for (auto& t : b->get_textures()) {
			button_textures.push_back(t);
		}
	}
	button_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, _scene_height, _scene_width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/home_bg_emtpy.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, true));
	return button_textures;
}
