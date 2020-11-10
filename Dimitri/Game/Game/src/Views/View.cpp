#include "View.h"

namespace Game {
	Views::View::View(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : _graphics_controller{ graphics_controller } {}

	void Views::View::set_textures(const std::vector<std::shared_ptr<Graphics::Models::Texture>>& textures)
	{
		_textures = textures;
	}

	bool Views::View::is_open() const {
		return _open;
	}

	void Views::View::set_open(bool open) {
		_open = open;
	}
}
