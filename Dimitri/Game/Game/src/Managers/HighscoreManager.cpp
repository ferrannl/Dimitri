#include "HighscoreManager.h"
#include "../Controllers/HomeController.h"
#include "../Controllers/InputController.h"
#include "../Controllers/WindowController.h"
#include "../Controllers/HomeController.h"
#include "../Mediators/CommandMediator.h"

Game::Managers::HighscoreManager::HighscoreManager(std::shared_ptr<Game::Controllers::InputController> input_controller, std::shared_ptr<Game::Controllers::AudioController> audio_controller, std::shared_ptr<Game::Controllers::WindowController> window_controller, std::shared_ptr<Game::Controllers::HomeController> home_controller)
	: BaseComponent("HighscoreManager"), _input_controller{ input_controller }, _audio_controller{ audio_controller }, _window_controller{ window_controller }, _home_controller{ home_controller } {}


void Game::Managers::HighscoreManager::load_highscore()
{

}

void Game::Managers::HighscoreManager::load_buttons()
{
	int window_height = _window_controller->get_window_height();
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(40, window_height - 95, 3, 50, 60, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(std::make_unique<Game::Models::Button>(40, window_height - 95, 50, 60, t, Enums::ButtonEnum::HOME));

}

void Game::Managers::HighscoreManager::update(const Game::Events::InputEvent& object)
{
	Mediators::CommandMediator::instance()->notify(*this, object);
}

const std::vector<std::shared_ptr<Graphics::Models::Texture>>& Game::Managers::HighscoreManager::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : get_buttons()) {
		for (auto& t : b->get_textures()) {
			button_textures.push_back(t);
		}
	}
	button_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, _window_controller->get_window_height(), _window_controller->get_window_width(), 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/records.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, false));
	return button_textures;
}


