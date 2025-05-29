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

	collection.addShape(Rectangle{ 3, 4, 6, 8 });
	collection.addShape(Circle{ 3, 3, 4 });
	collection.addShape(Circle{ 1, 4, 5 });
	collection.addShape(Triangle{ 1, 1, 2, 2, 3, 4 });

	ShapeCollection collection1(collection);
	collection.printAreas();
	std::cout << endl;
	collection.printPers();
	std::cout << endl;

	collection.checkPointIn({ 3, 3 });
}