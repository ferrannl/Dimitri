#include "Body.h"

float Models::Body::get_x()
{
	return _body_facade->get_x();
}

float Models::Body::get_y()
{
	return _body_facade->get_y();
}

float Models::Body::get_angle()
{
	return _body_facade->get_angle();
}
