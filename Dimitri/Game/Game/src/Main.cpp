#include "Controllers/MainController.h"

#undef main
int main() {
	auto controller = std::make_shared<Game::Controllers::MainController>();
	controller.get()->run();
	return 0;
}