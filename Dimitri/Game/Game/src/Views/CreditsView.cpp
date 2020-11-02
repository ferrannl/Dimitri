#include "CreditsView.h"
using namespace Game;

Views::CreditsView::CreditsView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : _graphics_controller{ graphics_controller }
{
	init_textures();
}

void Game::Views::CreditsView::init_textures()
{
	// TODO: for now hardcoded: maybe add static const to Window or add properties if values are variable
	int window_width = 1080;
	int window_height = 720;
	std::vector <std::string> names = { "Koen Baudewijns", "Olav Gerritsen", "Ferran Hendriks", "Billy Nooijens", "Max Peters", "Xia de Visser" };
	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
	Color color = { 255, 255, 255 };
	_textures.push_back(std::make_shared<Graphics::Models::Text>("Gemaakt door", color, 390, 500, 1, 70, 300, 0, path));

	int start_y = 450;
	int step = 50;
	for (int i = 0; i < names.size(); i++) {
		int width = names[i].length() * 15;
		int x = window_width / 2 - width / 2;
		_textures.push_back(std::make_shared<Graphics::Models::Text>(names[i], color, x, start_y - step * i, 1, 50, width, 0, path));
	}
}

void Game::Views::CreditsView::open()
{	
	for (auto texture : _textures) {
		_graphics_controller.get()->add_texture(texture);
	}
	_graphics_controller.get()->update_window();
	is_open = true;
}



void Game::Views::CreditsView::close()
{
	for (auto texture : _textures) {
		_graphics_controller.get()->remove_texture(texture);
	}
	_graphics_controller.get()->update_window();
	is_open = false;
}
