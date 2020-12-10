#include "LevelTransitionView.h"
#include <ctime>

namespace Game {
	Views::LevelTransitionView::LevelTransitionView(const std::shared_ptr<Graphics::Controllers::GraphicsController>& graphics_controller) :
		View(graphics_controller), _pc_ctrl{ std::make_unique<Controllers::PhysicsCollisionController>() }, _fade_opacity{ 100 } {
		_tips = {
			"Door tegen een muur aan te springen, kan je nog een keer springen.",
			"Lampen kunnen uitgezet worden door een schakelaar over te halen.",
			"Probeer een highscore te halen door zo snel mogelijk een level te voltooien.",
		};
		init_textures();
	}

	void Views::LevelTransitionView::init_textures()
	{
		std::tuple<int, int> camera_pos = _graphics_controller.get()->get_camera_pos();
		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();
		int viewport_x = std::get<0>(camera_pos);
		int viewport_y = std::get<1>(camera_pos);
		_pc_ctrl->setup_world(window_height, window_width);

		_textures.push_back(std::make_shared<Graphics::Models::Sprite>(0, 0, 0, window_height, window_width, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false));
		float lamp_w = 100, lamp_h = 100, lamp_offset_h = 250;
		_textures.push_back((Models::Lamp{ window_width / 2 - lamp_w / 2 + viewport_x, window_height - lamp_offset_h + viewport_y, 2, lamp_h, lamp_w, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0, 0 } }).get_texture());
		float light_w = 400, light_h = 300, light_offset_h = 20;
		_lightbeam.reset(new Models::LightBeam{ window_width / 2 - light_w / 2 + viewport_x, window_height - lamp_offset_h - light_h + light_offset_h + viewport_y, 1, light_h, light_w, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0, 0 } });
		_textures.push_back(_lightbeam->get_texture());
		float tile_x = viewport_x, tile_w = 30, tile_h = 30;
		while (tile_x <= window_width + viewport_x) {
			_textures.push_back((Models::Floor{ tile_x, window_height - lamp_offset_h + lamp_h + viewport_y, 1, tile_h, tile_w, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0, 0 } }).get_texture());
			Models::Floor ground{ tile_x, _lightbeam->get_y() - tile_h + viewport_y, 1, tile_h, tile_w, Enums::DirectionEnum::NONE, Graphics::Models::Center{ 0, 0 } };
			_textures.push_back(ground.get_texture());
			_pc_ctrl->load_shape(ground.get_shape());
			tile_x += tile_w;
		}
		float player_h = 120, player_w = 120;
		_player.reset(new Models::Player(viewport_x, _lightbeam->get_y() + viewport_y, 3, player_h, player_w, Enums::DirectionEnum::RIGHT, Graphics::Models::Center{ 0, 0 }));
		for (auto t : _player->get_all_textures()) {
			_textures.push_back(t);
		}
		_pc_ctrl->load_shape(_player->get_shape());
	}

	void Views::LevelTransitionView::update()
	{
		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();
		int viewport_x = std::get<0>(_graphics_controller.get()->get_camera_pos());

		++_counter;

		// lamp flickering
		if (_player->get_x() + _player->get_width() >= window_width / 2 - _lightbeam->get_width() / 2
			&& _player->get_x() <= window_width / 2 + _lightbeam->get_width() / 2) {
			_lightbeam->get_texture()->set_visible(false);
		}
		else if (rand() % 8 == 0) {
			if (_lightbeam->get_texture()->is_visible()) {
				_lightbeam->get_texture()->set_visible(false);
			}
			else {
				_lightbeam->get_texture()->set_visible(true);
			}
		}

		// move the player
		_player->get_shape()->move_x(1);
		_pc_ctrl->simulate();
		if (_counter % 5 == 0) {
			_player->update();
			_player->update_object();
			_player->update_state();
		}

		// fade in and out effect
		if (_counter % 21 &&
			(_fade_opacity > 0 || (_fade_opacity <= 0 && _player->get_x() >= window_width - _player->get_width() - 100))) {
			if (_fade_opacity < -100) {
				set_active(false);
				close();
			}
			if (_mask != nullptr) {
				_graphics_controller->remove_texture(_mask);
			}
			_mask.reset(new Graphics::Models::Sprite{ 0, 0, 10, static_cast<float>(window_height), static_cast<float>(window_width), 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/black_bg.png" }, Graphics::Enums::FlipEnum::NONE, true, Graphics::Models::Center{ 0,0 }, false, abs(_fade_opacity) });
			_graphics_controller->add_texture(_mask);
			_fade_opacity--;
		}
	}

	void Views::LevelTransitionView::open()
	{
		std::tuple<int, int> camera_pos = _graphics_controller.get()->get_camera_pos();
		int window_width = _graphics_controller->get_window()->get_width();
		int window_height = _graphics_controller->get_window()->get_height();
		int viewport_x = std::get<0>(camera_pos);
		int viewport_y = std::get<1>(camera_pos);
		int tile_h = 30;

		_counter = 0;
		_fade_opacity = 100;

		// change tip
		srand((unsigned int)time(NULL));
		std::string tip = _tips[rand() % _tips.size()];
		int tip_w = tip.length() * 10;
		int tip_h = 20;
		std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" };
		Graphics::Models::Color color = { 255, 255, 255 };
		_tip.reset(new Graphics::Models::Text(tip, color, window_width / 2 - tip_w / 2 + viewport_x, _lightbeam->get_y() - tile_h + ((tile_h - tip_h) / 2) + viewport_y, 3, tip_h, tip_w, 0, path, true, Graphics::Models::Center{ 0, 0 }, false));
		_textures.push_back(_tip);

		// set player in original pos
		_player->get_shape()->set_x(viewport_x);
		_player->update();
		_pc_ctrl->destroy_shape(_player->get_shape());
		_pc_ctrl->load_shape(_player->get_shape());

		View::open();
	}

	void Views::LevelTransitionView::close()
	{
		_textures.push_back(_mask);
		View::close();
		_textures.erase(std::remove(_textures.begin(), _textures.end(), _mask), _textures.end());
		_textures.erase(std::remove(_textures.begin(), _textures.end(), _tip), _textures.end());
		_counter = -1;
	}

	bool Views::LevelTransitionView::is_visible() const
	{
		return true;
	}
}

