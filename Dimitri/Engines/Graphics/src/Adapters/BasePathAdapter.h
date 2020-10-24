#pragma once
#include <string>
#include <SDL.h>

#ifdef _WIN64
#ifdef GRAPHICS_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else 
#define GRAPHICS_API __declspec(dllimport)
#endif
#else
#define GRAPHICS_API
#endif

/**
* Namespace for all the Adapters in the project
*/
namespace Adapters {
	/**
	* Adapter for returning the basepath of the project
	*/
	static class GRAPHICS_API BasePathAdapter {
	public:

		/**
		* returns the basepath of the project
		*/
		static const char* get_base_path();
	};
}