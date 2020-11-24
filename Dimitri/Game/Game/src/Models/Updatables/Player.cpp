#include "Player.h"

Game::Models::Player::Player(int x, int y, int z, int height, int width, Enums::DirectionEnum state, Graphics::Models::Center center) : Game::Models::Updatable(x, y, z, height, width, state, center)
{
	_jumps = _max_amount_of_jumps;
	_walk = {};
	_lastx = x;
	_lasty =y ;
	_direction = Enums::DirectionEnum::RIGHT;
	initialize_textures();
	create_shape(x, y, height, width, true, false, PhysicsCollision::Enums::ShapeEnum::Square);
}

void Game::Models::Player::initialize_textures()
{

	add_texture(Game::Enums::AnimateEnum::IDLE1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_000.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_001.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE3, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_002.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE4, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_003.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE5, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_004.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE6, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_005.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE7, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_006.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::IDLE8, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/idle/player_idle_007.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));


	add_texture(Game::Enums::AnimateEnum::WALK1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_000.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_001.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK3, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_002.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK4, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_003.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK5, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_004.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK6, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_005.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK7, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_006.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::WALK8, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/walk/player_walk_007.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));

	add_texture(Game::Enums::AnimateEnum::JUMP1, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/jump/player_jump_001_crop.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));
	add_texture(Game::Enums::AnimateEnum::JUMP2, std::make_shared<Graphics::Models::Sprite>(_x, _y, _z, _width, _height, 0, Utility::Helpers::get_base_path() + std::string{ "/assets/images/jump/player_jump_002_crop.png" }, Graphics::Enums::FlipEnum::NONE, false, _center));

	_animatestate = Enums::AnimateEnum::IDLE1;
	get_texture()->set_visible(true);
}

bool Game::Models::Player::jump()
{
	if (_jumps > 0) {
		_jumps--;
		return true;
	}
	else {
		return false;
	}
}

void Game::Models::Player::reset_jump()
{
	_jumps = _max_amount_of_jumps;
}

void Game::Models::Player::update_object(Controllers::LevelController* ctrl)
{
	if (_state == Enums::StateEnum::WALKING) {
		walk();
	}
	else if (_state == Enums::StateEnum::JUMPING) {
		set_animationstate(Enums::AnimateEnum::JUMP1);
	}
	else if (_state == Enums::StateEnum::FALLING) {
		set_animationstate(Enums::AnimateEnum::JUMP2);
	}
	else if (_state == Enums::StateEnum::IDLE) {
		idle();
	}

	if (_direction == Enums::DirectionEnum::LEFT) {
		get_texture()->set_flip_status(Graphics::Enums::FlipEnum::HORIZONTAL);
	}
	else {
		get_texture()->set_flip_status(Graphics::Enums::FlipEnum::NONE);
	}
}

void Game::Models::Player::walk()
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

void Game::Models::Player::idle()
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

void Game::Models::Player::update_state()
{
	if (_lasty < _y) {
		set_state(Enums::StateEnum::JUMPING);
	}
	else if (_lasty > _y) {
		set_state(Enums::StateEnum::FALLING);
	}
	else if ((_lastx < _x || _lastx > _x) && _state != Enums::StateEnum::JUMPING) {
		set_state(Enums::StateEnum::WALKING);
	}
	else if (_lastx == _x && _lasty == _y) {
		set_state(Enums::StateEnum::IDLE);
	}

	_lastx = _x;
	_lasty = _y;
}
