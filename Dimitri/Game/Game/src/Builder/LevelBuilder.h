#include <vector>
#include "../Factory/ObjectFactory.h";
#include "../Factory/InteractableFactory.h";
#include "../Factory/BackgroundFactory.h";
#include "../Models/Level.h"

/**
* Namespace for the game
*/
namespace Game {
	namespace Builder {
		class LevelBuilder {
		private:
			const int TILE_SIZE = 40;

			Factories::ObjectFactory _objectFactory;
			Factories::InteractableFactory _interactableFactory;
			Factories::BackgroundFactory _backgroundFactory;

			void build_background(std::shared_ptr<Models::Level>& level);
			void build_borders(std::shared_ptr<Models::Level>& level);
		public:
			std::shared_ptr<Models::Level> build(std::vector<std::vector<int>>, const std::shared_ptr<Controllers::AudioController> audio_controller);
		};
	}
}