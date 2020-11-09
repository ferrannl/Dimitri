#include "IView.h"
using namespace Game;


Views::IView::IView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : _graphics_controller{ graphics_controller }
{
	is_open = false;
}

void Views::IView::close()
{
	is_open = false;
	draw_thread.join();
	for (auto texture : _textures) {
		_graphics_controller.get()->remove_texture(texture);
	}
	_graphics_controller.get()->update_window();
}

void Views::IView::draw()
{
	while (is_open) {
		sleep_for(5ms);
		_graphics_controller.get()->update_window();
	}
}

void Views::IView::open()
{
	is_open = true;
	for (auto texture : _textures) {
		_graphics_controller.get()->add_texture(texture);
	}
	draw_thread = std::thread(&Views::IView::draw, this);
}
