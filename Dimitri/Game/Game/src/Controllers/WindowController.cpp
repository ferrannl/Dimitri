#include "WindowController.h"

namespace Game {
	Controllers::WindowController::WindowController()
	{
		_graphics_controller = std::make_shared<Graphics::Controllers::GraphicsController>();
	}

	void Controllers::WindowController::create_window(int height, int width)
	{
		if (_graphics_controller.get()->create_window("Dimitri", width, height) == NULL) {
			return;
		}

		_views.insert({ "credits", std::make_unique<Views::CreditsView>(_graphics_controller) });
		_views.insert({ "level", std::make_unique<Views::LevelView>(_graphics_controller) });
		_views.insert({ "fps", std::make_unique<Views::FpsView>(_graphics_controller) });

		draw_thread = std::thread(&Controllers::WindowController::draw, this);
	}

	void Controllers::WindowController::update(const Events::InputEvent& object)
	{
		bool fps_open = _views["fps"].get()->is_open();
		switch (object.event_enum) {
		case Input::Enums::EventEnum::KEY_PRESS_C:
			clear_views();
			open_view("credits");
			if (fps_open) {
				open_view("fps");
			}
			break;
		case Input::Enums::EventEnum::KEY_PRESS_L:
			clear_views();
			open_view("level");
			if (fps_open) {
				open_view("fps");
			}
			break;
		case Input::Enums::EventEnum::KEY_PRESS_QUIT:
			exit(0);
		}
	}

	void Controllers::WindowController::draw()
	{
		while (true) {
			sleep_for(5ms);
			_graphics_controller.get()->clear_textures();
			for (auto& v : _views) {
				if (v.second.get()->is_open()) {
					v.second.get()->draw();
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