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

namespace Graphics {
	/**
	* Namespace for all the Enums in the project
	*/
	namespace Enums {
		/**
		* Enum for the flip direction of the sprites
		*/
		enum class GRAPHICS_API FlipEnum {
			NONE, HORIZONTAL, VERTICAL
		};
	}
}