#include "TextureFacade.h"
#include <SDL_ttf.h>

using namespace Graphics;

Facades::TextureFacade::TextureFacade(const std::string path) :
	_path{ path }, _texture{ std::unique_ptr<SDL_Texture, TextureDestroyer>(nullptr, SDL_DestroyTexture) } {}

SDL_Texture* Facades::TextureFacade::get_texture() const
{
	return _texture.get();
}
