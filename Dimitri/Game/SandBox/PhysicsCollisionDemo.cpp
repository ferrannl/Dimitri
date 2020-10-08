#include "PhysicsCollisionDemo.h"
#include "../../Engines/Input/src/adapters/EventFacade.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	graphicsController = Controllers::GraphicsController{};
	worldController = Controllers::WorldController{};
	sprites = std::vector<Models::Sprite*>{};
	shapes = std::vector<Models::Shape>{};
}

void PhysicsCollisionDemo::start_demo()
{
	create_window(1080, 720);
	std::string path = (SDL_GetBasePath() + std::string{ "resources/images/img.png" });
	create_sprite(350, 600, 1, 50, 50, path.c_str());
	create_sprite(300, 200, 1, 300, 50, path.c_str());
	create_sprite(0, 720, 1, 1080, 1, path.c_str());
	create_sprite(0, -1,1, 1080, 1, path.c_str());
	create_sprite(-1, 0,1, 1, 720, path.c_str());
	create_sprite(1080, 0,1, 1, 720, path.c_str());
	graphicsController.add_sprites(sprites);
	create_shape(350, 600, 50, 50, true);
	create_shape(300, 200, 300, 50, false);
	create_shape(0, 720, 1080, 1, false); // top	
	create_shape(0, -1, 1080, 1, false); // bottom	
	create_shape(-1, 0, 1, 720, false); // left
	create_shape(1080, 0, 1, 720, false); // right
	run();
}

void PhysicsCollisionDemo::create_window(int width, int height)
{
	graphicsController.create_window("Test", 0, 0, height, width);
	worldController.setup_world(width, height);
}

void PhysicsCollisionDemo::create_sprite(int x, int y, int z, int width, int height, const char* path)
{
	sprites.push_back(new Models::Sprite{ x, y, z, height, width, path });
}

void PhysicsCollisionDemo::create_shape(int x, int y, int width, int height, bool is_dynamic)
{
	std::vector<std::pair<float, float>> positions{ {0.0f,0.0f}, {0.0f,height},{width, height}, {width, 0.0f} };
	shapes.push_back(worldController.create_shape("polygon", x, y, positions, is_dynamic));
}

void PhysicsCollisionDemo::run()
{
	SDL_Event event;
	while (true)
	{
		if (SDL_PollEvent(&event) != 1)
		{	
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				EventFacade adapter = EventFacade();
				adapter.handle_input(event, sprites[0], shapes[0]);
			}
		}
		for (int i = 0; i < shapes.size(); i++)
		{
			sprites[i]->set_x(static_cast<int>(shapes[i].get_x()));
			sprites[i]->set_y(static_cast<int>(shapes[i].get_y()));
		}
		graphicsController.update_window();
		worldController.simulate();

		SDL_Delay(5);
	}

	graphicsController.get_window()->destroy();
}
