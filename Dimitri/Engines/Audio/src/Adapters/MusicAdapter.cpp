#include "MusicAdapter.h"

void Adapters::MusicAdapter::play()
{
	Mix_PlayMusic(_music, -1);
}

void Adapters::MusicAdapter::resume()
{
	if (Mix_PausedMusic) {
		Mix_ResumeMusic();
	}
}

void Adapters::MusicAdapter::pause()
{
	if (Mix_PlayingMusic) {
		Mix_PauseMusic();
	}
}

void Adapters::MusicAdapter::stop()
{
	Mix_HaltMusic();
}