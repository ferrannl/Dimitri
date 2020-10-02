#include "../Engines/Graphics/src/Controllers/GraphicsController.h"
#include "../Engines/PhysicsCollision/WorldController.h"

int main(int argc, char** argv) 
{
    Controllers::GraphicsController handler = {};
    handler.create_window("Test", 0, 0, 720, 1080);

    WorldController worldController = WorldController{};
	worldController.setup_world(1080.0f, 720.0f);
	
    std::string base = SDL_GetBasePath();
    std::string path = base+"resources/images/img.png";
    const char* totalpath = path.c_str();

    std::vector<Models::Sprite*> sprites = {};
    std::vector<Shape> shapes = {};

    sprites.push_back(new Models::Sprite{ 350 ,600,1,100,100,totalpath });
    sprites.push_back(new Models::Sprite{ 300 ,200,1,100,300,totalpath });

    std::vector<std::pair<float, float>> position{ {0.0f,0.0f}, {0.0f,100.0f},{100.0f, 100.0f}, {100.0f, 0.0f}  };
    std::vector<std::pair<float, float>> position2{ {0.0f,0.0f}, {0.0f,100.0f},{300.0f, 100.0f}, {300.0f, 0.0f} };
    Shape shape = worldController.create_shape("polygon", 350.0f, 600.0f, position, true);
    Shape shape2 = worldController.create_shape("polygon", 300.0f, 200.0f, position2, false);

    shapes.push_back(shape);
    shapes.push_back(shape2);

    handler.add_sprites(sprites);

    bool isRunning = true;
    while (isRunning) {
        handler.update_window();
        worldController.simulate();
        for (int i = 0; i < shapes.size(); i++)
        {
            sprites[i]->set_x(static_cast<int>(shapes[i].get_x()));
            sprites[i]->set_y(static_cast<int>(shapes[i].get_y()));
        }

        SDL_Delay(5);
    }

    handler.get_window()->destroy();

    return 0;
}