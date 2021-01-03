#include "OpenHighscoreViewCommand.h"
#include <src/Models/Texture.h>
namespace Game {
	namespace Commands {
		Game::Commands::OpenHighscoreViewCommand::OpenHighscoreViewCommand(const std::shared_ptr<Controllers::MainController> main_controller) : Command(main_controller) {}


		void Game::Commands::OpenHighscoreViewCommand::execute(int param)
		{
			auto l_mgr = _main_controller->get_highscore_manager();
			auto w_ctrl = _main_controller->get_window_controller();
			auto ls_ctrl = _main_controller->get_level_selector_controller();
			auto i_ctrl = _main_controller->get_input_controller();
			std::vector<std::shared_ptr<Graphics::Models::Texture>> t{};
			
			int window_width = w_ctrl->get_graphics_controller()->get_window().get()->get_width();
			int window_height = w_ctrl->get_graphics_controller()->get_window().get()->get_height();
			std::string bg_path = Utility::Helpers::get_base_path() + std::string{ "/assets/images/records.png" };
			Graphics::Models::Color color = { 255, 255, 255 };
			std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/TravelingTypewriter.ttf" };
			int place_margin = 0;

			int x_offset = 0;
			int y_offset = 0;
			
			//tutorial
			t.push_back(std::make_shared<Graphics::Models::Text>("Tutorial", color, 470 + x_offset, 550+y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
			
			int text_y_offset = -50;
			int text_x_offset = -50;
			for (int i = 1; i < 6; i++) {
				t.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(i) + ".", color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
				text_y_offset += -40;
			}

			std::vector<std::string> highscores = _main_controller->get_highscore()->get_highscores(0);

			text_y_offset = -50;
			text_x_offset = 30;
			for (int i = 0; i < 5; i++) {
				if (highscores.size() > i) {
					t.push_back(std::make_shared<Graphics::Models::Text>(highscores.at(i).substr(0,6), color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
					text_y_offset += -40;
				}
				else {
					break;
				}
			}

			//level 1
			x_offset = 240;
			y_offset = 0;

			t.push_back(std::make_shared<Graphics::Models::Text>("Level 1", color, 470 + x_offset, 550 + y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
			text_y_offset = -50;
			text_x_offset = -50;
			for (int i = 1; i < 6; i++) {
				t.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(i) + ".", color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
				text_y_offset += -40;
			}
			highscores = _main_controller->get_highscore()->get_highscores(1);

			text_y_offset = -50;
			text_x_offset = 30;
			for (int i = 0; i < 5; i++) {
				if (highscores.size() > i) {
					t.push_back(std::make_shared<Graphics::Models::Text>(highscores.at(i).substr(0, 6), color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
					text_y_offset += -40;
				}
				else {
					break;
				}
			}
			//level 2
			x_offset = 0;
			y_offset = -270;

			t.push_back(std::make_shared<Graphics::Models::Text>("Level 2", color, 470 + x_offset, 550 + y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
			text_y_offset = -50;
			text_x_offset = -50;
			for (int i = 1; i < 6; i++) {
				t.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(i) + ".", color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
				text_y_offset += -40;
			}
			highscores = _main_controller->get_highscore()->get_highscores(2);

			text_y_offset = -50;
			text_x_offset = 30;
			for (int i = 0; i < 5; i++) {
				if (highscores.size() > i) {
					t.push_back(std::make_shared<Graphics::Models::Text>(highscores.at(i).substr(0, 6), color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
					text_y_offset += -40;
				}
				else {
					break;
				}
			}
			//level 3
			x_offset = 240;
			y_offset = -270;

			t.push_back(std::make_shared<Graphics::Models::Text>("Level 3", color, 470 + x_offset, 550 + y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
			text_y_offset = -50;
			text_x_offset = -50;
			for (int i = 1; i < 6; i++) {
				t.push_back(std::make_shared<Graphics::Models::Text>(std::to_string(i) + ".", color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 40, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
				text_y_offset += -40;
			}
			highscores = _main_controller->get_highscore()->get_highscores(3);

			text_y_offset = -50;
			text_x_offset = 30;
			for (int i = 0; i < 5; i++) {
				if (highscores.size() > i) {
					t.push_back(std::make_shared<Graphics::Models::Text>(highscores.at(i).substr(0, 6), color, 470 + x_offset + text_x_offset, 550 + y_offset + text_y_offset, 1, 40, 100, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
					text_y_offset += -40;
				}
				else {
					break;
				}
			}

			w_ctrl->set_textures(t, Enums::ViewEnum::HIGHSCORE);

			if (w_ctrl->is_active(Enums::ViewEnum::LEVEL_SELECTOR)) {
				i_ctrl->unsubscribe(ls_ctrl);
				w_ctrl->clear_views();
				l_mgr->load_buttons();
				w_ctrl->add_textures(l_mgr->get_textures(), Enums::ViewEnum::HIGHSCORE);
				w_ctrl->open_view(Enums::ViewEnum::HIGHSCORE);
				w_ctrl->set_scene_size(w_ctrl->get_window_height(), w_ctrl->get_window_width());
				i_ctrl->subscribe(l_mgr);
			}
		}
	}
}
