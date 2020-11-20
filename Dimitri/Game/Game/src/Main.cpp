#include "Controllers/MainController.h"

#undef main
int main() {
	try {
		auto controller = std::make_shared<Game::Controllers::MainController>();
		controller->run();
	}
	catch (std::exception e) {
		std::cout << std::endl << "Woops, something went wrong!" << std::endl;
	}

	return 0;
}