#include "WindowController.h"
using namespace Game;

Controllers::WindowController::WindowController()
{
	_open_window = false;
	_graphics_controller = std::make_unique<Graphics::Controllers::GraphicsController>();
	create_window(1080, 720);
}

void Game::Controllers::WindowController::create_window(int height, int width)
{
	if (_graphics_controller->create_window("Dimitri", width, height) == NULL) {
		return;
	}

	_credits_view = std::make_unique<Views::CreditsView>(_graphics_controller);
	_level_view = std::make_unique<Views::LevelView>(_graphics_controller);
}

void Game::Controllers::WindowController::update(const Game::Events::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::KEY_PRESS_C:
		if (!_credits_view.get()->is_open) {
			if (!_open_window) {
				_open_window = true;
				_credits_view.get()->open();
			}
		}
		else {
			_open_window = false;
			_credits_view.get()->close();
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_L:
		if (!_level_view.get()->is_open) {
			if (!_open_window) {
				_open_window = true;
				_level_view.get()->open();
			}
		}
		else {
			_open_window = false;
			_level_view.get()->close();
		}
	case Input::Enums::EventEnum::KEY_PRESS_QUIT:
		exit(0);
	case Input::Enums::EventEnum::KEY_PRESS_F:
		_graphics_controller->switch_fps();
		break;
	}
}


void Game::Controllers::WindowController::add_texture(std::shared_ptr<Graphics::Models::Texture> texture)
{
	_graphics_controller->add_texture(texture);
}

void Game::Controllers::WindowController::remove_texture(std::shared_ptr<Graphics::Models::Texture> texture)
{
	_graphics_controller->remove_texture(texture);
}

void Game::Controllers::WindowController::update_window()
{
	_graphics_controller->update_window();
}

void Game::Controllers::WindowController::destroy_window()
{
	_graphics_controller->get_window()->destroy();
}

void Game::Controllers::WindowController::set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures)
{
	_level_view->init_textures(textures);
}
