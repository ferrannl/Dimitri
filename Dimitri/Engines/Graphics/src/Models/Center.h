#pragma once
#include <cstdint>

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

/**
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Models
	* \brief Namespace for the models in the graphics engine
	*/
	namespace Models {
		/**
		* \struct Color
		* \brief Struct contains the RGB values of a color
		*/
		struct GRAPHICS_API Center {
		public:
			int x;
			int y;
		};
	}
}