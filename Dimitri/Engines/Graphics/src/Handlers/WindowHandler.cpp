#include "WindowHandler.h"
#include "TextureHandler.h"
#include <string> using namespace std
#include <vector>


int main(int argc, char** argv) 
{
    // step 1
    Handlers::WindowHandler handler = {};
    handler.create_window("Test", 0, 0, 720, 1080);

    // step 2
    std::string path = "D:/School - Programming/c++/Project/dimitri/Dimitri/Engines/Graphics/src/Handlers/img.png";
    Models::Sprite* sprite1 = new Models::Sprite{ 0,0,100,100,path };
    Models::Sprite* sprite2 = new Models::Sprite{ 200,200,100,100,path };
    Models::Sprite* sprite3 = new Models::Sprite{ 400,400,100,100,path };
    Models::Sprite* sprite4 = new Models::Sprite{ 500,600,100,100,path };

    std::vector<Models::Sprite*> sprites = {};

    sprites.push_back(sprite1);
    sprites.push_back(sprite2);
    sprites.push_back(sprite3);
    sprites.push_back(sprite4);

    // step 3
    handler.add_sprites(sprites);

    // step 4 
    bool isRunning = true;
    while (isRunning) {
        handler.update_window();

        for (Models::Sprite* sprite : sprites) {
            if ((sprite->get_x() + sprite->get_width()) >= handler.get_window()->get_width()) {
                isRunning = false;
            }

            sprite->set_x(sprite->get_x() + 1);
        }

        SDL_Delay(40);
    }

    SDL_Delay(1000);

    // step 5
    handler.get_window()->destroy();

    return 0;
}

void Handlers::WindowHandler::create_window(const char* title, int xpos, int ypos, int height, int width)
{
    _window = new Models::Window(title, xpos, ypos, height, width);
    _window->create();
}

void Handlers::WindowHandler::add_sprites(std::vector<Models::Sprite*> sprites)
{
    _window->set_sprites(sprites);
    _window->create_sprites();
}

std::vector<Models::Sprite*> Handlers::WindowHandler::get_sprites()
{
    return _window->get_sprites();
}

void Handlers::WindowHandler::update_window()
{
    _window->update();
}

Models::Window* Handlers::WindowHandler::get_window()
{
    return _window;
}
