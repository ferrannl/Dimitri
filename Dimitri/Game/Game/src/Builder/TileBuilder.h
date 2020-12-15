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
		public:
			/**
			* \brief Builds the level
			*/
			void build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset, const std::vector<std::vector<std::pair<std::string, std::any>>>& objects);

			/**
			* \brief Gets the tiled object from the list
			*/
			const std::vector<std::pair<std::string, std::any>> get_object(const std::vector<std::vector<std::pair<std::string, std::any>>>& objects, const int x, const int y);

			/**
			* \brief Gets all the light coordinates for the switches
			*/
			std::vector<std::tuple<float, float>> get_lights(std::vector<std::pair<std::string, std::any>> object);

			/**
			* \brief Get value from the tiled object
			*/
			template<typename T>
			const T get_value(std::string name, const std::vector<std::pair<std::string, std::any>>& object) {
				for (std::pair<std::string, std::any> value : object) {
					if (value.first == name) {
						return std::any_cast<T>(value.second);
					}
				}

				if (std::is_same<T, bool>::value) {
					return false;
				}
			}
		};
	}
}