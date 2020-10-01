#include "TextureFacade.h"

void Facades::TextureFacade::create_renderer(SDL_Window* window)
{
	//Create renderer for window
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	}
}

Models::Texture* Facades::TextureFacade::get_if_exists(const char* path)
{
	for (Models::Texture* texture : _textures) {
		if (texture->get_path() == path) {
			return texture;
		}
	}

	return nullptr;
}

Models::Texture* Facades::TextureFacade::create_texture_model(const char* path, SDL_Texture* texture)
{
	Models::Texture* new_texture = new Models::Texture(path, texture);
	_textures.push_back(new_texture);

	return new_texture;
}

bool Facades::TextureFacade::load_sprite(Models::Sprite* sprite)
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	Models::Texture* texture = get_if_exists(sprite->get_path());

	if (texture != nullptr) {
		sprite->set_texture(texture);
		return success;
	}

	SDL_Texture* sdltexture = create_texture(sprite->get_path());

	if (sdltexture == NULL)
	{
		delete sdltexture;
		printf("Failed to load texture image!\n");
		success = false;
	}
	else {
		sprite->set_texture(create_texture_model(sprite->get_path(), sdltexture));
	}

	return success;
}

SDL_Texture* Facades::TextureFacade::create_texture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	loadedSurface = NULL;

	return newTexture;
}

void Facades::TextureFacade::update_screen(SDL_Window* window, std::vector<Models::Sprite*> sprites)
{
	//Clear screen
	SDL_RenderClear(_renderer);
	int depth = 0;
	int objectcounter = 0;

	while (objectcounter < sprites.size()) {
		for (Models::Sprite* sprite : sprites) {
			if (sprite->get_z() == depth) {
				SDL_Rect rect;

				rect.x = sprite->get_x();
				rect.y = sprite->get_converted_y(SDL_GetWindowSurface(window)->h);
				rect.w = sprite->get_width();
				rect.h = sprite->get_height();

				//Render texture to screen
				SDL_RenderCopy(_renderer, sprite->get_texture()->get_texture(), NULL, &rect);
				objectcounter++;
			}
		}
		depth++;
	}

	//Update screen
	SDL_RenderPresent(_renderer);
}
