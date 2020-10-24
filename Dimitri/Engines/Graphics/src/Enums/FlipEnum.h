#pragma once
#pragma warning( disable : 26812 )

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Enums {
	enum class GRAPHICS_API FlipEnum {
		NONE, HORIZONTAL, VERTICAL
	};
}
