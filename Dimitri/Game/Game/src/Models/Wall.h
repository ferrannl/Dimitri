#pragma once
#include "IObject.h"
namespace Game {
	namespace Models {
		class Wall : public Game::Models::IObject {
		public:
			Wall(int x, int y, int z, int height, int width);
			void initialize_textures();
		};
	}
}