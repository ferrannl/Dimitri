#include "CheatView.h"
namespace Game {
	Views::CheatView::CheatView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller)
	{
	}

	bool Views::CheatView::is_visible() const
	{
		return true;
	}
}

