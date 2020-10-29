#pragma once
#include <string>
#include <windows.h>

#ifdef _WIN64
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else 
#define UTILITY_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

namespace Utility {
	namespace Helpers {
		UTILITY_API std::string get_base_path();
	}
}