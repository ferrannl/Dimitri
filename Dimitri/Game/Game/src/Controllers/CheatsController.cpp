#include "CheatsController.h"

Game::Controllers::CheatsController::CheatsController()
{
	_settings = std::make_shared<Game::Models::LevelCheatSettings>();
}

void Game::Controllers::CheatsController::initialize_textures(int height, int width)
{
	int window_width = width;
	int window_height = height;
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	Graphics::Models::Color color = { 255, 255, 255 };

	_buttons.push_back(std::make_unique<Game::Models::Buttons::CheckBox>(window_width / 2 + 100 + 50, 400, 10, 40, 40, Game::Enums::StateEnum::RIGHT, window_height, this->shared_from_this(), 0));
	_buttons.push_back(std::make_unique<Game::Models::Buttons::CheckBox>(window_width / 2 + 100 + 50, 300, 10, 40, 40, Game::Enums::StateEnum::RIGHT, window_height, this->shared_from_this(), 1));


	_textures.push_back(std::make_shared<Graphics::Models::Text>("Cheats", color, window_width / 2 - 150, 500, 10, 70, 300, 0, path, true));

	_textures.push_back(std::make_shared<Graphics::Models::Text>("Infinite Jump", color, window_width / 2 - 300 + 50, 400, 10, 40, 300, 0, path, true));
	_textures.push_back(std::make_shared<Graphics::Models::Sprite>(window_width / 2 + 100 + 50, 400, 10, 40, 40, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/button_border_gray.png" }, Graphics::Enums::FlipEnum::NONE, true));

	_textures.push_back(std::make_shared<Graphics::Models::Text>("Invincibility", color, window_width / 2 - 300 + 50, 300, 10, 40, 300, 0, path, true));
	_textures.push_back(std::make_shared<Graphics::Models::Sprite>(window_width / 2 + 100 + 50, 300, 10, 40, 40, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/button_border_gray.png" }, Graphics::Enums::FlipEnum::NONE, true));

	_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0 - 240, window_height - 270, 0, 340, 650, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg_cheats.jpg" }, Graphics::Enums::FlipEnum::NONE, true));
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::CheatsController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> all_textures;
	//gets all buttons textures
	for (auto& b : _buttons) {
		for (auto& t : b->get_all_textures()) {
			all_textures.push_back(t);
		}
	}
	//gets remaining textures
	for (auto& b : _textures) {
		all_textures.push_back(b);
	}
	return all_textures;
}

std::shared_ptr<Game::Models::LevelCheatSettings> Game::Controllers::CheatsController::get_cheat_settings() const
{
	return _settings;
}

void Game::Controllers::CheatsController::update(const Game::Events::InputEvent& object)
{
	for (auto& b : _buttons)
		b->update(object);
}

void Game::Controllers::CheatsController::check(int check_code)
{
	//for every checkbox one option
	switch (check_code) {
	case 0:
		//infinite jumps
		_settings->set_amount_of_jumps();
		break;
	case 1:
		//invincible
		_settings->set_invincible();
		break;
	}
}
