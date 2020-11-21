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

/**
* \namespace Utility
* \brief Namespace for the utility project
*/
namespace Utility {
	/**
	* \namespace Utility::Helpers
	* \brief Namespace for the helpers in the utility project
	*/
	namespace Helpers {
		/**
		* \brief Returns the path to the executable of the project 
		*/
		UTILITY_API std::string get_base_path();
	}
}