#include "WinLevelView.h"

namespace Game {
	Views::WinLevelView::WinLevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) :
		View(graphics_controller)
	{
		init_textures();
	}

	void Views::WinLevelView::init_textures()
	{
		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();
		int bg_width = 500;
		int bg_height = 300;

		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/TravelingTypewriter.ttf" };
		Graphics::Models::Color color = { 255, 255, 255 };
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Level Complete", color, window_width / 2 - (20 * 14 / 2), window_height / 2 + bg_height / 2 - 125, 105, 50, 20 * 14, 0, path, true, Graphics::Models::Center{ 0,0 }, false));

		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/pause.png" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(window_width / 2 - bg_width / 2, window_height / 2 - bg_height / 2, 104, bg_height, bg_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, false));
	}

	bool Views::WinLevelView::is_visible() const
	{
		return true;
	}
}