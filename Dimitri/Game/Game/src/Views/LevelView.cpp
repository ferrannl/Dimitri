#include "LevelView.h"
using namespace Game;

Views::LevelView::LevelView(std::shared_ptr<Graphics::Controllers::GraphicsController> graphics_controller) : _graphics_controller{ graphics_controller }
{
}

void Views::LevelView::init_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures)
{
	_textures = textures;
}

void Views::LevelView::open()
{
	is_open = true;
	for (auto texture : _textures) {
		_graphics_controller.get()->add_texture(texture);
	}
	draw_thread = std::thread(&Views::LevelView::draw, this);
}

void Views::LevelView::close()
{
	is_open = false;
	draw_thread.join();
	for (auto texture : _textures) {
		_graphics_controller.get()->remove_texture(texture);
	}
	_graphics_controller.get()->update_window();
}

void Game::Views::LevelView::draw()
{
	while (is_open) {
		sleep_for(5ms);
		_graphics_controller.get()->update_window();
	}
}
