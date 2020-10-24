#pragma once
#include <string>
#include <windows.h>
namespace Utility {
	namespace Helpers {
		__declspec(dllexport) std::string get_base_path();
	}
}