#pragma once
#include "../Models/Abstract/Interactable.h"
#include "../interfaces/IFactory.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game.Factories
	* \brief Namespace for the factories
	*/
	namespace Factories {
		/**
		* \class InteractableFactory
		* \brief Class contains the methods to create interactables
		*/
		class InteractableFactory {
		private:
			/**
			* \brief In this vector are the light beams saved so that when the lamp of camera is drawn the beam can get the appropiate hight.
			*/
			std::vector<int> _lights;
		public:
			InteractableFactory();

			/**
			* \brief Creates the interactable
			*/
			std::shared_ptr<Models::Interactable> create(Enums::TypeEnum type, float x, float y, float z, float height, float width, Enums::DirectionEnum state, std::vector<std::tuple<float, float>> = {}, bool secret = false);
		};
	}
}