#include "Sprite.h"

int Models::Sprite::get_x()
{
    return _x;
}

int Models::Sprite::get_y()
{
    return _y;
}

int Models::Sprite::get_width()
{
    return _width;
}

int Models::Sprite::get_height()
{
    return _height;
}

void Models::Sprite::set_x(int x)
{
    _x = x;
}

void Models::Sprite::set_y(int y)
{
    _y = y;
}

void Models::Sprite::set_width(int width)
{
    _width = width;
}

void Models::Sprite::set_height(int height)
{
    _height = height;
}



std::string Models::Sprite::get_path()
{
    return _path;
}

void Models::Sprite::add_texture(SDL_Texture* texture)
{
    _texture = texture;
}

SDL_Texture* Models::Sprite::get_texture()
{
    return _texture;
}
