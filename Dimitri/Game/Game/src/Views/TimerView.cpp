#include "../Views/TimerView.h"

namespace Game {

	Views::TimerView::TimerView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		//_level_controller = level_controller;
	}

	void Views::TimerView::draw()
	{
		std::tuple<int, int> camera_pos = _graphics_controller.get()->get_camera_pos();

		int window_width_camera = _graphics_controller.get()->get_window().get()->get_width() + std::get<0>(camera_pos);
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height_camera = _graphics_controller.get()->get_window().get()->get_height() + std::get<1>(camera_pos);

		int timer_width = 54;

		_textures.clear();
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Graphics::Models::Color color = { 255, 255, 255 };
		_textures.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(_graphics_controller->get_ticks() / 1000.f), color, window_width_camera - (window_width / 2) - timer_width, window_height_camera - 60, 100, timer_width, 100, 0, path, true));

		View::draw();

	}
	

}

