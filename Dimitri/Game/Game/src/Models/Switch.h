#pragma once
#include "IInteractable.h"
namespace Game {
	namespace Models {
		class Switch : public Game::Models::IInteractable {
		public:
			Switch(int x, int y, int z, int height, int width);
			void initialize_textures();
			void interact();
		};
	}
}