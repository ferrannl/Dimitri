#include "IAudioFacade.h"

Interfaces::IAudioFacade::IAudioFacade(const char* path) : _path{ path } {}

Interfaces::IAudioFacade::~IAudioFacade()
{
	delete _path;
}
