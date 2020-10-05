#pragma once
#include <string>
#include "../Interfaces/IAudioAdapter.h"

namespace Models {
	class __declspec(dllexport) Audio {
	private:
		std::string* _name;
		Interfaces::IAudioAdapter* _audio_adapter;
	public:
		std::string* get_name();
		Audio(std::string* name, Interfaces::IAudioAdapter* audio_adapter) : _name{ name }, _audio_adapter { audio_adapter } {};
		Interfaces::IAudioAdapter* get_audio_adapter();
	};
}