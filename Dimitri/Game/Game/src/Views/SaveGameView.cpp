#include "SaveGameView.h"
#include "../Models/Button.h"

namespace Game {
	Views::SaveGameView::SaveGameView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::SaveGameView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();		
	}

	bool Views::SaveGameView::is_visible() const
	{
		return true;
	}

}
