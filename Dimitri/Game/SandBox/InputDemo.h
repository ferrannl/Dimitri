#pragma once
#include "../../Engines/Input/src/Controllers/InputController.h"

class InputDemo {
private:
	std::shared_ptr<Controllers::InputController> _inputController;

public:
	InputDemo();
	std::shared_ptr<Controllers::InputController> get_input_controller();
};