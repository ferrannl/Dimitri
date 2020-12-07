#include <iostream>
#include <src\Controllers\GraphicsController.h>

#undef main
int main() {
	std::cout << "Hallo Wereld";
	std::shared_ptr<Graphics::Controllers::GraphicsController> g_ctlr = std::make_shared<Graphics::Controllers::GraphicsController>();

	g_ctlr->create_window("Demo", 720, 1280);

	while (true) {
		
	}
}