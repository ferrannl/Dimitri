#include "GraphicsController.h"
using namespace Graphics;

Controllers::GraphicsController::GraphicsController()
{
	_window = nullptr;
}

int Controllers::GraphicsController::create_window(const std::string title, const int height, const int width)
{
	_window = std::make_shared<Models::Window>(title, height, width);
	return _window->create();
}

void Graphics::Controllers::GraphicsController::add_texture(const std::shared_ptr<Models::Texture>& texture)
{
	_window->add_texture(texture);
}

void Graphics::Controllers::GraphicsController::remove_texture(const std::shared_ptr<Models::Texture>& texture)
{
	_window->remove_texture(texture);
}

void Graphics::Controllers::GraphicsController::clear_textures()
{
	_window->clear_textures();
}

std::vector<std::shared_ptr<Models::Texture>> Graphics::Controllers::GraphicsController::get_textures() const
{
	return _window->get_textures();
}

void Controllers::GraphicsController::update_window()
{
	_window->update();
}

std::shared_ptr<Models::Window> Controllers::GraphicsController::get_window() const
{
	return _window;
}

int Graphics::Controllers::GraphicsController::get_fps()
{
	return _window->get_facade()->get_fps();
}