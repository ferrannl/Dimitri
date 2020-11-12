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
		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/white_square.jpg" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(window_width / 2 - bg_width / 2, window_height / 2 - bg_height / 2, 5000, bg_height, bg_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true));

		std::string font_path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Color color = { 0,0,0 };
		int win_text_width = 3 * 20;
		int win_text_height = 50;
		_textures.push_back(std::make_shared<Graphics::Models::Text>("win", color, window_width / 2 - win_text_width / 2, window_height / 2 - win_text_height / 2, 5000, win_text_height, win_text_width, 0, font_path, true));
	}

	void Views::WinLevelView::draw()
	{
		for (auto& t : _textures) {
			_graphics_controller->add_texture(t);
		}
	}

	bool Views::WinLevelView::is_visible() const
	{
		return true;
	}
}