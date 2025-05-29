#include "Text.h"
#include <iostream>

#pragma warning (disable:4996)

Text::Text(const char* str, Censor& censor): censor(censor) {
	setContent(str);
}
void Text::setContent(const char* str) {
	if (str && strlen(str) >= SIZE) {
		strcpy(content, "");
	}
	else {
		strcpy(content, str);
	}
}

void Text::print() const
{
	censor.print(content);
}
