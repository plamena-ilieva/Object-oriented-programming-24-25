#include <iostream>
#include "ShapeCollection.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

void ShapeCollection::free()
{
	for (size_t i = 0; i < count; i++)
	{
		delete shapes[i];
	}

	delete[] shapes;
}


void ShapeCollection::moveFrom(ShapeCollection&& other)
{
	shapes = other.shapes;
	other.shapes = nullptr;

	count = other.count;
	capacity = other.capacity;
	other.count = other.capacity = 0;
}

void ShapeCollection::resize()
{
	Shape** temp = new Shape * [2 * capacity];

	for (size_t i = 0; i < count; i++)
	{
		temp[i] = shapes[i];
	}

	capacity *= 2;
	delete[] shapes;
	shapes = temp;
}

void ShapeCollection::addShape(Shape* shape)
{
	if (count == capacity) {
		resize();
	}

	shapes[count++] = shape;
}

ShapeCollection::ShapeCollection()
{
	count = 0;
	capacity = 8;
	shapes = new Shape * [capacity];
}

ShapeCollection::ShapeCollection(ShapeCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

ShapeCollection::~ShapeCollection()
{
	free();
}

void ShapeCollection::addRectangle(double x1, double y1, double x3, double y3)
{
	Rectangle* rec = new Rectangle(x1, y1, x3, y3);
	addShape(rec);
}

void ShapeCollection::addCircle(double x1, double y1, double r)
{
	Circle* cir = new Circle(x1, y1, r);
	addShape(cir);
}

void ShapeCollection::addTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	Triangle* tr = new Triangle(x1, y1, x2, y2, x3, y3);
	addShape(tr);
}

void ShapeCollection::printAreas() const
{
	for (int i = 0; i < count; i++) {
		std::cout << shapes[i]->getArea() << std::endl;
	}
}

void ShapeCollection::printPers() const
{
	for (int i = 0; i < count; i++) {
		std::cout << shapes[i]->getPer() << std::endl;
	}
}

void ShapeCollection::checkPointIn(const Shape::Point& p)
{
	for (int i = 0; i < count; i++) {
		std::cout << shapes[i]->isInside(p) << std::endl;
	}
}
