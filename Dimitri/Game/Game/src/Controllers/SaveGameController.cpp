#include "SaveGameController.h"
#include <src\Helpers\BasePathHelper.h>
#include <src/Models/Sprite.h>
#include "../Mediators/CommandMediator.h"

Game::Controllers::SaveGameController::SaveGameController(int sceneheight, int scenewidth) :
	Mediators::BaseComponent("SaveGameController"), _scene_height{ sceneheight }, _scene_width{ scenewidth }
{
	load_buttons();
}

void Game::Controllers::SaveGameController::load_buttons()
{
	Graphics::Models::Color color = { 255, 255, 255 };
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(10, _scene_height - 65, 3, 30, 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(Game::Models::Button{ 10, _scene_height - 65.0f, 30, 30, t, Enums::ButtonEnum::HOME });
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	std::vector<std::pair<std::string, Enums::ButtonEnum>> button_map_left{ { "Save1", Enums::ButtonEnum::SAVE1 }, { "Save2", Enums::ButtonEnum::SAVE2 },{ "Save3", Enums::ButtonEnum::SAVE3 } };
	std::vector<std::pair<std::string, Enums::ButtonEnum>> button_map_right{ { "New", Enums::ButtonEnum::SAVE1 }, { "New", Enums::ButtonEnum::SAVE2 },{ "New", Enums::ButtonEnum::SAVE3 } };
	int i = 0;
	float w = 150;
	float h = 50;
	for (auto b : button_map_left) {

		//billy
		float w_text = b.first.length() * 15;
		t = {
			std::make_shared<Graphics::Models::Sprite>(_scene_width / 3 - (w / 2) + 50, _scene_height / 4 * 3 - (120 + 70 * i), 2, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/save_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, _scene_width / 3 - (w_text / 2) + 50, _scene_height / 4 * 3 - (120 + 70 * i), 3, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		add_button(Models::Button{ _scene_width / 2 - (w / 2), _scene_height / 4.0f * 3 - (120 + 70 * i), h, w, t, b.second });
		i++;
	}
	int j = 0;
	for (auto b : button_map_right) {
		float w_text = b.first.length() * 15;
		t = {
			std::make_shared<Graphics::Models::Sprite>(((_scene_width / 3) * 2) - (w / 2) - 50, _scene_height / 4 * 3 - (120 + 70 * j), 2, h, w, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/save_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
			std::make_shared<Graphics::Models::Text>(b.first, color, ((_scene_width / 3) * 2) - (w_text / 2) - 50, _scene_height / 4 * 3 - (120 + 70 * j), 3, h, w_text, 0, path, true, Graphics::Models::Center{ 0, 0 }, false)
		};
		add_button(Models::Button{ _scene_width / 2 - (w / 2), _scene_height / 4.0f * 3 - (120 + 70 * j), h, w, t, b.second });
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
	return button_textures;
}
