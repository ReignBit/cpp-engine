#include "Vector2.h"

Vector2 up = Vector2(0,1);

Vector2::Vector2()
	:x(0), y(0)
{

}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{

}

std::ostream& operator<<(std::ostream& os,  Vector2 dt)
{
	os << '(' << dt.x << ',' << dt.y << ')' << std::endl;
	return os;
}


