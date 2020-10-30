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

namespace Graphics {
	namespace Models {
		class GRAPHICS_API Sprite : public Texture {
		public:
			Sprite(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path, const Enums::FlipEnum flipstatus);	
			void create_texture_facade();
			bool matches(const std::shared_ptr<Models::Texture>& texture) const;
		};
	}
}
