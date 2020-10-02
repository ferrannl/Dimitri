#include "GraphicsController.h"

//int main(int argc, char** argv) 
//{
//
//    // step 1
//    Controllers::GraphicsController handler = {};
//    handler.create_window("Test", 0, 0, 720, 1080);
//
//    // step 2
//    std::string base = SDL_GetBasePath();
//    std::string path = base+"resources/images/img.png";
//    const char* totalpath = path.c_str();
//
//    std::vector<Models::Sprite*> sprites = {};
//
//    for (int x = 0; x < 100; x++) {
//        sprites.push_back(new Models::Sprite{ 0 + x,0,1,100,100,totalpath });
//    }
//
//    // step 3
//    handler.add_sprites(sprites);
//
//    // step 4 
//    bool isRunning = true;
//    while (isRunning) {
//        handler.update_window();
//
//        for (Models::Sprite* sprite : sprites) {
//            sprite->set_x(sprite->get_x() + 1);
//        }
//
//        SDL_Delay(20);
//    }
//
//    SDL_Delay(10000);
//
//    // step 5
//    handler.get_window()->destroy();
//
//    return 0;
//}


void Controllers::GraphicsController::create_window(const char* title, int xpos, int ypos, int height, int width)
{
    _window = new Models::Window(title, xpos, ypos, height, width);
    _window->create();
}

void Controllers::GraphicsController::add_sprites(std::vector<Models::Sprite*> sprites)
{
    _window->set_sprites(sprites);
    _window->create_sprites();
}

std::vector<Models::Sprite*> Controllers::GraphicsController::get_sprites()
{
    return _window->get_sprites();
}

void Controllers::GraphicsController::update_window()
{
    _window->update();
}

Models::Window* Controllers::GraphicsController::get_window()
{
    return _window;
}
