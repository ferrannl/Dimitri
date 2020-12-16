#include "Controllers/MainController.h"
#include <src/Controllers/DocumentController.h>

#undef main
int main() {

	DocumentHandler::Controllers::DocumentController dc = {};
	std::vector<std::vector<int>> data = {};
	std::vector <int> one = {};
	one.push_back(1);
	std::vector <int> two = {};
	two.push_back(2);
	data.push_back(one);
	data.push_back(two);

	std::string path = Utility::Helpers::get_base_path() + std::string{ "/assets/saves/save1.txt" };

	dc.Write(path, data);

	dc.Read(path);

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