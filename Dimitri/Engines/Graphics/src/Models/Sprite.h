#pragma once
#include "../Facades/TextureFacade.h"
#include "../Facades/SpriteFacade.h"
#include "../Enums/FlipEnum.h"
#include "Texture.h"

namespace Graphics {
	namespace Models {
		class __declspec(dllexport) Sprite : public Texture {
		public:
			Sprite(const int x, const int y, const int z, const int height, const int width, const float angle, const std::string path, const Enums::FlipEnum flipstatus);	
			void create_texture_facade();
			bool matches(const std::shared_ptr<Models::Texture>& texture) const;
		};
	}
}