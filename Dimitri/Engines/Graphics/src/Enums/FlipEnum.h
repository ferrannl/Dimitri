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

/**
* \namespace Graphics
* \brief Namespace for the graphics engine
*/
namespace Graphics {
	/**
	* \namespace Graphics::Enums
	* \brief Namespace for the enums in the graphics engine
	*/
	namespace Enums {
		/**
		* \enum FlipEnum
		* \brief Enum Class contains the flip direction of the sprites
		*/
		enum class GRAPHICS_API FlipEnum {
			NONE, HORIZONTAL, VERTICAL
		};
	}
}