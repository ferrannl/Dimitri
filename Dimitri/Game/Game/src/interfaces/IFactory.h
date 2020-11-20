#pragma once
#include <memory>
#include "../Enums/TypeEnum.cpp"
#include "../Enums/StateEnum.cpp"
#include <src/Models/Sprite.h>

namespace Game {
	namespace Interfaces {
		template<class T>
		class IFactory {
		public:
			virtual std::shared_ptr<T> create(Enums::TypeEnum type, int x, int y, int width, int height, int z, Enums::StateEnum state) = 0;
		};
	}
}