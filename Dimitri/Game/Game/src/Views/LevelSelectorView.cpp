#include "LevelSelectorView.h"
namespace Game {
	Views::LevelSelectorView::LevelSelectorView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller)
	{
		init_textures();
	}

	void Views::LevelSelectorView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		Graphics::Models::Color color = { 255, 255, 255 };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, window_height, window_width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/levels/level_select0.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }, true));
	}

	bool Views::LevelSelectorView::is_visible() const
	{
		return true;
	}

}

