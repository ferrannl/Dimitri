#include "View.h"

namespace Game {
	Views::View::View(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : _graphics_controller{ graphics_controller } {}

	void Views::View::update() {}

	void Views::View::open() {
		std::lock_guard<std::mutex> guard(_graphics_controller->get_window()->get_mutex());
		for (auto& t : _textures) {
			_graphics_controller->add_texture(t);
		}
	}

	void Views::View::close() {
		std::lock_guard<std::mutex> guard(_graphics_controller->get_window()->get_mutex());
		for (auto& t : _textures) {
			_graphics_controller->remove_texture(t);
		}
	}

	void Views::View::set_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures)
	{
		_textures = textures;
	}

	bool Views::View::is_active() const {
		return _active;
	}

	void Views::View::set_active(bool active) {
		_active = active;
	}

	bool Views::View::is_visible() const
	{
		return _visible;
	}

	void Views::View::set_visible(bool visible)
	{
		_visible = visible;
	}
	void Views::View::add_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures) {
		for (const std::shared_ptr<Graphics::Models::Texture>& a : textures) {
			_textures.push_back(a);
		}
	}
}
