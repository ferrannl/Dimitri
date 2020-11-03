#pragma once
#include "Shape.h"
#include "../Facades/WorldFacade.h"

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else
#define PHYSICSCOLLISION_API __declspec(dllimport)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace PhysicsCollision {
	namespace Models {
		class PHYSICSCOLLISION_API World {
		private:
			Facades::WorldFacade _world_facade;
			std::vector<std::shared_ptr<Models::Shape>> _shapes;
		public:
			World();
			World(const float width, const float height);
			void add_shape(std::shared_ptr<Models::Shape> shape);
			std::vector<std::shared_ptr<Models::Shape>> get_shapes()const;
			void destroy_bodies();
			void simulate();
		};
	}
}
