#include "Complex.h"
#include <iostream>

int main()
{
	Complex  c(3, 4);
	Complex c2(3, 4);

	std::cout << c * c2;
}