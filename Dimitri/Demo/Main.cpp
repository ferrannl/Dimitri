#include "../Demo/Demo.h"

#undef main
int main() {
	std::shared_ptr<Demo::Demo> d = std::make_shared<Demo::Demo>();
	d->setup();
}