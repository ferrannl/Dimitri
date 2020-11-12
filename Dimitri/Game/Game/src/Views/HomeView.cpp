#include "HomeView.h"

using namespace Game;

Views::HomeView::HomeView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : Views::View(graphics_controller)
{
	init_textures();
}

void Views::HomeView::init_textures()
{
	int window_width = 1080;
	int window_height = 720;
	std::vector <std::string> slogan = { "De stealth game van 2020!" };
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	Color color = { 255, 255, 255 };
	std::shared_ptr<Graphics::Models::Text> texture = std::make_shared<Graphics::Models::Text>("Dimitri", color, window_width / 2 - 100, 600, 10, 100, 200, 0, path);

	texture->set_visible(true);
	_textures.push_back(texture);

	int start_y = texture->get_y() - (texture->get_height() / 2);
	int step = 50;
	for (int i = 0; i < slogan.size(); i++) {
		int width = slogan[i].length() * 15;
		int x = window_width / 2 - width / 2;
		texture = std::make_shared<Graphics::Models::Text>(slogan[i], color, x, start_y - step * i, 10, 50, width, 0, path);
		texture->set_visible(true);
		_textures.push_back(texture);
	}
}
