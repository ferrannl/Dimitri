#include "WindowController.h"
#include <algorithm>

namespace Game {
	Controllers::WindowController::WindowController()
	{
		_graphics_controller = std::make_shared<Graphics::Controllers::GraphicsController>();
	}

	void Controllers::WindowController::create_window(int height, int width)
	{
		_height = height;
		_width = width;

		if (_graphics_controller->create_window("Dimitri", height, width) == NULL) {
			return;
		}

		_views.insert({ "credits", std::make_unique<Views::CreditsView>(_graphics_controller) });
		_views.insert({ "help", std::make_unique<Views::HelpView>(_graphics_controller) });
		_views.insert({ "home", std::make_unique<Views::HomeView>(_graphics_controller) });
		_views.insert({ "level", std::make_unique<Views::LevelView>(_graphics_controller) });
		_views.insert({ "fps", std::make_unique<Views::FpsView>(_graphics_controller) });
		_views.insert({ "win_level", std::make_unique<Views::WinLevelView>(_graphics_controller) });
		_views.insert({ "game_over_level", std::make_unique<Views::GameOverLevelView>(_graphics_controller) });
		_views.insert({ "pause_level", std::make_unique<Views::PauseLevelView>(_graphics_controller) });
		open_view("home");
		toggle_view_visibility("home");


		draw_thread = std::thread(&Controllers::WindowController::draw, this);
	}

	void Controllers::WindowController::draw()
	{
		while (true) {
			sleep_for(5ms);
			_graphics_controller->clear_textures();
			for (auto& v : _views) {
				if (v.second->is_active() && v.second->is_visible()) {
					v.second->draw();
				}
			}
			_graphics_controller->update_window();
		}
	}

	void Controllers::WindowController::open_view(const std::string& view_name)
	{
		_views[view_name]->set_active(true);
	}

	bool Controllers::WindowController::is_active(const std::string& view_name)
	{
		return _views[view_name]->is_active();
	}

	void Controllers::WindowController::clear_views()
	{
		for (auto& v : _views) {
			v.second->set_active(false);
		}
	}

	void Controllers::WindowController::toggle_view_visibility(const std::string& view_name)
	{
		Views::View* view = _views[view_name].get();
		view->set_visible(!view->is_visible());
	}

	void Controllers::WindowController::set_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& view_name)
	{
		_views[view_name]->set_textures(textures);
	}
	void Controllers::WindowController::add_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures, const std::string& view_name)
	{
		_views[view_name]->add_textures(textures);
	}

	void Game::Controllers::WindowController::set_camera_pos(int x, int y)
	{
		_graphics_controller->set_camera_pos(x, y);
	}

	void Controllers::WindowController::set_camera_pos_based_on(const std::shared_ptr<Game::Models::IObject> object)
	{
		int x = (object->get_x() + object->get_width() / 2) - get_window_width() / 2;
		int y = (object->get_y() + object->get_height() / 2) - get_window_height() / 2;
		set_camera_pos(x, y);
	}

	void Game::Controllers::WindowController::set_scene_size(int height, int width)
	{
		_graphics_controller->set_scene_size(height, width);
	}

	int Game::Controllers::WindowController::get_window_height() const
	{
		return _height;
	}

	int Game::Controllers::WindowController::get_window_width() const
	{
		return _width;
	}

}
