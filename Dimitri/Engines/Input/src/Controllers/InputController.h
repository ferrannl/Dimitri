#pragma once
#include <tuple>
#include <memory>
#include <vector>
#include "../enums/EventEnum.cpp"
#include "../Facades/EventFacade.h"
#include "../Facades/MouseFacade.h"
#include "../Interfaces/IObservable.h"

namespace Controllers {
	class __declspec(dllexport) InputController : public Interfaces::IObservable{
	private:
		//shared press events
		std::shared_ptr<std::vector<std::shared_ptr<Interfaces::IObserver>>> _observers;
		//Facades
		std::unique_ptr<Facades::MouseFacade> _mouse_facade;
		std::unique_ptr<Facades::EventFacade> _event_facade;
		
	public:
		InputController();
		std::tuple<int, int> get_mouse_position();

		void notify(Enums::EventEnum event);
		void subscribe(std::shared_ptr<Interfaces::IObserver> observer);
		void poll_events();
	};
}