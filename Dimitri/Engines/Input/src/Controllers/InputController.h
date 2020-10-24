#pragma once
#include "../Facades/EventFacade.h"
#include "../Facades/MouseFacade.h"
#include "../Interfaces/IObservable.h"
#include <SDL.h>

#ifdef _WIN64
#ifdef INPUT_EXPORTS
#define INPUT_API __declspec(dllexport)
#else 
#define INPUT_API __declspec(dllimport)
#endif
#else
#define INPUT_API
#endif


namespace Controllers {
	class INPUT_API InputController : public Interfaces::IObservable{
	private:
		//shared press events
		std::shared_ptr<Interfaces::IObserver> _observer;

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