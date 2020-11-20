#include "CreditsView.h"

namespace Game {
	Views::CreditsView::CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::CreditsView::init_textures()
	{
		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();
		std::vector <std::string> names = { "Koen Baudewijns", "Olav Gerritsen", "Ferran Hendriks", "Billy Nooijens", "Max Peters", "Xia de Visser" };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Color color = { 255, 255, 255 };
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Gemaakt door", color, 390, 500, 10, 70, 300, 0, path, true));

		int start_y = 450;
		int step = 50;
		for (int i = 0; i < names.size(); i++) {
			int width = names[i].length() * 15;
			int x = window_width / 2 - width / 2;
			_textures.push_back(std::make_shared<Graphics::Models::Text>(names[i], color, x, start_y - step * i, 10, 50, width, 0, path, true));
		}
	}

	bool Views::CreditsView::is_visible() const
	{
		return true;
	}

}


