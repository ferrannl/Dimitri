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
		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, bg_height, bg_width, 0, bg_path, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0, 0 }));

		std::vector <std::string> gameplay = { "Dimitri moet", "ongezien infiltreren", "in de geheime", "russische basis" };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/TravelingTypewriter.ttf" };
		Graphics::Models::Color color = { 0, 0, 0 };

		_textures.push_back(std::make_shared<Graphics::Models::Text>("F", color, bg_width / 4 - 135, bg_height / 4 * 3, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("H", color, bg_width / 4 - 135, bg_height / 4 * 2, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("E", color, bg_width / 4 - 135, bg_height / 4 - 10, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Esc", color, bg_width / 3 - 22, bg_height / 4 * 3, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));

		_textures.push_back(std::make_shared<Graphics::Models::Text>("W", color, bg_width / 2 - 142, bg_height / 4 + 70, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("A", color, bg_width / 2 - 222, bg_height / 4 - 10, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("D", color, bg_width / 2 - 70, bg_height / 4 - 10, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }));

		color = { 255, 255, 255 };

		int start_y = 425;
		int step = 50;
		for (int i = 0; i < gameplay.size(); i++) {
			int width = gameplay[i].length() * 15;
			int x = (bg_width / 4) * 3 - width / 2;
			_textures.push_back(std::make_shared<Graphics::Models::Text>(gameplay[i], color, x + 75, start_y - step * i, 10, 50, width, 0, path, true, Graphics::Models::Center{ 0, 0 }));
		}
	}

	bool Views::HelpView::is_visible() const
	{
		return true;
	}
}
