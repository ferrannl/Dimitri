#include "HomeView.h"
#include "../Models/Button.h"

namespace Game {
	Views::HomeView::HomeView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) : View(graphics_controller) {
		init_textures();
	}

	void Views::HomeView::init_textures()
	{
		int window_width = _graphics_controller.get()->get_window().get()->get_width();
		int window_height = _graphics_controller.get()->get_window().get()->get_height();
		Color color = { 255, 255, 255 };
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		std::shared_ptr<Graphics::Models::Text> title = std::make_shared<Graphics::Models::Text>("DIMITRI", color, window_width / 2 - 100, (window_height / 4 * 3), 10, 80, 200, 0, path);
		std::vector <std::string> subtitle = { "De stealth game van 2020!" };
		std::vector <std::string> play = { "new game" };
		_buttonNewGame = std::make_shared<Game::Models::Button>(200, 200, 1, 50, 50, Game::Enums::StateEnum::RIGHT);
		//Game::Models::Button::Button(int x, int y, int z, int height, int width) : Game::Models::IObject(x, y, z, height, width)

		std::vector <std::string> exit = { "exit" };
		std::shared_ptr<Game::Models::Button> exitNewGame = std::make_shared<Game::Models::Button>();


		_background = std::make_shared<Graphics::Models::Sprite>(0, 0, 0, 720, 1080, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::HORIZONTAL);
		_background->set_visible(true);
		_textures.push_back(_background);

		title->set_visible(true);
		_textures.push_back(title);

		std::string bg_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" };
		int start_y = title->get_y() - (title->get_height() / 2);
		int step = 50;
		for (int i = 0; i < subtitle.size(); i++) {
			int width = subtitle[i].length() * 15;
			int x = window_width / 2 - width / 2;
			title = std::make_shared<Graphics::Models::Text>(subtitle[i], color, x, start_y - step * i, 10, 50, width, 0, path);
			title->set_visible(true);
			_textures.push_back(title);
		}
		start_y -= step * 2;
		for (int i = 0; i < play.size(); i++) {
			int width = play[i].length() * 15;
			int x = window_width / 2 - width / 2;
			title = std::make_shared<Graphics::Models::Text>(play[i], color, x, start_y - step * i, 10, 50, width, 0, path);
			title->set_visible(true);
			_textures.push_back(title);
		}
		start_y -= step * 2;
		for (int i = 0; i < exit.size(); i++) {
			int width = exit[i].length() * 15;
			int x = window_width / 2 - width / 2;
			title = std::make_shared<Graphics::Models::Text>(exit[i], color, x, start_y - step * i, 10, 50, width, 0, path);
			title->set_visible(true);
			_textures.push_back(title);
		}
	}

	void Views::HomeView::draw()
	{
		for (auto& t : _textures) {
			_graphics_controller.get()->add_texture(t);
		}
	}

	bool Views::HomeView::is_visible() const
	{
		return true;
	}

}