#include "HighscoreView.h"

namespace Game {
	Views::HighscoreView::HighscoreView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}


	void Views::HighscoreView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/records.png" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 5000, window_height, window_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true));

	}

	bool Views::HighscoreView::is_visible() const
	{
		return true;
	}
}



