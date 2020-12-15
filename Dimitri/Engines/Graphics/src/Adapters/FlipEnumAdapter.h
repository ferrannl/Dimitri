#pragma once
#include "../Enums/FlipEnum.h"
#include <SDL.h>

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
		* \class FlipEnumAdapter
		* \brief Class contains the method to convert for converting the FlipEnum to SDL_Rendererflip
		*/
		class FlipEnumAdapter {
		public:
			/**
			* \brief Converts the FlipEnum to SDL_Rendererflip
			*/
			SDL_RendererFlip get_sdl_flip(const Enums::FlipEnum flipstatus);
		};
	}
}