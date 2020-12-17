#include "HighscoreManager.h"
#include "../Controllers/HomeController.h"
#include "../Controllers/InputController.h"
#include "../Controllers/WindowController.h"
#include "../Controllers/HomeController.h"
#include "../Mediators/CommandMediator.h"

Game::Managers::HighscoreManager::HighscoreManager(std::shared_ptr<Game::Controllers::InputController>& input_controller, std::shared_ptr<Game::Controllers::AudioController>& audio_controller, std::shared_ptr<Game::Controllers::WindowController>& window_controller, std::shared_ptr<Game::Controllers::HomeController>& home_controller)
	: BaseComponent("HighscoreManager"), _input_controller{ input_controller }, _audio_controller{ audio_controller }, _window_controller{ window_controller }, _home_controller{ home_controller } {}


void Game::Managers::HighscoreManager::load_highscore()
{
	if (_window_controller->is_active(Enums::ViewEnum::HOME)) {
		_input_controller->unsubscribe(_home_controller);
		_window_controller->clear_views();
		_audio_controller->play_audio("highscore");
		_window_controller->open_view(Enums::ViewEnum::HIGHSCORE);
		_window_controller->set_scene_size(_window_controller->get_window_height(), _window_controller->get_window_width());
		_input_controller->subscribe(this->shared_from_this());
	}
}

void Game::Managers::HighscoreManager::load_buttons()
{
	int window_height = _window_controller->get_window_height();
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		   std::make_shared<Graphics::Models::Sprite>(10, window_height - 45, 3, 30, 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(std::make_unique<Game::Models::Button>( 10, window_height - 45.0f, 30, 30, t, Enums::ButtonEnum::HOME ));
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
	return button_textures;
}


