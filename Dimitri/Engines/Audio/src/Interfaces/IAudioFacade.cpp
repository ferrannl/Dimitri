#include "IAudioFacade.h"
#include <SDL.h>
#include <SDL_mixer.h>

Interfaces::IAudioFacade::IAudioFacade(const std::string path) : _path{ path } {
	try {
		//Initialize SDL
		if (SDL_Init(SDL_INIT_AUDIO) < 0)
		{
			throw Exceptions::SDLAudioInitFailed();
		}

		//Initialize SDL_mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			throw Exceptions::SDLMixerInitFailed();
		}
	}
	catch (Exceptions::SDLAudioInitFailed e) {
		std::cout << e.get() << std::endl;
	}
	catch (Exceptions::SDLMixerInitFailed e) {
		std::cout << e.get() << std::endl;
	}
}
