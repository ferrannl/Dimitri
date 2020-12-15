#include "CheatsView.h"
namespace Game {
	Views::CheatsView::CheatsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller)
	{
	}

	bool Views::CheatsView::is_visible() const
	{
		return true;
	}
}