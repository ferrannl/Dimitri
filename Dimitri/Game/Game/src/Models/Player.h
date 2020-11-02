#pragma once
#include "IObject.h"
namespace Game {
	namespace Models {
		class Player : public Game::Models::IObject{
		public:
			Player(int x, int y, int z, int height, int width);
			void initialize_textures();
		};
	}
}