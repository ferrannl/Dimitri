#pragma once
#include "../Models/Sprite.h"

namespace RAIIs {
	class SpriteRAII {
	private:
		Models::Sprite* _sprite;
	public:
		SpriteRAII(Models::Sprite* sprite);
		~SpriteRAII();
	};
}