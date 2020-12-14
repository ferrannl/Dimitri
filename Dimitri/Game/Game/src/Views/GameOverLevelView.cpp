#include "GameOverLevelView.h"

namespace Game {
	Views::GameOverLevelView::GameOverLevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) :
		View(graphics_controller)
	{
		init_textures();
	}

	void Views::GameOverLevelView::init_textures()
	{
		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();
		int bg_width = 500;
		int bg_height = 300;

		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/fail.png" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(window_width / 2 - bg_width / 2, window_height / 2 - bg_height / 2, 4, bg_height, bg_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, false));
	}

	bool Views::GameOverLevelView::is_visible() const
	{
		return true;
	}
}