#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include "../../Engines/Graphics/src/Controllers/GraphicsController.h"
#include "../../Engines/PhysicsCollision/src/Controllers/WorldController.h"
#include "../../Engines/Input/src/Controllers/InputController.h"
#include "../../Utility/src/Interfaces/IObserver.h"
#include "../../Utility/src/Helpers/BasePathHelper.h"

using namespace std::this_thread;
using namespace std::chrono_literals;

class PhysicsCollisionDemo : public Utility::Interfaces::IObserver<Input::Enums::EventEnum> {
public:
	Graphics::Controllers::GraphicsController graphicsController;
	PhysicsCollision::Controllers::WorldController worldController;
	std::shared_ptr<Input::Controllers::InputController> _inputController;
	std::shared_ptr<std::vector<std::unique_ptr<Graphics::Models::Sprite>>> sprites;
	std::vector<std::shared_ptr<PhysicsCollision::Models::Shape>> shapes;
	PhysicsCollisionDemo();
	void start_demo();
	int create_window(int width, int height);
	void create_sprite(float x, float y, float z, float height, float width, const char* path, const float angle, Graphics::Enums::FlipEnum flipstatus);
	void create_shape(float x, float y, float height, float width, bool is_dynamic);
	void run();
	void update(const Input::Enums::EventEnum& object);
	void subscribe_to_input(std::shared_ptr<PhysicsCollisionDemo> demo);
};
