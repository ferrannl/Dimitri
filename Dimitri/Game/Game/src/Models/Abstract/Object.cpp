#include "Object.h"

using namespace Game;

Models::Object::Object(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : _x{ x }, _y{ y }, _z{ z }, _width{ width }, _height{ height }, _direction{ state }, _center{ center }
{
	_angle = 0.0f;
	_animatestate = Enums::AnimateEnum::IDLE1;
	_state = Enums::StateEnum::IDLE;
}

std::shared_ptr<Graphics::Models::Texture> Models::Object::get_texture()
{
	std::shared_ptr<Graphics::Models::Texture> texture = _textures[_animatestate];

	texture->set_x(this->get_x());
	texture->set_y(this->get_y());
	texture->set_z(this->get_z());
	texture->set_height(this->_height);
	texture->set_width(this->_width);

	return texture;
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Models::Object::get_all_textures()
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> value = std::vector<std::shared_ptr<Graphics::Models::Texture>>();
	for (std::map<Enums::AnimateEnum, std::shared_ptr<Graphics::Models::Texture>>::iterator it = _textures.begin(); it != _textures.end(); ++it) {
		if (it->first != Enums::AnimateEnum::HUD1 || it->first != Enums::AnimateEnum::HUD2) {
			value.push_back(it->second);
		}
	}
	return value;
}

float Models::Object::get_x() const
{
	return _x;
}

void Models::Object::set_x(float value)
{
	this->_x = value;
}

float Models::Object::get_y() const
{
	return _y;
}

void Models::Object::set_y(float value)
{
	this->_y = value;
}

float Models::Object::get_z() const
{
	return _z;
}

void Models::Object::set_z(float value)
{
	this->_z = value;
}

void Models::Object::set_state(Enums::StateEnum value)
{
	this->_state = value;
}

void Models::Object::set_direction(Enums::DirectionEnum value)
{
	this->_direction = value;
}

void Game::Models::Object::set_animationstate(Enums::AnimateEnum state)
{
	this->get_texture()->set_visible(false);
	this->_animatestate = state;
	this->get_texture()->set_visible(true);
}

void Game::Models::Object::toggle_visibility()
{
	this->get_texture()->toggle_visible();
}

const std::shared_ptr<PhysicsCollision::Models::Shape>& Models::Object::get_shape() const
{
	return _shape;
}

void Models::Object::create_shape(float x, float y, float height, float width, bool is_dynamic, bool is_interactable, PhysicsCollision::Enums::ShapeEnum type)
{
	_shape = std::make_shared<PhysicsCollision::Models::Shape>(x, y, height, width, is_dynamic, is_interactable, type);
}

void Models::Object::add_texture(Enums::AnimateEnum state, const std::shared_ptr<Graphics::Models::Texture>& texture)
{
	this->_textures.insert(std::pair<Enums::AnimateEnum, std::shared_ptr<Graphics::Models::Texture>>(state, texture));
}

float Models::Object::get_height() const
{
	return _height;
}

float Models::Object::get_width() const
{
	return _width;
}

void Models::Object::update()
{
	set_x(_shape->get_x());
	set_y(_shape->get_y());
	_shape->set_angle(get_texture()->get_angle());
}

void Game::Models::Object::clear_textures()
{
	this->_textures.clear();
}