#include "Censor.h"
#include <iostream>

void Censor::printSymbol(char a) const
{
	if (shouldCensor(a)) {
		std::cout << '*';
	}
	else {
		std::cout << a;
	}
}

void Censor::print(const char* str) const
{
	while (str && *str != '\0') {
		printSymbol(*str);
		str++;
	}
}
