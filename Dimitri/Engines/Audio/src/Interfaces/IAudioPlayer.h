#pragma once

namespace Interfaces {
	class __declspec(dllexport) IAudioPlayer {
	public:
		void play(std::string* audio);
		void resume(std::string* audio);
		void pause(std::string* audio);
		void stop(std::string* audio);
	};
}