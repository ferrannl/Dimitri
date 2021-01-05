#include "LevelView.h"

namespace Game {
	Views::LevelView::LevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {}

	bool Views::LevelView::is_visible() const
	{
		return true;
	}
}
