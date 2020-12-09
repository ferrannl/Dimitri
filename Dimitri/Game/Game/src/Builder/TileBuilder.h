#include <vector>
#include "../Factory/ObjectFactory.h";
#include "../Factory/InteractableFactory.h";
#include "../Factory/UpdatableFactory.h";
#include "../Factory/BackgroundFactory.h";
#include "../Models/Level.h"
#include <any>

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
		class TileBuilder {
		private:
			/**
			* \brief The tile size used for all the calculations
			*/
			const int TILE_SIZE = 40;

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
		public:
			/**
			* \brief Builds the level
			*/
			void build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset);
		};
	}
}