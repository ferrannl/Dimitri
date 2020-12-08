#include "HomeView.h"
#include "../Models/Button.h"

namespace Game {
	Views::HomeView::HomeView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::HomeView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		Graphics::Models::Color color = { 255, 255, 255 };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		_textures.push_back(std::make_shared<Graphics::Models::Text>("DIMITRI", color, window_width / 2 - 100, (window_height / 4 * 3), 10, 80, 200, 0, path, true, Graphics::Models::Center{ 0, 0 }, true));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("De stealth game van 2020!", color, window_width / 2 - 175, (window_height / 4 * 3) - 50, 1, 50, 350, 0, path, true, Graphics::Models::Center{ 0, 0 }, true));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Highscore", color, window_width - 120, window_height - 70, 1, 50, 90, 0, path, true, Graphics::Models::Center{ 0, 0 }, true));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Play", color, window_width / 2 - 25, (window_height / 4 * 3) - 150, 1, 50, 50, 0, path, true, Graphics::Models::Center{ 0, 0 }, true));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Exit", color, window_width / 2 - 25, (window_height / 4 * 3) - 225, 1, 50, 50, 0, path, true, Graphics::Models::Center{ 0, 0 }, true));
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, window_height, window_width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, true, Graphics::Models::Center{ 0, 0 }, true));
	}

	bool Views::HomeView::is_visible() const
	{
		return true;
	}

}