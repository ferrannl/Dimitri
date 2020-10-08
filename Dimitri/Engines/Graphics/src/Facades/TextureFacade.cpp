#include "TextureFacade.h"

Facades::TextureFacade::TextureFacade() {
    _texture = { nullptr };
}

// copy constructor
Facades::TextureFacade::TextureFacade(const Facades::TextureFacade& facade) {
    _texture = facade._texture;
}

// copy operator
Facades::TextureFacade& Facades::TextureFacade::operator=(const Facades::TextureFacade& facade)
{
    if (this != &facade) {
        _texture = facade._texture;
    }

    return *this;
}

// move constructor
Facades::TextureFacade::TextureFacade(Facades::TextureFacade&& facade) {
    _texture = facade._texture;

    _texture = { nullptr };
}

// move operator
Facades::TextureFacade& Facades::TextureFacade::operator=(Facades::TextureFacade&& facade)
{
	if (this != &facade) {

		_texture = facade._texture;

		facade._texture = { nullptr };
	}

	return *this;
}

void Facades::TextureFacade::create_texture(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>& renderer, const std::string path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		_texture = std::make_shared<SDL_Texture>(SDL_CreateTextureFromSurface(renderer.get(), loadedSurface), SDL_DestroyTexture);

		if (_texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	loadedSurface = NULL;
}

std::shared_ptr<SDL_Texture> Facades::TextureFacade::get_texture()
{
	return _texture;
}

Facades::TextureFacade::~TextureFacade() {
	_texture = { nullptr };
}