#include "CheatsController.h"
#include "../Mediators/CommandMediator.h"
#include "../Models/CheckButton.h"
#include <conio.h> 
#include <stdio.h>


Game::Controllers::CheatsController::CheatsController(): Mediators::BaseComponent("CheatsController")
{
	_settings = std::make_shared<Game::Models::CheatsSettings>();
}

void Game::Controllers::CheatsController::initialize_textures(int height, int width)
{
	

	int window_width = width;
	int window_height = height;
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	Graphics::Models::Color color = { 255, 255, 255 };

	std::vector<std::shared_ptr<Graphics::Models::Texture>> t{
		std::make_shared<Graphics::Models::Sprite>(10, 0 + 10, 3, 30, 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/back_button.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false),
	};
	add_button(Game::Models::Button{ 10, 0 + 10.0f, 30, 30, t, Enums::ButtonEnum::HOME });

	_textures.push_back(std::make_shared<Graphics::Models::Text>("Cheats", color, window_width / 2 - 150, 500, 10, 70, 300, 0, path, true, Graphics::Models::Center{ 0,0 }, true));

	_textures.push_back(std::make_shared<Graphics::Models::Text>("Infinite Jump", color, window_width / 2 - 300 + 50, 400, 10, 40, 300, 0, path, true, Graphics::Models::Center{ 0,0 }, true));
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t1{
		std::make_shared<Graphics::Models::Sprite>(window_width / 2 + 100 + 50, 400, 10, 40, 40, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/button_border_gray.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, true),
		std::make_shared<Graphics::Models::Sprite>(window_width / 2 + 100 + 50, 400, 11, 40 + 30, 40 + 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/check.png" }, Graphics::Enums::FlipEnum::NONE, false, Graphics::Models::Center{ 0,0 }, true),
	};
	add_button(Game::Models::CheckButton{ window_width / 2 + 100 + 50.0f, 400, 40,40, t1, Enums::ButtonEnum::CHEATS_CHECKBOX_INFINITE });


	_textures.push_back(std::make_shared<Graphics::Models::Text>("Invincibility", color, window_width / 2 - 300 + 50, 300, 10, 40, 300, 0, path, true, Graphics::Models::Center{ 0,0 }, true));
	std::vector<std::shared_ptr<Graphics::Models::Texture>> t2{
		std::make_shared<Graphics::Models::Sprite>(window_width / 2 + 100 + 50, 300, 10, 40, 40, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/button_border_gray.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, true),
		std::make_shared<Graphics::Models::Sprite>(window_width / 2 + 100 + 50, 300, 11, 40 + 30, 40 + 30, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/check.png" }, Graphics::Enums::FlipEnum::NONE, false, Graphics::Models::Center{ 0,0 }, true),
	};
	add_button(Game::Models::CheckButton{ window_width / 2 + 100 + 50.0f, 300, 40,40, t2, Enums::ButtonEnum::CHEATS_CHECKBOX_INVINCIBLE });

	_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0 - 240, window_height - 270, 0, 340, 650, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg_cheats.jpg" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, true));
}

void Game::Controllers::CheatsController::update(const Game::Events::InputEvent& object)
{
	Game::Mediators::CommandMediator::instance()->notify(*this, object);
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::CheatsController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> all_textures;
	//gets all buttons textures
	for (auto& b : get_buttons()) {
		for (auto& t : b->get_textures()) {
			all_textures.push_back(t);
		}
	}
	//gets remaining textures
	for (auto& b : _textures) {
		all_textures.push_back(b);
	}
	return all_textures;
}

std::shared_ptr<Game::Models::CheatsSettings> Game::Controllers::CheatsController::get_cheat_settings() const
{
	return _settings;
}