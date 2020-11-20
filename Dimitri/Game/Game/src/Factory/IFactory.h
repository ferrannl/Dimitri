#pragma once
#include "../Enums/TypeEnum.cpp"
#include <string>

namespace Game {
	namespace Factories {
		template <class T, class E>
		class IFactory {
		public:
			virtual void register_type(E type, T* object) = 0;
			virtual T* create(E type) = 0;
		};
	}
}