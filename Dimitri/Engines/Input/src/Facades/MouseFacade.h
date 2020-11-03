#pragma once
#include <tuple>

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif
namespace Input {
	namespace Facades {
		class INPUT_API MouseFacade {
		public:
			std::tuple<int, int> get_mouse_position() const;
		};
	}
}