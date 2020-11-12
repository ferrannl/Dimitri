#include "LevelView.h"

namespace Game {
	Views::LevelView::LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {}

	void Views::LevelView::draw()
	{
		for (auto& t : _textures) {
			_graphics_controller->add_texture(t);
		}
	}

	bool Views::LevelView::is_visible() const
	{
		return true;
	}
}
