#pragma once
#include <SDL.h>

namespace Adapters {
	static class __declspec(dllexport) BasePathAdapter {
	public:
		static const char* get_base_path();
	};
}