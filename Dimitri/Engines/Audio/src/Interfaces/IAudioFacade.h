#pragma once
#include <string>
#include <memory>
#include "../Exceptions/AudioExceptions.h"
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

#ifdef _WIN64
#ifdef AUDIO_EXPORTS
#define AUDIO_API __declspec(dllexport)
#else AUDIO_API __declspec(import)
#endif
#else
#define AUDIO_API
#endif

namespace Interfaces {
	class AUDIO_API IAudioFacade {
	protected:
		const std::string _path;
	public:
		IAudioFacade(const std::string path);
		virtual void play() const = 0;
		virtual void resume() const = 0;
		virtual void pause() const = 0;
		virtual void stop() const = 0;
	};
}