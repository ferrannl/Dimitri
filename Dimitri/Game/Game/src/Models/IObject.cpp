#include "IObject.h"

Game::Models::IObject::IObject(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : _x{ x }, _y{ y }, _z{ z }, _width{ width }, _height{ height }, _state { state }
{
}

std::shared_ptr<Graphics::Models::Texture> Game::Models::IObject::get_texture()
{
	std::shared_ptr<Graphics::Models::Texture> texture = _textures[_state];
	texture->set_x(this->get_x());
	texture->set_y(this->get_y());
	texture->set_z(this->get_z());
	texture->set_height(this->_height);
	texture->set_width(this->_width);
	return texture;
}

std::vector<std::shared_ptr<Graphics::Models::Texture>> Game::Models::IObject::get_all_textures()
{
	std::vector<std::shared_ptr<Graphics::Models::Texture>> value = std::vector<std::shared_ptr<Graphics::Models::Texture>>();
	for (std::map<Game::Enums::StateEnum, std::shared_ptr<Graphics::Models::Texture>>::iterator it = _textures.begin(); it != _textures.end(); ++it) {
		value.push_back(it->second);
	}
	return value;
}

int Game::Models::IObject::get_x() const
{
	return _x;
}

void Game::Models::IObject::set_x(int value)
{
	this->_x = value;
	_textures[_state]->set_x(_x);
}

int Game::Models::IObject::get_y() const
{
	return _y;
}

void Game::Models::IObject::set_y(int value)
{
	this->_y = value;
	_textures[_state]->set_y(_y);
}

int Game::Models::IObject::get_z() const
{
	return _z;
}

void Game::Models::IObject::set_z(int value)
{
	this->_z = value;
	_textures[_state]->set_z(_z);
}

void Game::Models::IObject::set_state(const Game::Enums::StateEnum& value)
{
	this->get_texture()->set_visible(false);
	this->_state = value;
	this->get_texture()->set_visible(true);
}

std::shared_ptr<PhysicsCollision::Models::Shape> Game::Models::IObject::get_shape() const
{
	return _shape;
}

void Game::Models::IObject::create_shape(const int x, const int y, const int height, const int width, const bool is_dynamic, const bool is_interactable, const PhysicsCollision::Enums::ShapeEnum type)
{
	set_shape(std::make_shared<PhysicsCollision::Models::Shape>(x, y, height, width, is_dynamic,is_interactable, type));
}

void Game::Models::IObject::set_shape(std::shared_ptr<PhysicsCollision::Models::Shape> shape)
{
	_shape = shape;
}

void Game::Models::IObject::add_texture(const Game::Enums::StateEnum& state, std::shared_ptr<Graphics::Models::Texture> texture)
{
	this->_textures.insert(std::pair<Game::Enums::StateEnum, std::shared_ptr<Graphics::Models::Texture>>(state, texture));
}

int Game::Models::IObject::get_height() const
{
	return _height;
}

int Game::Models::IObject::get_width() const
{
	return _width;
}

void Game::Models::IObject::update()
{
	set_x(_shape->get_x());
	set_y(_shape->get_y());
}
