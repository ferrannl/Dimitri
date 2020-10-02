#include "GraphicsController.h"

void Controllers::GraphicsController::create_window(const char* title, int xpos, int ypos, int height, int width)
{
	_window = new Models::Window(title, xpos, ypos, height, width);
	_window->create();
}

void Controllers::GraphicsController::add_sprites(std::vector<Models::Sprite*> sprites)
{
	_window->set_sprites(sprites);
	_window->create_sprites();
}

std::vector<Models::Sprite*> Controllers::GraphicsController::get_sprites()
{
	return _window->get_sprites();
}

void Controllers::GraphicsController::update_window()
{
	_window->update();
}

Models::Window* Controllers::GraphicsController::get_window()
{
	return _window;
}
