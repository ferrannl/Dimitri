#pragma once
#include "../Interfaces/IAudioFacade.h"
#include "../Exceptions/AudioExceptions.h"

namespace Facades {
	class __declspec(dllexport) SoundFacade : public Interfaces::IAudioFacade {
	private:
		std::unique_ptr<Mix_Chunk, decltype (&Mix_FreeChunk)> _sound;
		const int _channel;
	public:
		SoundFacade(const std::string path, int channel);
		void play() const;
		void resume() const;
		void pause() const;
		void stop() const;
	};
}