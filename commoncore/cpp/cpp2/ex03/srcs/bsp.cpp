#include "Point.h"

static float area(Point const a, Point const b, Point const c)
{
	float area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0;
	if (area < 0)
		area *= -1;

	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float areaABC = area(a, b, c);
	float areaPBC = area(point, b, c);
	float areaPCA = area(a, point, c);
	float areaPAB = area(a, b, point);

	return ((areaABC == areaPBC + areaPCA + areaPAB) && (areaPBC != 0 && areaPCA != 0 && areaPAB != 0));
}