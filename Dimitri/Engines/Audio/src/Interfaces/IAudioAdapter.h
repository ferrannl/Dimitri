#pragma once

namespace Interfaces {
	class __declspec(dllexport) IAudioAdapter {
	protected:
		const char* _path;
	public:
		IAudioAdapter(const char* path) : _path{ path } {}
		virtual void play() = 0;
		virtual void resume() = 0;
		virtual void pause() = 0;
		virtual void stop() = 0;
	};
}