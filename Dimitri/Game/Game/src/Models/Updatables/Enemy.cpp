#include "Enemy.h"
#include "../../Controllers/LevelController.h"

Game::Models::Enemy::Enemy(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center, int area_left, int area_right, int area_top, int area_bottom) : Game::Models::Updatable(x,y,z,height,width,state,center)
{
	_lastx = x;
	_base_x = x;
	_area_left = area_left;
	_area_right = area_right;
	_area_top = area_top;
	_area_bottom = area_bottom;
	_lasty = y;
	_moving_direction = { 1 };
	_direction = Enums::DirectionEnum::NONE;
	_standstill = false;
	_playing_alarm = false;
	_playing_adaptive = false;
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Enemy::initialize_textures()
{
	add_texture(Game::Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_000.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_001.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE3, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_002.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE4, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_003.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE5, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_004.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE6, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_005.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE7, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_006.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::IDLE8, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_idle/Enemy_idle_007.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));


	add_texture(Game::Enums::AnimateEnum::WALK1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_000.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_001.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK3, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_002.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK4, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_003.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK5, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_004.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK6, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_005.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK7, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_006.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));
	add_texture(Game::Enums::AnimateEnum::WALK8, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/enemy_walk/Enemy_walk_007.png" }, Graphics::Enums::FlipEnum::NONE, false, _center, true));

	_animatestate = Enums::AnimateEnum::IDLE1;
	get_texture()->set_visible(true);
}

void Game::Models::Enemy::update_object(Controllers::LevelController* ctrl)
{
	bool left = (_base_x - _area_left < (ctrl->get_level()->get_player()->get_x() + ctrl->get_level()->get_player()->get_width()));
	bool right = ((_base_x + _width) + (_area_right) > (ctrl->get_level()->get_player()->get_x()));
	bool top = (_y + _area_top > (ctrl->get_level()->get_player()->get_y()));
	bool bottom = (_y - _area_bottom < (ctrl->get_level()->get_player()->get_y() + ctrl->get_level()->get_player()->get_height()));

	if (left && right && top && bottom)
	{
		play_alarm(ctrl);
		chase_player(ctrl);
	}
	else if (!_standstill) {
		play_adaptive(ctrl);
		walk_in_area(ctrl);
	}
	else {
		idle();
	}

	if (_direction == Enums::DirectionEnum::LEFT) {
		get_texture()->set_flip_status(Graphics::Enums::FlipEnum::HORIZONTAL);
	}
	else {
		get_texture()->set_flip_status(Graphics::Enums::FlipEnum::NONE);
	}
	if (!ctrl->get_cheats_settings()->get_invincible()) {
		if (_shape->check_square_collision(ctrl->get_level()->get_player()->get_shape()) && get_texture()->is_visible()) {
			ctrl->set_state(Enums::LevelStateEnum::GAME_OVER);
		}
	}
}

void Game::Models::Enemy::walk_in_area(Controllers::LevelController* ctrl)
{
	walk();

	if (_x >= _base_x + _area_right) {
		_direction = Enums::DirectionEnum::LEFT;
		_moving_direction = -1;
	}
	else if (_x <= _base_x - _area_left) {
		_direction = Enums::DirectionEnum::RIGHT;
		_moving_direction = 1;
	}
	if (_moving_direction == 1)
	{
		_direction = Enums::DirectionEnum::RIGHT;
	}
	else {
		_direction = Enums::DirectionEnum::LEFT;
	}

	_shape->move_x(_moving_direction, 0.5);
}

void Game::Models::Enemy::chase_player(Controllers::LevelController* ctrl)
{
	bool bounds_right = (_x > _base_x - _area_left);
	bool bounds_left = (_x < _base_x + _area_right);

	walk();

	if (_x < (ctrl->get_level()->get_player()->get_x()) && bounds_left) {
		_shape->move_x(1, 1);
		_direction = Enums::DirectionEnum::RIGHT;
	}
	else if (bounds_right)
	{
		_shape->move_x(-1, 1);
		_direction = Enums::DirectionEnum::LEFT;
	}
}

void Game::Models::Enemy::play_alarm(Controllers::LevelController* ctrl)
{
	if (!_playing_alarm) {
		ctrl->get_level()->play_music("danger");
		ctrl->get_level()->stop_music("enemynear");
		_playing_alarm = true;
		_playing_adaptive = false;
	}
}

void Game::Models::Enemy::play_adaptive(Controllers::LevelController* ctrl)
{
	if (_playing_alarm) {
		ctrl->get_level()->stop_music("danger");
		_playing_alarm = false;
	}

	int difx = ctrl->get_level()->get_player()->get_x() - _x;
	int dify = ctrl->get_level()->get_player()->get_y() - _y;

	int xbound = 500;
	int ybound = 400;

	if (abs(difx) < xbound && abs(dify) < ybound) {
		if (!_playing_adaptive) {
			ctrl->get_level()->play_music("enemynear");
			_playing_adaptive = true;
		}

		int new_vol = ((xbound - abs(difx)) / 5);
		ctrl->get_level()->volume_control("enemynear", new_vol);
	}
	else if (_playing_adaptive) {
		ctrl->get_level()->stop_music("enemynear");
		_playing_adaptive = false;
	};
}

void Game::Models::Enemy::update_state()
{
	if (_lasty < _y) {
		set_state(Enums::StateEnum::JUMPING);
	}
	else if (_lasty > _y) {
		set_state(Enums::StateEnum::FALLING);
	}
	else if (_x) {
		set_state(Enums::StateEnum::WALKING);
	}
	else if (_lastx == _x && _lasty == _y) {
		set_state(Enums::StateEnum::IDLE);
	}

	_lastx = _x;
	_lasty = _y;
}

void Game::Models::Enemy::walk()
{
	if (_animatestate != Enums::AnimateEnum::WALK1 &&
		_animatestate != Enums::AnimateEnum::WALK2 &&
		_animatestate != Enums::AnimateEnum::WALK3 &&
		_animatestate != Enums::AnimateEnum::WALK4 &&
		_animatestate != Enums::AnimateEnum::WALK5 &&
		_animatestate != Enums::AnimateEnum::WALK6 &&
		_animatestate != Enums::AnimateEnum::WALK7 &&
		_animatestate != Enums::AnimateEnum::WALK8) {
		set_animationstate(Enums::AnimateEnum::WALK1);
	}

	if (_animatestate == Game::Enums::AnimateEnum::WALK1) {
		set_animationstate(Game::Enums::AnimateEnum::WALK2);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK2) {
		set_animationstate(Game::Enums::AnimateEnum::WALK3);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK3) {
		set_animationstate(Game::Enums::AnimateEnum::WALK4);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK4) {
		set_animationstate(Game::Enums::AnimateEnum::WALK5);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK5) {
		set_animationstate(Game::Enums::AnimateEnum::WALK6);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK6) {
		set_animationstate(Game::Enums::AnimateEnum::WALK7);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK7) {
		set_animationstate(Game::Enums::AnimateEnum::WALK8);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::WALK8) {
		set_animationstate(Game::Enums::AnimateEnum::WALK1);
	}
}

void Game::Models::Enemy::idle()
{
	if (_animatestate != Enums::AnimateEnum::IDLE1 &&
		_animatestate != Enums::AnimateEnum::IDLE2 &&
		_animatestate != Enums::AnimateEnum::IDLE3 &&
		_animatestate != Enums::AnimateEnum::IDLE4 &&
		_animatestate != Enums::AnimateEnum::IDLE5 &&
		_animatestate != Enums::AnimateEnum::IDLE6 &&
		_animatestate != Enums::AnimateEnum::IDLE7 &&
		_animatestate != Enums::AnimateEnum::IDLE8) {
		set_animationstate(Enums::AnimateEnum::IDLE1);
	}

	if (_animatestate == Game::Enums::AnimateEnum::IDLE1) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE2);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE2) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE3);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE3) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE4);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE4) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE5);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE5) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE6);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE6) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE7);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE7) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE8);
	}
	else if (_animatestate == Game::Enums::AnimateEnum::IDLE8) {
		set_animationstate(Game::Enums::AnimateEnum::IDLE1);
	}
}