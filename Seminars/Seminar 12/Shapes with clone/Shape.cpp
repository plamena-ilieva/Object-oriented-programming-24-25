#include "Shape.h"
#include <stdexcept>

Shape::Shape(size_t n)
{
	count = n;
	points = new Point[count];
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.count];

	for (int i = 0; i < other.count; i++)
		points[i] = other.points[i];

	count = other.count;
}
void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	other.points = nullptr;

	count = other.count;
	other.count = 0;
}
void Shape::free()
{
	delete[] points;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}
Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
}

Shape& Shape::operator= (const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Shape::~Shape()
{
	free();
}


const Shape::Point& Shape::getAtIndex(size_t n) const
{
	if (n >= count) {
		throw std::out_of_range("Invalid point index");
	}

	return points[n];
}

void Shape::setAtIndex(size_t n, const Point& p)
{
	if (n >= count) {
		throw std::out_of_range("Invalid point index");
	}

	points[n] = p;
}

double Shape::getPer() const
{
	double res = 0;

	for (size_t i = 0; i < count - 1; i++)
	{
		res += points[i].getDist(points[i + 1]);
	}
	res += points[count - 1].getDist(points[0]);
	return res;
}
