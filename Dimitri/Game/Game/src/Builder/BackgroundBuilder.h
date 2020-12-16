#include <vector>
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
		* \class BackgroundBuilder
		* \brief Class contains the methods to build the background
		*/
		class BackgroundBuilder {
		private:
			/**
			* \brief The tile size used for all the calculations
			*/
			const int TILE_SIZE = 40;

			/**
			* \brief Factory which creates backgrounds
			*/
			Factories::BackgroundFactory _background_factory;
		public:
			/**
			* \brief Builds the level
			*/
			void build(std::shared_ptr<Models::Level>& level, const std::pair<int, std::vector<std::vector<int>>>& tileset, const std::vector<std::vector<std::pair<std::string, std::any>>>& objects);
		};
	}
}