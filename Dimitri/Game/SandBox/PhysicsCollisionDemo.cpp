#include "PhysicsCollisionDemo.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	graphicsController = Controllers::GraphicsController{};
	worldController = Controllers::WorldController{};
	sprites = std::make_shared<std::vector<std::unique_ptr<Models::Sprite>>>();
	shapes = std::vector<Models::Shape>{};
}

void PhysicsCollisionDemo::start_demo()
{
	if (create_window(1080, 720) == NULL) {
		return;
	}

	std::string path = (SDL_GetBasePath() + std::string{ "assets/images/img.png" });
	create_sprite(350, 600, 1, 50, 50, path.c_str(), 0, Enums::FlipEnum::VERTICAL);
	create_sprite(300, 200, 1, 300, 50, path.c_str(), 0, Enums::FlipEnum::HORIZONTAL);
	create_sprite(0, 720, 1, 1080, 1, path.c_str(), 0, Enums::FlipEnum::HORIZONTAL);
	create_sprite(0, -1, 1, 1080, 1, path.c_str(), 0, Enums::FlipEnum::HORIZONTAL);
	create_sprite(-1, 0, 1, 1, 720, path.c_str(), 0, Enums::FlipEnum::HORIZONTAL);
	create_sprite(1080, 0, 1, 1, 720, path.c_str(), 0, Enums::FlipEnum::HORIZONTAL);
	graphicsController.add_sprites(sprites);
	create_shape(350, 600, 50, 50, true);
	create_shape(300, 200, 300, 50, false);
	create_shape(0, 720, 1080, 1, false); // top    
	create_shape(0, -1, 1080, 1, false); // bottom    
	create_shape(-1, 0, 1, 720, false); // left
	create_shape(1080, 0, 1, 720, false); // right
	
}

int PhysicsCollisionDemo::create_window(int width, int height)
{
	if (graphicsController.create_window("Test", height, width) != NULL) {
		worldController.setup_world(width, height);
	}
	else {
		return NULL;
	}
}

void PhysicsCollisionDemo::create_sprite(int x, int y, int z, int width, int height, const char* path, const float angle, Enums::FlipEnum flipstatus)
{
	sprites->push_back(std::make_unique<Models::Sprite>( x, y, z, height, width, path, angle, flipstatus ));
}

void PhysicsCollisionDemo::create_shape(int x, int y, int width, int height, bool is_dynamic)
{
	std::vector<std::pair<float, float>> positions{ {0.0f,0.0f}, {0.0f,height},{width, height}, {width, 0.0f} };
	shapes.push_back(worldController.create_shape("polygon", x, y, positions, is_dynamic));
}

void PhysicsCollisionDemo::run()
{
	
	while (true)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			sprites->at(i)->set_x(static_cast<int>(shapes[i].get_x()));
			sprites->at(i)->set_y(static_cast<int>(shapes[i].get_y()));
			sprites->at(i)->set_angle(static_cast<int>(shapes[i].get_angle()));
		}
		graphicsController.update_window();
		worldController.simulate();

		SDL_Delay(5);
	}

	graphicsController.get_window()->destroy();
}

void PhysicsCollisionDemo::update(Enums::EventEnum event)
{
	switch (event) {
	case Enums::EventEnum::KEY_PRESS_LEFT:
		shapes[0].move_x(-1);
		sprites->at(0)->set_x(shapes[0].get_x());
		break;
	case Enums::EventEnum::KEY_PRESS_RIGHT:
		shapes[0].move_x(1);
		sprites->at(0)->set_x(shapes[0].get_x());
		break;
	default: 
		std::cout << "geen reactie";
	}
}



