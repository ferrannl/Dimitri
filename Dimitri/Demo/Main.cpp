#include <iostream>
#include <src\Controllers\GraphicsController.h>

#undef main
int main() {
	std::cout << "Hallo Wereld";
	Graphics::Controllers::GraphicsController g_ctlr = {};

	g_ctlr.create_window("Demo", 720, 1280);
}