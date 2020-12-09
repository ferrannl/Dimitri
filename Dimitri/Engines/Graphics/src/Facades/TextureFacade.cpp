#include "TextureFacade.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace Graphics;

Facades::TextureFacade::TextureFacade(const std::string& path) :
	_path{ path }, _texture{ std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)>(nullptr, SDL_DestroyTexture) } {}

SDL_Texture* Facades::TextureFacade::get_texture() const
{
	return _texture.get();
}
