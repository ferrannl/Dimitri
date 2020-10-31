#include "PhysicsCollisionDemo.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	PhysicsCollisionDemo::graphics_controller = Graphics::Controllers::GraphicsController{};
	world_controller = PhysicsCollision::Controllers::WorldController{};
	input_controller = std::make_shared<Input::Controllers::InputController>();
	sprites = std::make_shared<std::vector<std::unique_ptr<Graphics::Models::Sprite>>>();
	shapes = std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>>();
}

void PhysicsCollisionDemo::start_demo()
{
	if (create_window(1080, 720) == NULL) {
		return;
	}

	std::string bg_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" };
	std::string ground_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/wall.png" };
	std::string player_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/player.png" };
	create_sprite(350, 300, 1, 75, 75, player_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE, true);
	create_sprite(300, 200, 1, 300, 50, ground_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE, false);
	create_sprite(0, 0, 0, 1080, 720, bg_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE, true);

	graphics_controller.add_sprites(sprites);
	create_shape(350, 300, 75, 75, true);
	create_shape(300, 175, 300, 50, false);
	create_shape(0, 645, 1080, 100, false); // top
	create_shape(0, -175, 1080, 100, false); // bottom

	create_shape(-1, 0, 1, 720, false); // left
	create_shape(1080, 0, 1, 720, false); // right
	shapes = world_controller.get_shapes();

	std::thread demo_thread(&PhysicsCollisionDemo::run, this);
	input_controller->poll_events();
	demo_thread.join();
}

int PhysicsCollisionDemo::create_window(int width, int height)
{
	if (graphics_controller.create_window("Test", height, width) != NULL) {
		world_controller.setup_world(width, height);
	}
	else {
		return NULL;
	}
}

void PhysicsCollisionDemo::create_sprite(float x, float y, float z, float  width, float height, const char* path, const float angle, Graphics::Enums::FlipEnum flipstatus, bool is_dynamic)
{
	if (!is_dynamic)
	{
		y = y + height;
	}
	sprites->push_back(std::make_unique<Graphics::Models::Sprite>(x, y, z, height, width, path, angle, flipstatus));
}

void PhysicsCollisionDemo::create_shape(float x, float y, float width, float height, bool is_dynamic)
{
	shapes.push_back(world_controller.create_shape(PhysicsCollision::Enums::ShapeEnum::Square, x, y, width, height, is_dynamic));
}

void PhysicsCollisionDemo::run()
{
	while (true)
	{
		std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> _shapes = world_controller.get_shapes();
		for (auto const& it : _shapes)
		{
			std::shared_ptr<PhysicsCollision::Models::Shape> shape = it;
				if (shape->get_is_dynamic())
				{
					sprites->at(0)->set_x(shape->get_x());
					sprites->at(0)->set_y(shape->get_y());

				}
				world_controller.simulate();
		}
		graphics_controller.update_window();
		sleep_for(5ms);
	}
	world_controller.destroy_bodies();
	graphics_controller.get_window()->destroy();
}

void PhysicsCollisionDemo::update(const Input::Enums::EventEnum& event)
{
	switch (event) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		shapes[0]->get_shape_facade()->move_x(-1);
		sprites->at(0)->set_x(shapes[0]->get_x());
		sprites->at(0)->set_flip_status(Graphics::Enums::FlipEnum::HORIZONTAL);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		shapes[0]->get_shape_facade()->move_x(1);
		sprites->at(0)->set_x(shapes[0]->get_x());
		sprites->at(0)->set_flip_status(Graphics::Enums::FlipEnum::NONE);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_UP:
		shapes[0]->get_shape_facade()->move_y();
		sprites->at(0)->set_y(shapes[0]->get_y());
		break;
	default:
		std::cout << "geen reactie";
		break;
	}
}

void PhysicsCollisionDemo::subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo)
{
	input_controller->subscribe(demo);
}
