#include "IInteractable.h"

Game::Models::IInteractable::IInteractable(int x, int y, int z, int height, int width, Game::Enums::StateEnum state) : Game::Models::IObject(x, y, z, height, width, state)
{
}
