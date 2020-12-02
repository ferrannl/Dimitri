#include "PhysicsCollisionDemo.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	PhysicsCollisionDemo::graphics_controller = Graphics::Controllers::GraphicsController{};
	world_controller = PhysicsCollision::Controllers::WorldController{};
	input_controller = std::make_shared<Input::Controllers::InputController>();
	textures = {};
	shapes = {};
}

void PhysicsCollisionDemo::start_demo()
{
	if (create_window(1080, 720) == NULL) {
		return;
	}

	std::string bg_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" };
	std::string ground_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/wall.png" };
	std::string player_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/player.png" };
	create_sprite(350, 300, 1, 50, 100, player_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	create_sprite(300, 200, 1, 300, 50, ground_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	create_sprite(0, 0, 0, 1080, 720, bg_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	create_sprite(0, 0, 0, 1080, 720, bg_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);

	create_text("Dimitri", 450, 550, 2, 200, 100, Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" }, 0);
	create_text("het stealth spel van 2020", 450, 540, 2, 200, 30, Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" }, 0);
	textures = graphics_controller.get_textures();
	create_shape(350, 300, 50, 100, true);
	create_shape(300, 200, 300, 50, false);

	// create walls around screen
	create_shape(0, 721, 1080, 1, false); // top
	create_shape(0, -1, 1080, 1, false); // bottom
	create_shape(-1, 0, 1, 720, false); // left
	create_shape(1081, 0, 1, 720, false); // right
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

void PhysicsCollisionDemo::create_sprite(int x, int y, int z, int width, int height, std::string path, const float angle, Graphics::Enums::FlipEnum flipstatus)
{
	graphics_controller.add_texture(std::make_shared<Graphics::Models::Sprite>(x, y, z, height, width, angle, path, flipstatus, true));
}

void PhysicsCollisionDemo::create_text(std::string text, int x, int y, int z, int width, int height, std::string path, const float angle)
{
	Graphics::Models::Color color = { 255, 255, 255 };
	graphics_controller.add_texture(std::make_shared<Graphics::Models::Text>(text, color, x, y, z, height, width, angle, path, true));
}

void PhysicsCollisionDemo::create_shape(float x, float y, float width, float height, bool is_dynamic)
{
	//shapes.push_back(world_controller.create_shape(PhysicsCollision::Enums::ShapeEnum::Square, x, y, width, height, is_dynamic));
}

void PhysicsCollisionDemo::run()
{
	while (true)
	{
		for (int i = 0; i < shapes.size(); i++)
		{
			if (shapes.at(i) != nullptr && textures.at(i) != nullptr)
			{
				textures.at(i)->set_x(static_cast<int>(shapes.at(i)->get_x()));
				textures.at(i)->set_y(static_cast<int>(shapes.at(i)->get_y()));
				textures.at(i)->set_angle(static_cast<int>(shapes.at(i)->get_angle()));
			}
			//world_controller.check_collision(shapes.at(0), shapes.at(1));
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
		shapes.at(0)->move_x(-1);
		textures.at(0)->set_x(shapes.at(0)->get_x());
		textures.at(0)->set_flip_status(Graphics::Enums::FlipEnum::HORIZONTAL);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		shapes.at(0)->move_x(1);
		textures.at(0)->set_x(shapes.at(0)->get_x());
		textures.at(0)->set_flip_status(Graphics::Enums::FlipEnum::NONE);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_UP:
		shapes.at(0)->move_y();
		textures.at(0)->set_y(shapes.at(0)->get_y());
		textures.at(0)->set_flip_status(Graphics::Enums::FlipEnum::NONE);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_QUIT:
		exit(0);
	default:
		std::cout << "geen reactie";
		break;
	}
}

void PhysicsCollisionDemo::subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo)
{
	input_controller->subscribe(demo);
}
