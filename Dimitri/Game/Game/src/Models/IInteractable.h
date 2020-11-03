#pragma once
#include "IObject.h"
namespace Game {
	namespace Models {
		class IInteractable : public Game::Models::IObject{
		public:
			IInteractable(int x, int y, int z, int height, int width);
			virtual void interact() = 0;
		};
	}
}