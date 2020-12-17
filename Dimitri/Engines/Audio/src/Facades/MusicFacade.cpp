#include "MusicFacade.h"
#include <SDL.h>
#include <SDL_mixer.h>

using namespace Audio;


Facades::MusicFacade::MusicFacade(const std::string path, int volume) : Interfaces::IAudioFacade(path, volume), _music(nullptr, Mix_FreeMusic) {

	Mix_VolumeMusic(_volume);

	_music.reset(Mix_LoadMUS(_path.c_str()));
	if (_music == NULL)
	{
		throw Exceptions::LoadAudioFailed();
	}
}

void Facades::MusicFacade::play() const
{
	Mix_PlayMusic(_music.get(), -1);
}

void Facades::MusicFacade::resume() const
{
	if (Mix_PausedMusic) {
		Mix_ResumeMusic();
	}
}

void Facades::MusicFacade::pause() const
{
	if (Mix_PlayingMusic) {
		Mix_PauseMusic();
	}
}

void Facades::MusicFacade::set_volume(int value)
{
	_volume = value;
	if (Mix_PlayingMusic) {
		Mix_VolumeMusic(_volume);
	}
}

void Facades::MusicFacade::stop() const
{
	Mix_HaltMusic();
}

bool Audio::Facades::MusicFacade::is_playing() const
{
	return Mix_PlayingMusic() != 0;
}
