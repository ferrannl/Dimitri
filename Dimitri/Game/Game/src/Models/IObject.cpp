#include "IObject.h"

Game::Models::IObject::IObject(int x, int y, int z, int height, int width) : _x{ x }, _y{ y }, _z{ z }, _width{ width }, _height{ height }
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
	for (std::map<std::string, std::shared_ptr<Graphics::Models::Texture>>::iterator it = _textures.begin(); it != _textures.end(); ++it) {
		value.push_back(it->second);
	}
	return value;
}

int Game::Models::IObject::get_x()
{
	return _x;
}

void Game::Models::IObject::set_x(int value)
{
	this->_x = value;
	_textures[_state]->set_x(_x);
}

int Game::Models::IObject::get_y()
{
	return _y;
}

void Game::Models::IObject::set_y(int value)
{
	this->_y = value;
	_textures[_state]->set_y(_y);
}

int Game::Models::IObject::get_z()
{
	return _z;
}

void Game::Models::IObject::set_z(int value)
{
	this->_z = value;
	_textures[_state]->set_z(_z);
}

void Game::Models::IObject::set_state(std::string value)
{
	this->get_texture()->set_visible(false);
	this->_state = value;
	this->get_texture()->set_visible(true);
}

void Game::Models::IObject::add_texture(std::string state, std::shared_ptr<Graphics::Models::Texture> texture)
{
	this->_textures.insert(std::pair<std::string, std::shared_ptr<Graphics::Models::Texture>>(state, texture));
}
