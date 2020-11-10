#include "Controllers/MainController.h"

int wmain() {
	auto controller = std::make_shared<Game::Controllers::MainController>();
	controller.get()->run();
	return 0;
}