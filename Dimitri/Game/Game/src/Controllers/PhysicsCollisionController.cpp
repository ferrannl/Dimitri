#include "PhysicsCollisionController.h"

Game::Controllers::PhysicsCollisionController::PhysicsCollisionController()
{
	_world_controller = std::make_unique<PhysicsCollision::Controllers::WorldController>();
}

void Game::Controllers::PhysicsCollisionController::simulate()
{
	_world_controller->simulate();
}

void Game::Controllers::PhysicsCollisionController::destroy_shapes()
{
	_world_controller->destroy_bodies();
}

std::shared_ptr<PhysicsCollision::Models::Shape> Game::Controllers::PhysicsCollisionController::create_shape(float x, float y, float width, float height, bool is_dynamic)
{
	return _world_controller->create_shape(PhysicsCollision::Enums::ShapeEnum::Square, x, y, width, height, is_dynamic);
}

bool Game::Controllers::PhysicsCollisionController::check_collision(std::shared_ptr<PhysicsCollision::Models::Shape> shape1, std::shared_ptr<PhysicsCollision::Models::Shape> shape2)
{
	return _world_controller->check_collision(shape1, shape2);
}

void Game::Controllers::PhysicsCollisionController::setup_world(const int height, const int width)
{
	_world_controller->setup_world(width, height);
}
