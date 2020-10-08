#pragma once
#include "../Facades/BodyFacade.h"

namespace Models {
	class __declspec(dllexport) Body {
	private:
		Facades::BodyFacade* _body_facade;
	public:
		Body(Facades::BodyFacade* body_facade) : _body_facade{ body_facade } {};
		float get_x();
		float get_y();
		float get_angle();
	};
}