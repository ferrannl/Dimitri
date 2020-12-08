#include <vector>
#include "../Factory/ObjectFactory.h";
#include "../Factory/InteractableFactory.h";
#include "../Factory/UpdatableFactory.h";
#include "../Factory/BackgroundFactory.h";
#include "../Models/Level.h"

/**
* \namespace Game
* \brief Namespace for the game
*/
namespace Game {
	/**
	* \namespace Game.Builder
	* \brief Namespace for the builder
	*/
	namespace Builder {
		/**
		* \class LevelBuilder
		* \brief Class contains the methods to build a level
		*/
		class LevelBuilder {
		private:
			/**
			* \brief The tile size used for all the calculations 
			*/
			const float TILE_SIZE = 40;

			/**
			* \brief Factory which creates static tiles
			*/
			Factories::ObjectFactory _object_factory;
			
			/**
			* \brief Factory which creates interactables
			*/
			Factories::InteractableFactory _interactable_factory;

			/**
			* \brief Factory which creates updatables
			*/
			Factories::UpdatableFactory _updatable_factory;

			/**
			* \brief Factory which creates backgrounds
			*/
			Factories::BackgroundFactory _background_factory;

			/**
			* \brief Builds the backgrounds for the level
			*/
			void build_background(std::shared_ptr<Models::Level>& level);

			/**
			* \brief Builds invisible borders for the level
			*/
			void build_borders(std::shared_ptr<Models::Level>& level);
		public:
			/**
			* \brief Builds the level
			*/
			std::shared_ptr<Models::Level> build(std::vector<std::vector<int>>, const std::shared_ptr<Controllers::AudioController> audio_controller, const std::shared_ptr<Controllers::WindowController> window_controller);
		};
	}
}