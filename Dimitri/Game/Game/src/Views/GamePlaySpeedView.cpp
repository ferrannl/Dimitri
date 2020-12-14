#include "GamePlaySpeedView.h"

namespace Game {
	Views::GamePlaySpeedView::GamePlaySpeedView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller)
	{
	}

	void Views::GamePlaySpeedView::update()
	{
		close();
		Graphics::Models::Color color{ 255, 255, 255 };
		path_text = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		_textures.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(_graphics_controller->get_speed()).substr(0,3), color, 160, 595, 100, 30, 35, 0, path_text, true, Graphics::Models::Center{ 0,0 }, false));
		open();
	}

	bool Views::GamePlaySpeedView::is_visible() const
	{
		return true;
	}

	void Views::GamePlaySpeedView::close() {
		View::close();
		_textures.clear();
	}
}