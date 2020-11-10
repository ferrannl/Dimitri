#include "CreditsView.h"

namespace Game {
	Views::CreditsView::CreditsView(float width, float height) : View(width, height) {
		init_textures();
	}

	void Views::CreditsView::init_textures()
	{
		int window_width = get_width();
		int window_height = get_height();
		std::vector <std::string> names = { "Koen Baudewijns", "Olav Gerritsen", "Ferran Hendriks", "Billy Nooijens", "Max Peters", "Xia de Visser" };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Color color = { 255, 255, 255 };
		std::shared_ptr<Graphics::Models::Text> texture = std::make_shared<Graphics::Models::Text>("Gemaakt door", color, 390, 500, 10, 70, 300, 0, path);
		texture->set_visible(true);
		add_texture(texture);

		int start_y = 450;
		int step = 50;
		for (int i = 0; i < names.size(); i++) {
			int width = names[i].length() * 15;
			int x = window_width / 2 - width / 2;
			texture = std::make_shared<Graphics::Models::Text>(names[i], color, x, start_y - step * i, 10, 50, width, 0, path);
			texture->set_visible(true);
			add_texture(texture);
		}
	}

	
}


