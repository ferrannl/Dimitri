#include "WindowController.h"
using namespace Game;
Controllers::WindowController::WindowController()
{
	_graphics_controller = std::make_unique<Graphics::Controllers::GraphicsController>();
	if (_graphics_controller->create_window("Test", 720, 1080) == NULL) {
		return;
	}
}
