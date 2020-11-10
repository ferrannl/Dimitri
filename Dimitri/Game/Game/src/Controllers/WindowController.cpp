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
		open_view("fps");
		toggle_view_visibility("fps");

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
		case Input::Enums::EventEnum::KEY_PRESS_F:
			toggle_view_visibility("fps");
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
				if (v.second->is_active() && v.second->is_visible()) {
					v.second->draw();
				}
			}
			_graphics_controller.get()->update_window();
		}
	}

	void Controllers::WindowController::open_view(const std::string& view_name)
	{
		_views[view_name].get()->set_active(true);
	}

	void Controllers::WindowController::clear_views()
	{
		for (auto& v : _views) {
			v.second.get()->set_active(false);
		}
	}

	void Controllers::WindowController::toggle_view_visibility(const std::string& view_name)
	{
		Views::View* view = _views[view_name].get();
		view->set_visible(!view->is_visible());
	}

	void Controllers::WindowController::set_level_textures(std::vector<std::shared_ptr<Graphics::Models::Texture>> textures)
	{
		_views["level"].get()->set_textures(textures);
	}
}