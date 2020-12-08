#include "Object.h"

using namespace Game;

Models::Object::Object(float x, float y, float z, float height, float width, Enums::DirectionEnum state, Graphics::Models::Center center) : _x{ x }, _y{ y }, _z{ z }, _width{ width }, _height{ height }, _direction{ state }, _center{ center }
{
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
	_textures[_animatestate]->set_x(_x);
}

float Models::Object::get_y() const
{
	return _y;
}

void Models::Object::set_y(float value)
{
	this->_y = value;
	_textures[_animatestate]->set_y(_y);
}

float Models::Object::get_z() const
{
	return _z;
}

void Models::Object::set_z(float value)
{
	this->_z = value;
	_textures[_animatestate]->set_z(_z);
}

void Models::Object::set_state(const Enums::StateEnum& value)
{
	this->_state = value;
}

void Models::Object::set_direction(const Enums::DirectionEnum& value)
{
	this->_direction = value;
}

void Game::Models::Object::set_animationstate(const Enums::AnimateEnum& state)
{
	this->get_texture()->set_visible(false);
	this->_animatestate = state;
	this->get_texture()->set_visible(true);
}

std::shared_ptr<PhysicsCollision::Models::Shape> Models::Object::get_shape() const
{
	return _shape;
}

void Models::Object::create_shape(const float x, const float y, const float height, const float width, const bool is_dynamic, const bool is_interactable, const PhysicsCollision::Enums::ShapeEnum type)
{
	set_shape(std::make_shared<PhysicsCollision::Models::Shape>(x, y, height, width, is_dynamic,is_interactable, type));
}

void Models::Object::set_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape)
{
	_shape = shape;
}

void Models::Object::add_texture(const Enums::AnimateEnum& state, std::shared_ptr<Graphics::Models::Texture> texture)
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
