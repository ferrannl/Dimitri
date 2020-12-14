#include "TextureFacade.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>

using namespace Graphics;

Facades::TextureFacade::TextureFacade(const std::string& path, int opacity) :
	_path{ path }, _opacity{ (uint8_t)(opacity * 255 / 100) }, _texture{ std::unique_ptr<SDL_Texture, TextureDestroyer>(nullptr, SDL_DestroyTexture) } {}

SDL_Texture* Facades::TextureFacade::get_texture() const
{
	return _texture.get();
}
