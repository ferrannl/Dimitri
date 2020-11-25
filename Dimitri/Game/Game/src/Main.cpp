#include "Controllers/MainController.h"

#undef main
int main() {
	try {
		auto controller = std::make_shared<Game::Controllers::MainController>();
		controller->run();
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}