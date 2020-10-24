#include "BasePathAdapter.h"

const char* Adapters::BasePathAdapter::get_base_path()
{
	return SDL_GetBasePath();
}