#include "HUDView.h"

namespace Game {
	Views::HUDView::HUDView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) 
	{
		init_textures();
	}

	void Views::HUDView::init_textures()
	{
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		int width = 250;
		int height = 143;

		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/hud/lives.png" };
		Graphics::Models::Color color{ 255, 255, 255 };
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>( 0, window_height - height, 100, height, width, 0, path, Graphics::Enums::FlipEnum::NONE,true, Graphics::Models::Center{ 0, 0 }, false));
	}

	void Views::HUDView::update()
	{
		int size = 28;
		int x1 = 175;
		int x2 = 37;
		for (auto texture : _textures) {
			if(texture->get_path() == Utility::Helpers::get_base_path() + std::string{ "/assets/images/hud/jump.png" })
			if (texture->get_width() != size) {
				texture->set_x(x1);
				texture->set_y(_graphics_controller.get()->get_window().get()->get_height() - 40);
				texture->set_width(size);
				texture->set_height(size);
				x1 += x2;
			}
		}
		
	}

	bool Views::HUDView::is_visible() const
	{
		return true;
	}

	void Views::HUDView::close() {
		View::close();
	}
}