#include "HighscoreView.h"

namespace Game {
	Views::HighscoreView::HighscoreView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		_record_times = {};
		init_textures();
	}


	void Views::HighscoreView::init_textures()
	{
	}

	bool Views::HighscoreView::is_visible() const
	{
		return true;
	}
	void Views::HighscoreView::add_record(std::string record)
	{
	}
}



