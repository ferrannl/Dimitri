#pragma once

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else GRAPHICS_API __declspec(import)
#endif
#else
#define GRAPHICS_API
#endif

namespace Adapters {
	static class GRAPHICS_API BasePathAdapter {
	public:
		static const char* get_base_path();
	};
}