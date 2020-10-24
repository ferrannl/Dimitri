#pragma once
#include <vector>
#include "../Models/Shape.h"

#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else PHYSICSCOLLISION_API __declspec(import)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Facades {
	class PHYSICSCOLLISION_API WorldFacade {
	private:
		std::shared_ptr<b2World> _world;
		std::vector<b2Body*> _bodies;;
	public:
		WorldFacade();
		void destroy_bodies();
		void simulate()const ;
		void add_shape(std::shared_ptr<Models::Shape>, const float x, const float y);
	};
}