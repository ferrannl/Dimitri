#include "Texture.h"
using namespace Graphics;

Models::Texture::Texture(float x, float y, float z, float height, float width, float angle, const std::string& path, bool visible, const Models::Center center, bool is_dynamic, int opacity) :
	_x{ x }, _y{ y }, _z{ z }, _height{ height }, _width{ width }, _angle{ angle }, _path{ path }, _facade{ nullptr }, _flipstatus{ Enums::FlipEnum::NONE }, _visible{ visible }, _center{center}, _is_dynamic{is_dynamic}, _opacity{ opacity } {}

float Models::Texture::get_converted_y(float height) const
{
	return height - (_y + _height);
}

float Models::Texture::get_x() const
{
	return _x;
}

float Models::Texture::get_z() const
{
	return _z;
}

float Models::Texture::get_y() const
{
	return _y;
}

float Models::Texture::get_width() const
{
	return _width;
}

float Models::Texture::get_height() const
{
	return _height;
}

float Models::Texture::get_angle() const
{
	return _angle;
}

Models::Center Graphics::Models::Texture::get_center() const
{
	return _center;
}

bool Models::Texture::is_visible() const
{
	return _visible;
}

bool Graphics::Models::Texture::is_dynamic() const
{
	return _is_dynamic;
}

std::string Models::Texture::get_path() const
{
	return _path;
}

Enums::FlipEnum Models::Texture::get_flip_status() const
{
	return _flipstatus;
}

std::shared_ptr<Facades::TextureFacade> Models::Texture::get_texture_facade() const
{
	return _facade;
}

void Models::Texture::set_x(float x)
{
	_x = x;
}

void Models::Texture::set_z(float z)
{
	_z = z;
}

void Models::Texture::set_y(float y)
{
	_y = y;
}

void Models::Texture::set_width(float width)
{
	_width = width;
}

void Models::Texture::set_height(float height)
{
	_height = height;
}

void Models::Texture::set_angle(float angle)
{
	_angle = angle;
}

void Models::Texture::set_flip_status(Enums::FlipEnum flipstatus)
{
	_flipstatus = flipstatus;
}

void Models::Texture::set_visible(bool visibility)
{
	_visible = visibility;
}

void Models::Texture::toggle_visible()
{
	_visible = !_visible;
}

void Graphics::Models::Texture::set_center(const Models::Center& center)
{
	_center = center;
}

int Graphics::Models::Texture::get_opacity() const
{
	return _opacity;
}

void Models::Texture::set_facade(const std::shared_ptr<Facades::TextureFacade>& facade)
{
	_facade = facade;
}
