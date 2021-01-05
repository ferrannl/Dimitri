#include "Controllers/MainController.h"
#include <src/Controllers/DocumentController.h>

#undef main
int main() {
	try {
		auto controller = std::make_shared<Game::Controllers::MainController>();
		controller->run();
	}
	catch (std::exception e) {
		std::cout << std::endl << "Woops, something went wrong!" << std::endl;
		std::cout << std::endl << e.what() << std::endl;
	}
	catch (...) {
		std::cout << std::endl << "Woops, something went wrong! - Unknown" << std::endl;
	}

	return 0;
}