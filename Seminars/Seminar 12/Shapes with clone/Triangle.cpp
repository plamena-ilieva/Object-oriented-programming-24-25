#include "Triangle.h"
#include <limits>

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : Shape(3)
{
    setAtIndex(0, { x1, y1 });
    setAtIndex(1, { x2, y2 });
    setAtIndex(2, { x3, y3 });
}

double Triangle::getArea() const
{
    const Point& p1 = getAtIndex(0);
    const Point& p2 = getAtIndex(1);
    const Point& p3 = getAtIndex(2);

    return abs(p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.y * p2.x - p2.y * p3.x - p3.y * p1.x) / 2.00;
}

bool Triangle::isInside(const Point& p) const
{
    Triangle t1(p.x, p.y, getAtIndex(0).x, getAtIndex(0).y, getAtIndex(1).x, getAtIndex(1).y);
    Triangle t2(p.x, p.y, getAtIndex(2).x, getAtIndex(2).y, getAtIndex(1).x, getAtIndex(1).y);
    Triangle t3(p.x, p.y, getAtIndex(0).x, getAtIndex(0).y, getAtIndex(2).x, getAtIndex(2).y);
    
    return abs(t1.getArea() + t2.getArea() + t3.getArea() - getArea()) <= std::numeric_limits<double>::epsilon();
}

Triangle* Triangle::clone() const
{
    return new Triangle(*this);
}
