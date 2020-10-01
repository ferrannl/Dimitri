#include "Texture.h"

const char* Models::Texture::get_path()
{
	return _path;
}

SDL_Texture* Models::Texture::get_texture()
{
	return _texture;
}
