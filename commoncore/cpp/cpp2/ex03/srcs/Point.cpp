#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(Fixed(x)), y(Fixed(y)) {
}

Point::Point(const Point& src) : x(src.x), y(src.y) {} 

Point::~Point() {}

Point &Point::operator=(const Point& src) {
	(void)src;
	return *this;
}

float Point::getX(void) const
{
	return (this->x.toFloat());
}

float Point::getY(void) const
{
	return (this->y.toFloat());
}