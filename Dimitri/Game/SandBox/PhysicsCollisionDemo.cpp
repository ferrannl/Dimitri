#include "PhysicsCollisionDemo.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	graphicsController = Controllers::GraphicsController{};
	worldController = Controllers::WorldController{};
	_inputController = std::make_shared<Controllers::InputController>();
	sprites = std::make_shared<std::vector<std::unique_ptr<Models::Sprite>>>();
	shapes = std::vector<Models::Shape>();
}

void PhysicsCollisionDemo::start_demo()
{
	if (create_window(1080, 720) == NULL) {
		return;
	}

	std::string image = (Adapters::BasePathAdapter::get_base_path() + std::string{ "assets/images/img.png" });
	create_sprite(350, 100, 1, 100, 100, image.c_str(), 0, Enums::FlipEnum::VERTICAL);
	create_sprite(400, 200, 1, 300, 100, image.c_str(), 0, Enums::FlipEnum::HORIZONTAL);

	graphicsController.add_sprites(sprites);
	create_shape(350, 100, 100, 100, true);
	create_shape(400, 200, 300, 100, false);
	create_shape(0, 620, 1080, 100, false); // top    
	create_shape(0, -200, 1080, 100, false); // bottom    
	create_shape(-1, 0, 1, 720, false); // left
	create_shape(1080, 0, 1, 720, false); // right

	std::thread demo_thread(&PhysicsCollisionDemo::run, this);
	_inputController->poll_events();
	demo_thread.join();
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

void PhysicsCollisionDemo::create_sprite(float x, float y, float z, float  width, float height, const char* path, const float angle, Enums::FlipEnum flipstatus)
{
	if (flipstatus == Enums::FlipEnum::HORIZONTAL)
	{
		y = y + height;
	}
	sprites->push_back(std::make_unique<Models::Sprite>(x, y, z, height, width, path, angle, flipstatus));
}

void PhysicsCollisionDemo::create_shape(float x, float y, float width, float height, bool is_dynamic)
{
	//std::vector<std::pair<float, float>> positions{ {0 ,0 }, {0,height / 2},{width / 2, height / 2}, {width / 2, 0} };
	/*x = x - width / 2;
	y = y + height / 2;*/
	shapes.push_back(worldController.create_shape("polygon", x, y, width, height, is_dynamic));
}

void PhysicsCollisionDemo::run()
{
	while (true)
	{
		std::map<std::shared_ptr<Models::Shape>, b2Body*> _world_bodies = worldController.get_world_bodies();
		for (auto const& it : _world_bodies)
		{
			std::shared_ptr<Models::Shape> shape = it.first;
			b2Body* body = shape->get_shape_facade()->get_body();
				if (shape->get_is_dynamic())
				{
					sprites->at(0)->set_x(shape->get_x());
					sprites->at(0)->set_y(shape->get_y());
					printf("%4.2f %4.2f %4.2f %4.2f \n", shape->get_x(), shape->get_y(), shape->get_width(), shape->get_height());

				}		
				worldController.simulate();
		}
		graphicsController.update_window();
		sleep_for(5ms);
	}
	worldController.destroy_bodies();
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
	case Enums::EventEnum::KEY_PRESS_UP:
		shapes[0].move_y();
		sprites->at(0)->set_y(shapes[0].get_y());
		break;
	default:
		std::cout << "geen reactie";
		break;
	}
}

void PhysicsCollisionDemo::subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo)
{
	_inputController->subscribe(demo);
}



