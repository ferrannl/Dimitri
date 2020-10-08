#pragma once

namespace Interfaces {
	class __declspec(dllexport) IAudioFacade {
	protected:
		const char* _path;
	public:
		IAudioFacade(const char* path);
		virtual void play() = 0;
		virtual void resume() = 0;
		virtual void pause() = 0;
		virtual void stop() = 0;

		// forbid copying and moving
		IAudioFacade(const IAudioFacade& i_audio_facade) = delete;
		IAudioFacade& operator=(const IAudioFacade& i_audio_facade) = delete;
		IAudioFacade(IAudioFacade&& i_audio_facade) = delete;
		IAudioFacade& operator=(IAudioFacade&& i_audio_facade) = delete;

		~IAudioFacade();
	};
}