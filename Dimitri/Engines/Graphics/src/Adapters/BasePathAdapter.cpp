#include "BasePathAdapter.h"

const char* Adapters::BasePathAdapter::get_assets_path()
{
	return SDL_GetBasePath();;
}