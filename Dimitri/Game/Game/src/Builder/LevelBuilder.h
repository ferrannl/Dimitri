#include <vector>
#include "../Factory/BackgroundFactory.h";
#include "../Builder/TileBuilder.h";
#include "../Builder/BackgroundBuilder.h";
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
		class LevelBuilder {
		private:
			/**
			* \brief The tile size used for all the calculations 
			*/
			const int TILE_SIZE = 40;
			
			/**
			* \brief Builder for the tiles
			*/
			Builder::TileBuilder _tile_builder;

			/**
			* \brief Builder for the backgrounds
			*/
			Builder::BackgroundBuilder _background_builder;

			/**
			* \brief Factory which creates backgrounds
			*/
			Factories::BackgroundFactory _background_factory;

			/**
			* \brief Builds invisible borders for the level
			*/
			void build_borders(std::shared_ptr<Models::Level>& level);
		public:
			/**
			* \brief Builds the level
			*/
			std::shared_ptr<Models::Level> build(const std::pair<std::vector<std::pair<int, std::vector<std::vector<int>>>>, std::vector<std::vector<std::pair<std::string, std::any>>>>& level_layers, const std::shared_ptr<Controllers::AudioController> audio_controller, const std::shared_ptr<Controllers::WindowController> window_controller);
		};
	}
}