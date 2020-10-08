#pragma once

namespace Interfaces {
	class __declspec(dllexport) IAudioFacade {
	protected:
		const char* _path;
	public:
		IAudioFacade(const char* path);
		virtual void play() const = 0;
		virtual void resume() const = 0;
		virtual void pause() const = 0;
		virtual void stop() const = 0;

		// forbid copying and moving
		IAudioFacade(const IAudioFacade& i_audio_facade) = delete;
		IAudioFacade& operator=(const IAudioFacade& i_audio_facade) = delete;
		IAudioFacade(IAudioFacade&& i_audio_facade) = delete;
		IAudioFacade& operator=(IAudioFacade&& i_audio_facade) = delete;

		~IAudioFacade();
	};
}