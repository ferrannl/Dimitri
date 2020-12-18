#pragma once
#include "../Facades/TextureFacade.h"
#include "../Facades/SpriteFacade.h"
#include "../Enums/FlipEnum.h"
#include "Texture.h"

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
		* \class Sprite
		* \brief Class contains the data to render an image
		*/
		class GRAPHICS_API Sprite : public Texture {
		public:
			Sprite(float x, float y, float z, float height, float width, float angle, const std::string& path, Enums::FlipEnum flipstatus, bool visible, const Models::Center center, bool is_dynamic, int opacity = 100);

			/**
			* \brief Creates the TextureFacade
			*/
			void create_texture_facade();

			/**
			* \brief Checks if this Texure matches the given Texture
			*/
			bool matches(const std::shared_ptr<Models::Texture>& texture) const;
		};
	}
}
