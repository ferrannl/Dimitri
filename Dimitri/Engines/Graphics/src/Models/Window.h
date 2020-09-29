#pragma once
#include <string> 
namespace Models {
	class Window {
	private:
		int _x;
		int _y;
		int _height;
		int _width;
		const char* _title;
	public:
		Window(const int x, const int y, const int height, const int width, const char* title) 
			: _x{ x }, _y{ y }, _height{ height }, _width{ width }, _title{ title } {}

		const int getX();
		const int getY();
		const int getHeight();
		const int getWidth();
		const char* getTitle();
	};
}