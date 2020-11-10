#include "View.h"

namespace Game {
	Views::View::View(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : _graphics_controller{ graphics_controller } {}

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
}
