#include "PhysicsCollisionDemo.h"

PhysicsCollisionDemo::PhysicsCollisionDemo()
{
	PhysicsCollisionDemo::graphics_controller = Graphics::Controllers::GraphicsController{};
	world_controller = Controllers::WorldController{};
	input_controller = std::make_shared<Input::Controllers::InputController>();
	textures = {};
	shapes = {};
}

void PhysicsCollisionDemo::start_demo()
{
	if (create_window(1080, 720) == NULL) {
		return;
	}

	std::string image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/img.png" };
	std::string bg_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/bg.png" };
	std::string ground_end_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground_end.png" };
	std::string ground_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/ground.png" };
	std::string player_image = Utility::Helpers::get_base_path() + std::string{ "/assets/images/player.png" };

	create_sprite(350, 300, 1, 50, 100, player_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	create_sprite(300, 200, 1, 50, 50, ground_end_image.c_str(), 0, Graphics::Enums::FlipEnum::HORIZONTAL);
	create_sprite(350, 200, 1, 50, 50, ground_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	create_sprite(400, 200, 1, 50, 50, ground_end_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	// create walls around screen
	create_sprite(0, 720, 1, 1080, 1, image.c_str(), 0, Graphics::Enums::FlipEnum::HORIZONTAL);
	create_sprite(0, -1, 1, 1080, 1, image.c_str(), 0, Graphics::Enums::FlipEnum::HORIZONTAL);
	create_sprite(-1, 0, 1, 1, 720, image.c_str(), 0, Graphics::Enums::FlipEnum::HORIZONTAL);
	create_sprite(1080, 0, 1, 1, 720, image.c_str(), 0, Graphics::Enums::FlipEnum::HORIZONTAL);
	create_sprite(0, 0, 0, 1080, 720, bg_image.c_str(), 0, Graphics::Enums::FlipEnum::NONE);
	create_text("Dimitri", 450, 550, 2, 200, 100, Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" }, 0);
	create_text("het stealth spel van 2020", 450, 540, 2, 200, 30, Utility::Helpers::get_base_path() + std::string{ "/assets/fonts/font1.ttf" }, 0);
	textures = graphics_controller.get_textures();
	create_shape(350, 300, 50, 100, true);
	create_shape(300, 200, 50, 50, false);
	create_shape(350, 200, 50, 50, false);
	create_shape(400, 200, 50, 50, false);
	// create walls around screen
	create_shape(0, 720, 1080, 1, false); // top    
	create_shape(0, -1, 1080, 1, false); // bottom    
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

void PhysicsCollisionDemo::create_sprite(int x, int y, int z, int width, int height, std::string path, const float angle, Graphics::Enums::FlipEnum flipstatus)
{
	graphics_controller.add_texture(std::make_shared<Graphics::Models::Sprite>(x, y, z, height, width, angle, path, flipstatus));
}

void PhysicsCollisionDemo::create_text(std::string text, int x, int y, int z, int width, int height, std::string path, const float angle)
{
	Color color = { 255, 255, 255 };
	graphics_controller.add_texture(std::make_shared<Graphics::Models::Text>(text, color, x, y, z, height, width, angle, path));
}

void PhysicsCollisionDemo::create_shape(int x, int y, int width, int height, bool is_dynamic)
{
	std::vector<std::pair<float, float>> positions{ {0.0f,0.0f}, {0.0f,height},{width, height}, {width, 0.0f} };
	world_controller.create_shape("polygon", x, y, positions, is_dynamic);
}

void PhysicsCollisionDemo::run()
{
	while (true)
	{
		for (int i = 0; i < shapes.get()->size(); i++)
		{
			textures.at(i)->set_x(static_cast<int>(shapes.get()->at(i)->get_x()));
			textures.at(i)->set_y(static_cast<int>(shapes.get()->at(i)->get_y()));
			textures.at(i)->set_angle(static_cast<int>(shapes.get()->at(i)->get_angle()));
		}
		graphics_controller.update_window();
		world_controller.simulate();

		sleep_for(5ms);
	}
	world_controller.destroy_bodies();
	graphics_controller.get_window()->destroy();
}

void PhysicsCollisionDemo::update(const Input::Enums::EventEnum& event)
{
	switch (event) {
	case Input::Enums::EventEnum::KEY_PRESS_LEFT:
		shapes.get()->at(0)->move_x(-1);
		textures.at(0)->set_x(shapes.get()->at(0)->get_x());
		textures.at(0)->set_flip_status(Graphics::Enums::FlipEnum::HORIZONTAL);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_RIGHT:
		shapes.get()->at(0)->move_x(1);
		textures.at(0)->set_x(shapes.get()->at(0)->get_x());
		textures.at(0)->set_flip_status(Graphics::Enums::FlipEnum::NONE);
		break;
	case Input::Enums::EventEnum::KEY_PRESS_QUIT:
		exit(0);
	default:
		std::cout << "geen reactie";
	}
}

void PhysicsCollisionDemo::subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo)
{
	input_controller->subscribe(demo);
}



