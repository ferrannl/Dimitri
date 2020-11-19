#include "HelpView.h"

namespace Game {
	Views::HelpView::HelpView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::HelpView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		std::vector <std::string> controls = { "Links: Beweeg naar links", "Rechts: Beweeg naar rechts", "Omhoog: Spring", "L: Laad level", "C: Open credits scherm", "E: Interactie", "F: FPS aan-/uitzetten", "P: Het level pauzeren" };
		std::vector <std::string> gameplay = { "Dimitri moet", "ongezien infiltreren", "in de geheime", "russische basis" };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Color color = { 255, 255, 255 };

		_textures.push_back(std::make_shared<Graphics::Models::Text>("Helpscherm", color, (window_width / 2) - 120, 600, 10, 70, 240, 0, path, true));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Knoppen", color, window_width / 4 - 75, 500, 10, 60, 150, 0, path, true));
		_textures.push_back(std::make_shared<Graphics::Models::Text>("Doel", color, (window_width / 4) * 3 - 45, 500, 10, 60, 90, 0, path, true));

		int start_y = 425;
		int step = 50;
		for (int i = 0; i < controls.size(); i++) {
			int width = controls[i].length() * 15;
			int x = window_width / 4 - width / 2;
			_textures.push_back(std::make_shared<Graphics::Models::Text>(controls[i], color, x, start_y - step * i, 10, 50, width, 0, path, true));
		}

		for (int i = 0; i < gameplay.size(); i++) {
			int width = gameplay[i].length() * 15;
			int x = (window_width / 4) * 3 - width / 2;
			_textures.push_back(std::make_shared<Graphics::Models::Text>(gameplay[i], color, x, start_y - step * i, 10, 50, width, 0, path, true));
		}
	}

	bool Views::HelpView::is_visible() const
	{
		return true;
	}

}


