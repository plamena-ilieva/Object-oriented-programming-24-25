#pragma once
#include "Shape.h"

class ShapeCollection
{
	Shape** shapes;
	size_t count;
	size_t capacity;
	void free();
	void moveFrom(ShapeCollection&& other);
	void copyFrom(const ShapeCollection& other);
	void resize();

	void addShape(Shape* shape);

public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);

	ShapeCollection(ShapeCollection&& other) noexcept;
	ShapeCollection& operator=(ShapeCollection&& other) noexcept;
	~ShapeCollection();

	void addShape(const Shape& shape);
	void printAreas() const;
	void printPers() const;
	void checkPointIn(const Shape::Point& p);
};

