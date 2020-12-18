#include "FlipEnumAdapter.h"
using namespace Graphics;

SDL_RendererFlip Adapters::FlipEnumAdapter::get_sdl_flip(Enums::FlipEnum flipstatus)
{
	switch (flipstatus) {
	case Enums::FlipEnum::HORIZONTAL:
		return SDL_FLIP_HORIZONTAL;
	case Enums::FlipEnum::VERTICAL:
		return SDL_FLIP_VERTICAL;
	default:
		return SDL_FLIP_NONE;
	}
}