#include "PhysicsCollisionDemo.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	graphicsController = Controllers::GraphicsController{};
	worldController = Controllers::WorldController{};
	inputEvent = InputEvent::Instance();
	sprites = std::vector<Models::Sprite*>{};
	shapes = std::vector<Models::Shape>{};
}

void PhysicsCollisionDemo::start_demo()
{
	create_window(1080, 720);
	std::string path = (SDL_GetBasePath() + std::string{ "resources/images/img.png" });
	create_sprite(350, 600, 1, 100, 50, path.c_str());
	create_sprite(300, 200, 1, 300, 50, path.c_str());
	graphicsController.add_sprites(sprites);
	create_shape(350, 600, 100, 50, true);
	create_shape(300, 200, 300, 50, false);
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
		if (SDL_PollEvent(&event) == 1)
		{
			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_RIGHT:
					//std::cout << shapes[0].get_x() + 50;
					shapes[0].set_x(5, "right");
					std::cout << shapes[0].get_x();
					sprites[0]->set_x(static_cast<int>(shapes[0].get_x()));
					break;
				case SDLK_LEFT:
					/*shapes[0].set_x(shapes[0].get_x() - 1);*/
					shapes[0].set_x(5, "left");
					std::cout << shapes[0].get_x();
					sprites[0]->set_x(static_cast<int>(shapes[0].get_x()));
				case SDLK_UP:
					//shapes[0].set_y(shapes[0].get_y() + 1);
					shapes[0].set_y(5);
					std::cout << shapes[0].get_y();
					sprites[0]->set_y(static_cast<int>(shapes[0].get_y()));
				default:
					//sprites[0]->set_x(static_cast<int>(shapes[0].get_x() + 50));
					break;
				}
			}
		}
		graphicsController.update_window();
		worldController.simulate();


		for (int i = 0; i < shapes.size(); i++)
		{
			sprites[i]->set_x(static_cast<int>(shapes[i].get_x()));
			sprites[i]->set_y(static_cast<int>(shapes[i].get_y()));
		}

		SDL_Delay(5);

	}

	graphicsController.get_window()->destroy();
}
