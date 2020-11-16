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

void Game::Controllers::PhysicsCollisionController::load_shape(const std::shared_ptr<PhysicsCollision::Models::Shape>& _shape)
{
	_world_controller->load_shape(_shape);
}
