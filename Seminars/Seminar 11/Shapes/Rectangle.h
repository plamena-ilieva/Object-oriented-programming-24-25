#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(double x1, double y1, double x3, double y3);

	// Inherited via Shape
	double getArea() const override;
	bool isInside(const Point&) const override;
};