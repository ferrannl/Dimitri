#include "GameOverLevelView.h"

namespace Game {
	Views::GameOverLevelView::GameOverLevelView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) :
		View(graphics_controller)
	{
		init_textures();
	}

	void Views::GameOverLevelView::init_textures()
	{
		int bg_width = 500;
		int bg_height = 300;
		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/white_square.jpg" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 5000, bg_height, bg_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }));

		std::string font_path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Graphics::Models::Color color = { 0,0,0 };
		int win_text_width = 9 * 20;
		int win_text_height = 50;
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Game Over", color, 0, 0, 5000, win_text_height, win_text_width, 0, font_path, true, Graphics::Models::Center{ 0, 0 }));
	}

	bool Views::GameOverLevelView::is_visible() const
	{
		return true;
	}

	void Views::GameOverLevelView::update()
	{
		std::tuple<int, int> camera_pos = _graphics_controller.get()->get_camera_pos();

		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();

		for (auto& t : _textures) {
			t->set_x((window_width / 2 - t->get_width() / 2) + std::get<0>(camera_pos));
			t->set_y((window_height / 2 - t->get_height() / 2) + std::get<1>(camera_pos));
		}
	}
}