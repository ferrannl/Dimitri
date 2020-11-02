#pragma once
#include <cstdint>

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
* Holds the RGB values of a color
*/
struct GRAPHICS_API Color {
public:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
};