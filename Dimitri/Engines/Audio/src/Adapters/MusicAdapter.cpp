#include "MusicAdapter.h"

void Adapters::MusicAdapter::play()
{
	Mix_PlayMusic(_music, -1);
}

void Adapters::MusicAdapter::resume()
{
}

void Adapters::MusicAdapter::pause()
{
}

void Adapters::MusicAdapter::stop()
{
}