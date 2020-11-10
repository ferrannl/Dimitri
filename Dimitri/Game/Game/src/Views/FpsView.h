#pragma once
#include <memory>
#include <src\Controllers\GraphicsController.h>
#include <src\Helpers\BasePathHelper.h>
#include "View.h"
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the views
	*/
	namespace Views {
		/**
		*	Containing all the code to draw the fps using the graphics controller
		*/
		class FpsView : public View {
		};
	}
}
