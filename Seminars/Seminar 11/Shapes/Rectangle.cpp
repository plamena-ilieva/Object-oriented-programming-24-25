#include "Rectangle.h"
#include <limits>

const double EPSILON = std::numeric_limits<double>::epsilon();

Rectangle::Rectangle(double x1, double y1, double x3, double y3) : Shape(4)
{
	setAtIndex(0, { x1, y1 });
	setAtIndex(1, { x1, y3 });
	setAtIndex(2, { x3, y3 });
	setAtIndex(3, { x3, y1 });
}

double Rectangle::getArea() const
{
	const Shape::Point& p0 = getAtIndex(0);
	const Shape::Point& p1 = getAtIndex(1);
	const Shape::Point& p3 = getAtIndex(3);

	return p0.getDist(p1) * p0.getDist(p3);
}


bool Rectangle::isInside(const Point& p) const
{
	return (p.x >= getAtIndex(0).x - EPSILON && p.x <= getAtIndex(2).x + EPSILON) &&
		(p.y <= getAtIndex(0).y + EPSILON && p.y >= getAtIndex(2).y - EPSILON);
}
