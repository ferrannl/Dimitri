#include "TextureFacade.h"
#include <SDL_ttf.h>

using namespace Graphics;

Facades::TextureFacade::TextureFacade(const std::string path) : _path{ path }, _texture(nullptr, SDL_DestroyTexture) {}

std::shared_ptr<SDL_Texture> Facades::TextureFacade::get_texture()
{
	return _texture;
}
