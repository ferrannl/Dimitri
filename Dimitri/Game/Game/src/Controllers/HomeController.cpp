#include "HomeController.h"
using namespace Game;

void Game::Controllers::HomeController::init_buttons()
{
	_buttons.push_back(std::make_shared<Game::Models::Button>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 150, 1, 50, 70, Game::Enums::StateEnum::RIGHT));
	_buttons.push_back(std::make_shared<Game::Models::Button>(_scene_width / 2 - 35, (_scene_height / 4 * 3) - 225, 1, 50, 70, Game::Enums::StateEnum::RIGHT));
}

Game::Controllers::HomeController::HomeController(int sceneheight, int scenewidth)
{
	_scene_height = sceneheight;
	_scene_width = scenewidth;
	init_buttons();
}

void Game::Controllers::HomeController::update(const Game::Events::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::MOUSE_PRESSED_LEFT:

		int x = std::get<0>(object.mouse_pos);
		int y = _scene_height - std::get<1>(object.mouse_pos);
		std::cout << "clicked on: (" + std::to_string(x) + "," + std::to_string(y) + ")" << std::endl;

		for (auto& b : _buttons)
			if (x >= b->get_x() && x <= b->get_x() + b->get_width() && y <= b->get_y() + b->get_height() && y >= b->get_y())
			{
				std::cout << "clicked within button: (" + std::to_string(x) + "," + std::to_string(y) + ")" << std::endl;

				//_input_controller->unsubscribe(_home_controller);
				//_window_controller->clear_views();
				//_window_controller->open_view("level");
				//_window_controller->open_view("fps");
				//_input_controller->subscribe(_level_controller);
				//_level_controller->start();
			}
		break;
	}
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Controllers::HomeController::get_textures() const
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> button_textures;
	for (auto& b : _buttons) {
		button_textures.push_back(b->get_texture());
	}
	return button_textures;
}