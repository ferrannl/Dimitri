#pragma once
#include "../Enums/FlipEnum.h"
#include <SDL.h>

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
	* \namespace Graphics::Adapters
	* \brief Namespace for the adapters in the graphics engine
	*/
	namespace Adapters {
		/**
		* Adapter for converting the FlipEnum to SDL_Rendererflip
		*/
		class GRAPHICS_API FlipEnumAdapter {
		public:
			/**
			* Converts the FlipEnum to SDL_Rendererflip
			*/
			SDL_RendererFlip get_sdl_flip(const Enums::FlipEnum flipstatus);
		};
	}
}