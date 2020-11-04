#include "WindowController.h"
using namespace Game;

Controllers::WindowController::WindowController()
{
	_graphics_controller = std::make_shared<Graphics::Controllers::GraphicsController>();
	if (_graphics_controller->create_window("Test", 720, 1080) == NULL) {
		return;
	}

	_credits_view = std::make_unique<Views::CreditsView>(_graphics_controller);
}

void Game::Controllers::WindowController::update(const Game::Models::InputEvent& object)
{
	switch (object.event_enum) {
	case Input::Enums::EventEnum::KEY_PRESS_C:
		if (!_credits_view.get()->is_open) {
			_credits_view.get()->open();
		}
		else {
			_credits_view.get()->close();
		}
		break;
	case Input::Enums::EventEnum::KEY_PRESS_QUIT:
		exit(0);
	case Input::Enums::EventEnum::KEY_PRESS_F:
		_graphics_controller->switch_fps();
		break;
	}
}
