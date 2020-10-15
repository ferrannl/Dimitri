#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "../../Engines/Graphics/src/Controllers/GraphicsController.h"
#include "../../Engines/PhysicsCollision/src/Controllers/WorldController.h"
#include "../../Engines/Input/src/Controllers/InputController.h"
#include "../../Utility/src/Interfaces/IObserver.h"

using namespace std::this_thread;
using namespace std::chrono_literals;

class PhysicsCollisionDemo : public Interfaces::IObserver<Enums::EventEnum> {
public:
	Controllers::GraphicsController graphicsController;
	Controllers::WorldController worldController;
	std::shared_ptr<Controllers::InputController> _inputController;
	std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites;
	std::vector<Models::Shape> shapes;
	PhysicsCollisionDemo();
	void start_demo();
	int create_window(int width, int height);
	void create_sprite(int x, int y, int z, int height, int width, const char* path, const float angle, Enums::FlipEnum flipstatus);
	void create_shape(int x, int y, int height, int width, bool is_dynamic);
	void run();
	void update(const Enums::EventEnum& object);
	void subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo);
};