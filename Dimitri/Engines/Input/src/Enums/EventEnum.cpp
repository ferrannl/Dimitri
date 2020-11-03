#pragma once

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif

/**
* Namespace for the input engine
*/
namespace Input {
	/**
	* Namespace for the enums
	*/
	namespace Enums {
		/**
		* All key and mouse events that can be fired
		*/
		enum class INPUT_API EventEnum
		{
			NOT_SUPPORTED,
			KEY_PRESS_UP,
			KEY_PRESS_RIGHT,
			KEY_PRESS_LEFT,
			KEY_PRESS_DOWN,
			MOUSE_PRESSED,
			MOUSE_PRESSED_RIGHT,
			MOUSE_PRESSED_LEFT,
			MOUSE_MOTION,
			KEY_PRESS_A,
			KEY_PRESS_B,
			KEY_PRESS_C,
			KEY_PRESS_D,
			KEY_PRESS_E,
			KEY_PRESS_F,
			KEY_PRESS_G,
			KEY_PRESS_H,
			KEY_PRESS_I,
			KEY_PRESS_J,
			KEY_PRESS_K,
			KEY_PRESS_L,
			KEY_PRESS_M,
			KEY_PRESS_N,
			KEY_PRESS_O,
			KEY_PRESS_P,
			KEY_PRESS_Q,
			KEY_PRESS_R,
			KEY_PRESS_S,
			KEY_PRESS_T,
			KEY_PRESS_U,
			KEY_PRESS_V,
			KEY_PRESS_W,
			KEY_PRESS_X,
			KEY_PRESS_Y,
			KEY_PRESS_Z,
			KEY_PRESS_ESC,
			KEY_PRESS_CTRL,
			KEY_PRESS_ENTER,
			KEY_PRESS_BACKSPACE,
			KEY_PRESS_SHIFT,
			KEY_PRESS_0,
			KEY_PRESS_1,
			KEY_PRESS_2,
			KEY_PRESS_3,
			KEY_PRESS_4,
			KEY_PRESS_5,
			KEY_PRESS_6,
			KEY_PRESS_7,
			KEY_PRESS_8,
			KEY_PRESS_9
		};
	}
}