#include "SoundFacade.h"
#include <SDL.h>
#include <SDL_mixer.h>

using namespace Audio;

Facades::SoundFacade::SoundFacade(const std::string path, int channel) : Interfaces::IAudioFacade(path), _channel{ channel }, _sound(nullptr, Mix_FreeChunk) {
	_sound.reset( Mix_LoadWAV(_path.c_str()));
	if (_sound == NULL)
	{
		throw Exceptions::LoadAudioFailed();
	}
}

void Facades::SoundFacade::play() const
{
	Mix_PlayChannel(_channel, _sound.get(), 0);
}

void Facades::SoundFacade::resume() const
{
	if (Mix_Paused(_channel)) {
		Mix_Resume(_channel);
	}
}

void Facades::SoundFacade::pause() const
{
	if (Mix_Playing(_channel)) {
		Mix_Pause(_channel);
	}
}

void Facades::SoundFacade::stop() const
{
	Mix_HaltChannel(_channel);
}

bool Audio::Facades::SoundFacade::is_playing() const
{
	return Mix_Playing(_channel) != 0;
}
