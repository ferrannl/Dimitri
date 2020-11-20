#pragma once
#include <src\Interfaces\IObserver.h>
#include <src\Interfaces\IObservable.h>
#include <src\Models\Texture.h>
#include <..\Game\Game\src\Models\Level.h>
#include <..\Game\Game\src\Events\InputEvent.h>
#include <..\Game\Game\src\Enums\LevelStateEnum.cpp>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono_literals;

/**
*	Namespace for the game
*/
namespace Game {
	/**
	*	Namespace for the controllers
	*/
	namespace Controllers {
		/**
		*	Contains the code to controle the level model
		*/
		class LevelController : public Utility::Interfaces::IObserver<Events::InputEvent>, public Utility::Interfaces::IObservable<Enums::LevelStateEnum> {
		private:
			/**
			*	Level model
			*/
			std::shared_ptr<Game::Models::Level> _level;
			/**
			*	Simulation thread
			*/
			std::thread _simulation_thread;
			/**
			*	Keeps track of simulation thread state
			*/
			Enums::LevelStateEnum _state;
			/**
			*	List of observers
			*/
			std::vector<std::shared_ptr<Utility::Interfaces::IObserver<Enums::LevelStateEnum>>> _observers;

			/**
			*	Set the level state and stops/starts the thread
			*/
			void set_state(Enums::LevelStateEnum state);
		public:
			LevelController();

			/**
			*	List of all textures in level
			*/
			std::vector<std::shared_ptr<Graphics::Models::Texture>> get_textures() const;
			
			/**	
			*	Update received from input controller	
			*/	
			void update(const Game::Events::InputEvent& object);

			/**
			*	Returns level
			*/
			std::shared_ptr<Game::Models::Level> get_level() const;

			/**
			*	Start simulation
			*/
			void start();

			/**
			*	Stop simulation
			*/
			void stop();

			/**
			*	Simulate thread start
			*/
			void simulate();

			/**
			*	Notifies observables
			*/
			void notify(const Enums::LevelStateEnum& object);

			/**
			*	Add observer to list of observables
			*/
			void subscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::LevelStateEnum>>& observer);

			/**
			* Removes observer from list of observables
			*/
			void unsubscribe(const std::shared_ptr<Utility::Interfaces::IObserver<Enums::LevelStateEnum>>& observer);

		};
	}
}