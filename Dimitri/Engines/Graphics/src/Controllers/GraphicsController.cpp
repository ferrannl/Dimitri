#include "GraphicsController.h"
using namespace Graphics;

Controllers::GraphicsController::GraphicsController()
{
	_speed = 1.5;
	_window = nullptr;
}

int Controllers::GraphicsController::create_window(const std::string& title, int height, int width)
{
	_window = std::make_unique<Models::Window>(title, height, width);
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

const std::unique_ptr<Models::Window>& Controllers::GraphicsController::get_window() const
{
	return _window;
}

float Graphics::Controllers::GraphicsController::get_fps() const
{
	return _window->get_fps();
}

Uint32 Graphics::Controllers::GraphicsController::get_ticks() const {
	return _window->get_ticks();
}

void Graphics::Controllers::GraphicsController::set_camera_pos(int x, int y)
{
	_window->set_camera_pos(x, y);
}

std::tuple<float, float> Graphics::Controllers::GraphicsController::get_camera_pos() const
{
	return _window->get_camera_pos();
}

void Graphics::Controllers::GraphicsController::set_scene_size(int height, int width)
{
	_window->set_scene_size(height, width);
}

std::tuple<int, int> Graphics::Controllers::GraphicsController::get_scene_size() const
{
	return _window->get_scene_size();
}

void Graphics::Controllers::GraphicsController::set_speed(float speed)
{
	_speed = speed;
}

float Graphics::Controllers::GraphicsController::get_speed() const
{
	return _speed;
}