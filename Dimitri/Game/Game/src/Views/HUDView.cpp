#include "HUDView.h"

namespace Game {
	Views::HUDView::HUDView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) 
	{
		init_textures();
	}

	void Views::HUDView::init_textures()
	{
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		int width = 395;
		int height = 226;

		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/lives.png" };
		Graphics::Models::Color color{ 255, 255, 255 };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>( 0, window_height - height, 100, height, width, 0, path, Graphics::Enums::FlipEnum::NONE,true, Graphics::Models::Center{ 0, 0 }, false));
	}

	void Views::HUDView::update()
	{
		int size = 45;
		if (_textures.at(1)->get_width() != size) {
			_textures.at(1)->set_x(230);
			_textures.at(1)->set_y(_graphics_controller.get()->get_window().get()->get_height() - 70);
			_textures.at(1)->set_width(size);
			_textures.at(1)->set_height(size);

			_textures.at(2)->set_x(287);
			_textures.at(2)->set_y(_graphics_controller.get()->get_window().get()->get_height() - 70);
			_textures.at(2)->set_width(size);
			_textures.at(2)->set_height(size);
		}
	}

	bool Views::HUDView::is_visible() const
	{
		return true;
	}

	void Views::HUDView::close() {
		View::close();
		_textures.clear();
	}
}