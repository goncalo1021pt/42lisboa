#ifndef Point_HPP
#define Point_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const Point& src);
		Point(float const x, float const y);
		~Point();
		Point &operator=(const Point& src);
		float getX(void) const;
		float getY(void) const;
};

#endif
