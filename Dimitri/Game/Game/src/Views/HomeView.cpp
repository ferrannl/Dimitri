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
		std::shared_ptr<Graphics::Models::Text> title = std::make_shared<Graphics::Models::Text>("DIMITRI", color, window_width / 2 - 100, (window_height / 4 * 3), 10, 80, 200, 0, path, true);
		std::shared_ptr<Graphics::Models::Text> subTitle = std::make_shared<Graphics::Models::Text>("De stealth game van 2020!", color, window_width / 2 - 175, (window_height / 4 * 3) - 50, 1, 50, 350, 0, path, true);
		std::shared_ptr<Graphics::Models::Text> play = std::make_shared<Graphics::Models::Text>("Play", color, window_width / 2 - 25, (window_height / 4 * 3) - 150, 1, 50, 50, 0, path, true);
		std::shared_ptr<Graphics::Models::Text> exit = std::make_shared<Graphics::Models::Text>("Exit", color, window_width / 2 - 25, (window_height / 4 * 3) - 225, 1, 50, 50, 0, path, true);
		_background = std::make_shared<Graphics::Models::Sprite>(0, 0, 0, window_height, window_width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::HORIZONTAL, true);
		_background->set_visible(true);
		_textures.push_back(_background);

		title->set_visible(true);
		_textures.push_back(title);
		subTitle->set_visible(true);
		_textures.push_back(subTitle);
		play->set_visible(true);
		_textures.push_back(play);
		exit->set_visible(true);
		_textures.push_back(exit);
	}

	void Views::HomeView::draw()
	{
		for (auto& t : _textures) {
			_graphics_controller.get()->add_texture(t);
		}
	}

	bool Views::HomeView::is_visible() const
	{
		return true;
	}

}