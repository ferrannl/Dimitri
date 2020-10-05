#include "SoundAdapter.h"

void Adapters::SoundAdapter::play()
{
	Mix_PlayChannel(-1, _sound, 0);
}

void Adapters::SoundAdapter::resume()
{
	
}

void Adapters::SoundAdapter::pause()
{
}

void Adapters::SoundAdapter::stop()
{
}