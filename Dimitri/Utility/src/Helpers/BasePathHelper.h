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
#define UTILITY_API
#endif

namespace Utility {
	namespace Helpers {
		/**
		* Gets the path to the executable of the project 
		*/
		UTILITY_API std::string get_base_path();
	}
}