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
	/*return _world_controller->create_shape(PhysicsCollision::Enums::ShapeEnum::Square, x, y, width, height, is_dynamic);*/
}
