#include "../Views/TimerView.h"

namespace Game {

	Views::TimerView::TimerView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) :
		View(graphics_controller) { }

	void Views::TimerView::update()
	{
		std::tuple<int, int> camera_pos = _graphics_controller.get()->get_camera_pos();

		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();

		int timer_width = 54;
		close();
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Graphics::Models::Color color = { 255, 255, 255 };
		std::string ticks = std::to_string(_graphics_controller->get_window()->get_facade()->get_timer()->getTicks() / 1000.f);
		if (!is_visible()) {
			_textures.clear();
		}
		if (!_graphics_controller->get_window()->get_facade()->get_timer()->is_paused()) {
			_textures.push_back(std::make_shared<Graphics::Models::Text>(ticks, color, window_width - (window_width / 2) - timer_width, window_height - 60, 100, timer_width, 100, 0, path, true, Graphics::Models::Center{ 0,0 }, false));
		}
		open();

	}

	void Views::TimerView::close() {
		View::close();
		_textures.clear();
	}

	bool Views::TimerView::is_visible() const
	{
		return true;
	}

}

