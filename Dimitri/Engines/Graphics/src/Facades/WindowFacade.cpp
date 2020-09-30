#include "WindowFacade.h"

void Facades::WindowFacade::create(const char* title, int xpos, int ypos, int height, int width)
{
    //Start up SDL and create window
    if (!Facades::WindowFacade::Init())
    {
        printf("Failed to initialize!\n");
    }
    else {
        _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        _textureFacade = new Facades::TextureFacade {_window};
    }
}

void Facades::WindowFacade::create_sprites(std::vector<Models::Sprite*> sprites)
{
    if (_textureFacade == nullptr) {
        return;
    }

    for(Models::Sprite* sprite : sprites) {
        _textureFacade->load_sprite(sprite);
    }
}

    void Facades::WindowFacade::destroy()
{
        //Deallocate surfaces
        SDL_FreeSurface(_background);
        SDL_FreeSurface(_foreground);

        _background = NULL;
        _foreground = NULL;

        //Destroy window
        SDL_DestroyWindow(_window);
        _window = NULL;

        //Quit SDL subsystems
        SDL_Quit();
}

    bool Facades::WindowFacade::Init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            return false;
        }
        else
        {
            return true;
        }
    }

    void Facades::WindowFacade::update_sprites(std::vector<Models::Sprite*> sprites) 
    {
        _textureFacade->update_screen(_window, sprites);
    }
