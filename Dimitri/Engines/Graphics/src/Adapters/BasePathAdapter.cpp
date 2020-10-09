#include "BasePathAdapter.h"

const char* Adapters::BasePathAdapter::get_resource_path()
{
	return SDL_GetBasePath();;
}