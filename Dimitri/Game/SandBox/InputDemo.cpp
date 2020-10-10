#include "InputDemo.h"

InputDemo::InputDemo()
{
	_inputController = std::make_shared<Controllers::InputController>();
}

std::shared_ptr<Controllers::InputController> InputDemo::get_input_controller()
{
	return _inputController;
}
