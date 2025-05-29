#include "Circle.h"

Circle::Circle(double x, double y, double radius) : Shape(1), radius(radius)
{
    setAtIndex(0, { x, y });
}

double Circle::getArea() const
{
    return 3.14 * radius * radius;
}

double Circle::getPer() const
{
    return 3.14 * 2 * radius;
}

bool Circle::isInside(const Point& p) const
{
    return p.getDist(getAtIndex(0)) <= radius;
}

Circle* Circle::clone() const
{
    return new Circle(*this);
}
