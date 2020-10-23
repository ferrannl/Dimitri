#pragma once
#include <iostream>
#include "GraphicsController.h"
#include "BasePathAdapter.h"
//#include "../../Engines/Graphics/src/Controllers/GraphicsController.h"
#include "../../Engines/PhysicsCollision/src/Controllers/WorldController.h"
//#include "../../Engines/Graphics/src/Adapters/BasePathAdapter.h"
#include "../../Engines/Input/src/Controllers/InputController.h"

#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;


class PhysicsCollisionDemo : public Interfaces::IObserver {
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
	void update(Enums::EventEnum event);
	void subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo);
};