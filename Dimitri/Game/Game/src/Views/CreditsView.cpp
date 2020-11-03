#include "CreditsView.h"
using namespace Game;

Views::CreditsView::CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : _graphics_controller{ graphics_controller }
{
	init_textures();
}

void Views::CreditsView::init_textures()
{
	// TODO: for now hardcoded: maybe add static const to Window or add properties if values are variable
	int window_width = 1080;
	int window_height = 720;
	std::vector <std::string> names = { "Koen Baudewijns", "Olav Gerritsen", "Ferran Hendriks", "Billy Nooijens", "Max Peters", "Xia de Visser" };
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	Color color = { 255, 255, 255 };
	std::shared_ptr<Graphics::Models::Text> texture = std::make_shared<Graphics::Models::Text>("Gemaakt door", color, 390, 500, 10, 70, 300, 0, path);
	texture->set_visible(true);
	_textures.push_back(texture);

	int start_y = 450;
	int step = 50;
	for (int i = 0; i < names.size(); i++) {
		int width = names[i].length() * 15;
		int x = window_width / 2 - width / 2;
		texture = std::make_shared<Graphics::Models::Text>(names[i], color, x, start_y - step * i, 10, 50, width, 0, path);
		texture->set_visible(true);
		_textures.push_back(texture);
	}
}

void Views::CreditsView::open()
{	
	is_open = true;
	for (auto texture : _textures) {
		_graphics_controller.get()->add_texture(texture);
	}
	draw_thread = std::thread(&Views::CreditsView::draw, this);
}

void Views::CreditsView::close()
{
	is_open = false;
	for (auto texture : _textures) {
		_graphics_controller.get()->remove_texture(texture);
	}
	draw_thread.join();
}

void Game::Views::CreditsView::draw()
{
	while (is_open) {
		sleep_for(5ms);
		_graphics_controller.get()->update_window();
	}
}


