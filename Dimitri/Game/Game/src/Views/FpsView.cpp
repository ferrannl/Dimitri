#include "FpsView.h"
#include <iostream>

namespace Game {
	Views::FpsView::FpsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {}

	void Views::FpsView::update()
	{
		std::string fps = std::to_string(_graphics_controller.get()->get_fps());
		fps = fps.substr(0, fps.find("."));
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		int width = fps.size() * 15;
		int height = 50;
		close();
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Graphics::Models::Color color { 255, 255, 255 };
		_textures.push_back(std::make_shared<Graphics::Models::Text>(fps, color, window_width - width - 5, window_height - height, 100, height, width, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
		open();
	}

	void Views::FpsView::close() {
		View::close();
		_textures.clear();
	}
}