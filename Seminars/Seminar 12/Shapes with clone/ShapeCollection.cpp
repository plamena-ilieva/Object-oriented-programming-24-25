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

void ShapeCollection::copyFrom(const ShapeCollection& other)
{
	count = other.count;
	capacity = other.capacity;

	shapes = new Shape * [capacity];

	for (size_t i = 0; i < count; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
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

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
	copyFrom(other);
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
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

void ShapeCollection::addShape(const Shape& shape)
{
	Shape* ptr = shape.clone();
	addShape(ptr);
}
