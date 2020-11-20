#include <vector>
#include "../Factory/ObjectFactory.h";
#include "../Factory/InteractableFactory.h";
#include "../Factory/BackgroundFactory.h";
#include "../Models/Level.h"

namespace Game {
	namespace Builder {
		class LevelBuilder {
		private:
			const int TILE_SIZE = 40;

			Factories::ObjectFactory _objectFactory;
			Factories::InteractableFactory _interactableFactory; 
			Factories::BackgroundFactory _backgroundFactory;
			void build_background(std::shared_ptr<Game::Models::Level>& level, const int width, const int height);
		public:
			LevelBuilder();
			std::shared_ptr<Game::Models::Level> build(std::vector<std::vector<int>>);

		};
	}
}