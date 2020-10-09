#pragma once
#include "../../Engines/Graphics/src/Controllers/GraphicsController.h"
#include "../../Engines/PhysicsCollision/src/Controllers/WorldController.h"
#include "../../Engines/Input/src/interfaces/IObserver.h"
//#include "../../Engines/Input/src/adapters/EventFacade.h"
#include <thread>
#include <iostream>
#include "../../Engines/Input/src/Controllers/InputController.h"

class PhysicsCollisionDemo : public Interfaces::IObserver {
public: 
	Controllers::GraphicsController graphicsController;
	Controllers::WorldController worldController;
	std::unique_ptr<Controllers::InputController> inputController;
	std::shared_ptr<std::vector<std::unique_ptr<Models::Sprite>>> sprites;
	std::vector<Models::Shape> shapes;
	PhysicsCollisionDemo();
	void start_demo();
	int create_window(int width, int height);
	void create_sprite(int x, int y, int z, int height, int width, const char* path, const float angle, Enums::FlipEnum flipstatus);
	void create_shape(int x, int y, int height, int width, bool is_dynamic);
	void run();
	void update(Enums::EventEnum event);
};