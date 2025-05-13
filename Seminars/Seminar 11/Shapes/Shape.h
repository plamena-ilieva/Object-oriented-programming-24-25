#pragma once
#include <cmath>
class Shape
{
public:
	struct Point
	{
		Point() :x(0), y(0) {}
		Point(double x, double y) :x(x), y(y) {}
		double x;
		double y;
		double getDist(const Point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return std::sqrt(dx * dx + dy * dy);
		}
	};

private:
	Point* points;
	size_t count;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
	void free();

public:
	Shape(size_t n);

	Shape(const Shape& other);
	Shape(Shape&& other) noexcept;

	Shape& operator=(const Shape& other);
	Shape& operator=(Shape&& other) noexcept;

	const Point& getAtIndex(size_t n) const;
	void setAtIndex(size_t n, const Point& p);

	virtual double getArea() const = 0;
	virtual double getPer() const;
	virtual bool isInside(const Point&) const = 0;

	virtual ~Shape();
};

