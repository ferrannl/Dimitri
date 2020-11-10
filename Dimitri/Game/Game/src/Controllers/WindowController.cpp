#include "WindowController.h"

namespace Game {
	Controllers::WindowController::WindowController()
	{
		_graphics_controller = std::make_unique<Graphics::Controllers::GraphicsController>();
	}

	void Controllers::WindowController::create_window(int height, int width)
	{
		if (_graphics_controller.get()->create_window("Dimitri", width, height) == NULL) {
			return;
		}

		_views.insert({ "credits", std::make_unique<Views::CreditsView>(_graphics_controller.get()->get_window().get()->get_width(),_graphics_controller.get()->get_window().get()->get_height()) });
		_views.insert({ "level", std::make_unique<Views::LevelView>(_graphics_controller.get()->get_window().get()->get_width(),_graphics_controller.get()->get_window().get()->get_height()) });

		draw_thread = std::thread(&Controllers::WindowController::draw, this);
	}

	void Controllers::WindowController::update(const Events::InputEvent& object)
	{
		switch (object.event_enum) {
		case Input::Enums::EventEnum::KEY_PRESS_C:
			clear_views();
			open_view("credits");
			open_view("fps");
			break;
		case Input::Enums::EventEnum::KEY_PRESS_L:
			clear_views();
			open_view("level");
			open_view("fps");
			break;
		case Input::Enums::EventEnum::KEY_PRESS_QUIT:
			exit(0);
		}
	}

	void Controllers::WindowController::draw()
	{
		while (true) {
			_graphics_controller.get()->clear_textures();
			for (auto& v : _views) {
				sleep_for(5ms);
				if (v.second.get()->is_open()) {
					for (auto& t : v.second.get()->get_textures()) {
						if (t.get()->is_visible()) {
							_graphics_controller.get()->add_texture(t);
						}
					}
				}
			}
			_graphics_controller.get()->update_window();
		}
	}

	void Controllers::WindowController::open_view(const std::string& view_name)
	{
		if (_views.find(view_name) != _views.end()) {
			_views[view_name].get()->set_open(true);
		}
	}

	void Controllers::WindowController::clear_views()
	{
		for (auto& v : _views) {
			v.second.get()->set_open(false);
		}

	}

	void Controllers::WindowController::set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures)
	{
		_views["level"].get()->set_textures(textures);
	}
}