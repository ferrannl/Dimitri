#include "HelpView.h"

namespace Game {
	Views::HelpView::HelpView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::HelpView::init_textures()
	{
		int window_width = 1080;
		int window_height = 720;
		std::vector <std::string> controls = { "Links: Beweeg naar links", "Rechts: Beweeg naar rechts", "Links: Beweeg naar links", "L: laad level", "C: Open credits scherm", "E: Interactie" };
		std::vector <std::string> gameplay = { "Dimitri moet", "ongezien infiltreren", "in de geheime", "russische basis" };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Color color = { 255, 255, 255 };
		std::shared_ptr<Graphics::Models::Text> texture = std::make_shared<Graphics::Models::Text>("Helpscherm", color, 390, 600, 10, 70, 240, 0, path);
		std::shared_ptr<Graphics::Models::Text> controls_header = std::make_shared<Graphics::Models::Text>("Knoppen", color, window_width / 4 - 75, 500, 10, 60, 150, 0, path);
		std::shared_ptr<Graphics::Models::Text> play_header = std::make_shared<Graphics::Models::Text>("Doel", color, (window_width / 4) * 3 - 45, 500, 10, 60, 90, 0, path);

		texture->set_visible(true);
		controls_header->set_visible(true);
		play_header->set_visible(true);
		_textures.push_back(texture);
		_textures.push_back(controls_header);
		_textures.push_back(play_header);

		int start_y = 425;
		int step = 50;
		for (int i = 0; i < controls.size(); i++) {
			int width = controls[i].length() * 15;
			int x = window_width / 4 - width / 2;
			texture = std::make_shared<Graphics::Models::Text>(controls[i], color, x, start_y - step * i, 10, 50, width, 0, path);
			texture->set_visible(true);
			_textures.push_back(texture);
		}

		for (int i = 0; i < gameplay.size(); i++) {
			int width = gameplay[i].length() * 15;
			int x = (window_width / 4) * 3 - width / 2;
			texture = std::make_shared<Graphics::Models::Text>(gameplay[i], color, x, start_y - step * i, 10, 50, width, 0, path);
			texture->set_visible(true);
			_textures.push_back(texture);
		}
	}

	void Views::HelpView::draw()
	{
		for (auto& t : _textures) {
			_graphics_controller.get()->add_texture(t);
		}
	}

	bool Views::HelpView::is_visible() const
	{
		return true;
	}

}


