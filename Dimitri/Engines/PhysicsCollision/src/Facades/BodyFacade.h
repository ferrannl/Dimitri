#pragma once
#include <box2d\b2_body.h>

namespace Facades {
	float static RADIAN_IN_DEGREES = 57.3f;
	class __declspec(dllexport) BodyFacade {
	private:
		b2Body* _body;
	public:
		BodyFacade(b2Body* body) : _body{ body } {};
		float get_x();
		float get_y();
		float get_angle();
	};
}