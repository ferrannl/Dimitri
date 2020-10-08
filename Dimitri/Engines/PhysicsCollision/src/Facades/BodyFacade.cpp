#include "BodyFacade.h"

float Facades::BodyFacade::get_x()
{
	return _body->GetPosition().x;
}

float Facades::BodyFacade::get_y()
{
	return  _body->GetPosition().y;
}

float Facades::BodyFacade::get_angle()
{
	return  _body->GetAngle() * RADIAN_IN_DEGREES;
}
