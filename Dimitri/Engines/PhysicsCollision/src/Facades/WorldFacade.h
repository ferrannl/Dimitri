#pragma once
#include <vector>
#include "../Models/Shape.h"


#ifdef _WIN64
#ifdef PHYSICSCOLLISION_EXPORTS
#define PHYSICSCOLLISION_API __declspec(dllexport)
#else 
#define PHYSICSCOLLISION_API __declspec(dllimport)
#endif
#else
#define PHYSICSCOLLISION_API
#endif

namespace Facades {
	class PHYSICSCOLLISION_API WorldFacade {
	private:
		std::shared_ptr<b2World> _world;
		std::vector<b2Body*> _bodies;
	public:
		WorldFacade();
		void destroy_body(std::shared_ptr<Facades::ShapeFacade> shape_facade);
		void simulate()const;
		void add_shape(std::unique_ptr<Models::Shape>& shape, const float x, const float y);
	};
}