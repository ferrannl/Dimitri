#include "Enemy.h"
#include "../../Controllers/LevelController.h"

Game::Models::Enemy::Enemy(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Game::Models::Updatable(x, y, z, height, width, state, center)
{
	_jumps = _max_amount_of_jumps;
	_lastx = x;
	_lasty = y;
	_direction = Enums::DirectionEnum::NONE;
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

bool Game::Models::Enemy::jump()
{
	if (_jumps > 0) {
		_jumps--;
		return true;
	}
	else {
		return false;
	}
}

void Game::Models::Enemy::reset_jump()
{
	_jumps = _max_amount_of_jumps;
}

void Game::Models::Enemy::update_object(Controllers::LevelController* ctrl)
{
	bool Left = (_x - 240 < (ctrl->get_level()->get_player()->get_x()));
	bool Right = (_x + 240 > (ctrl->get_level()->get_player()->get_x()));
	bool Top = (_y - 200 < (ctrl->get_level()->get_player()->get_y()));
	bool Bottom = (_y + 200 > (ctrl->get_level()->get_player()->get_y()));
	bool In_Area = (Left && Right && Top && Bottom);

	if (In_Area)
	{
		walk();
		if (_x < (ctrl->get_level()->get_player()->get_x())) {
			_shape->move_x(1, 1);
			_direction = Enums::DirectionEnum::RIGHT;
		}
		else {
			_shape->move_x(-1, 1);
			_direction = Enums::DirectionEnum::LEFT;
		}
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
