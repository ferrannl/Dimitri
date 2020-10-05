#pragma once
#include "../../Engines/Graphics/src/Controllers/GraphicsController.h"
#include "../../Engines/PhysicsCollision/src/Controllers/WorldController.h"
#include "../../Engines/Input/src/events/InputEvent.h"

class PhysicsCollisionDemo {
public: 
	InputEvent* inputEvent;
	Controllers::GraphicsController graphicsController;
	Controllers::WorldController worldController;
	std::vector<Models::Sprite*> sprites;
	std::vector<Models::Shape> shapes;
	PhysicsCollisionDemo();
	void start_demo();
	void create_window(int width, int height);
	void create_sprite(int x, int y, int z, int height, int width, const char* path);
	void create_shape(int x, int y, int height, int width, bool is_dynamic);
	void run();
};