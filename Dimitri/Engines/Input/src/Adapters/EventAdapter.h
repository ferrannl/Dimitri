#pragma once
#include <memory>
#include "MouseAdapter.h"
#include "KeyBoardAdapter.h"
namespace Adapters {
	class __declspec(dllexport) EventAdapter{
	private:
		std::shared_ptr<Interfaces::IInputAdapter> _input_adapter;

	public:
		Enums::EventEnum translate_to_enum(const SDL_Event event);
	};
}