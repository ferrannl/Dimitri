#include "GraphicsController.h"

void Controllers::GraphicsController::create_window(const std::string title, const int height, const int width)
{
	_window = std::make_shared<Models::Window>(title, height, width);
	_window->create();
}

void Controllers::GraphicsController::add_sprites(std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites)
{
	_window->set_sprites(sprites);
}

std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> Controllers::GraphicsController::get_sprites() const
{
	return _window->get_sprites();
}

void Controllers::GraphicsController::update_window()
{
	_window->update();
}

std::shared_ptr<Models::Window> Controllers::GraphicsController::get_window() const
{
	return _window;
}