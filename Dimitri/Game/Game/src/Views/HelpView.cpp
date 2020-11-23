#include "HelpView.h"

namespace Game {
	Views::HelpView::HelpView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::HelpView::init_textures()
	{
		int bg_width = _graphics_controller->get_window()->get_width();
		int bg_height = _graphics_controller->get_window()->get_height();
		std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/help.png" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 5000, bg_height, bg_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true));

	}

	bool Views::HelpView::is_visible() const
	{
		return true;
	}

	void Views::HelpView::draw()
	{
		std::tuple<int, int> camera_pos = _graphics_controller.get()->get_camera_pos();

		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();

		for (auto& t : _textures) {
			t->set_x((window_width / 2 - t->get_width() / 2) + std::get<0>(camera_pos));
			t->set_y((window_height / 2 - t->get_height() / 2) + std::get<1>(camera_pos));
		}
		View::draw();
	}

}
