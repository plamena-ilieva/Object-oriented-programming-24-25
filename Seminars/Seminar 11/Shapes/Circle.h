#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius;

public:
	Circle(double x, double y, double raduis);

	// Inherited via Shape
	double getArea() const override;
	double getPer() const override;
	bool isInside(const Point&) const override;
};

