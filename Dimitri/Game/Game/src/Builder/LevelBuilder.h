#include "../Models/Level.h"
#include <vector>
#include "../Factory/ObjectFactory.h";
#include "../Factory/InteractableFactory.h";

namespace Game {
	namespace Builder {
		class LevelBuilder {
		private:
			const int TILE_SIZE = 40;
			const int _width;
			const int _height;
			Factories::ObjectFactory _objectFactory;
			Factories::InteractableFactory _interactableFactory;

		public:
			LevelBuilder(const int width, const int height);
			std::shared_ptr<Game::Models::Level> Build(std::vector<std::vector<int>>);

		};
	}
}