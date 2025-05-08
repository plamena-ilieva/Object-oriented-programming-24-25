#include <iostream>
using namespace std;

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h"
#include "ShapeCollection.h"

int main()
{
	ShapeCollection collection;

	collection.addRectangle(3, 4, 6, 8);
	collection.addCircle(3, 3, 4);
	collection.addCircle(1, 4, 5);
	collection.addTriangle(1, 1, 2, 2, 3, 4);

	collection.printAreas();
	std::cout << endl;
	collection.printPers();
	std::cout << endl;

	collection.checkPointIn({ 3, 3 });
}