#include "MusicFacade.h"

void Facades::MusicFacade::play()
{
	Mix_PlayMusic(_music, -1);
}

void Facades::MusicFacade::resume()
{
	if (Mix_PausedMusic) {
		Mix_ResumeMusic();
	}
}

void Facades::MusicFacade::pause()
{
	if (Mix_PlayingMusic) {
		Mix_PauseMusic();
	}
}

void Facades::MusicFacade::stop()
{
	Mix_HaltMusic();
}