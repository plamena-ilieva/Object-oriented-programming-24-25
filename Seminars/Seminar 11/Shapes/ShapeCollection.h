#pragma once
#include "Shape.h"

class ShapeCollection
{
	Shape** shapes;
	size_t count;
	size_t capacity;
	void free();
	void moveFrom(ShapeCollection&& other);
	void resize();

	void addShape(Shape* shape);

public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other) = delete;
	ShapeCollection& operator=(const ShapeCollection& other) = delete;

	ShapeCollection(ShapeCollection&& other) noexcept;
	ShapeCollection& operator=(ShapeCollection&& other) noexcept;
	~ShapeCollection();

	void addRectangle(double x1, double y1, double x3, double y3);
	void addCircle(double x1, double y1, double r);
	void addTriangle(double x1, double y1, double x2, double y2, double x3, double y3);

	void printAreas() const;
	void printPers() const;
	void checkPointIn(const Shape::Point& p);
};

