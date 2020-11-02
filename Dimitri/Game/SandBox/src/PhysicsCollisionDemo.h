#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <src\Controllers\GraphicsController.h>
#include <src\Controllers\InputController.h>
#include <src\Controllers\WorldController.h>
#include <src\Helpers\BasePathHelper.h>

using namespace std::this_thread;
using namespace std::chrono_literals;

class PhysicsCollisionDemo : public Utility::Interfaces::IObserver<Input::Enums::EventEnum> {
public:
	Graphics::Controllers::GraphicsController graphics_controller;
	Controllers::WorldController world_controller;
	std::shared_ptr<Input::Controllers::InputController> input_controller;
	std::vector<std::shared_ptr<Graphics::Models::Texture>> textures;
	std::shared_ptr<std::vector<std::unique_ptr<Models::Shape>>> shapes;
	PhysicsCollisionDemo();
	void start_demo();
	int create_window(int width, int height);
	void create_sprite(int x, int y, int z, int height, int width, std::string path, const float angle, Graphics::Enums::FlipEnum flipstatus);
	void create_text(std::string text, int x, int y, int z, int width, int height, std::string path, const float angle);
	void create_shape(int x, int y, int height, int width, bool is_dynamic);
	void run();
	void update(const Input::Enums::EventEnum& object);
	void subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo);
};