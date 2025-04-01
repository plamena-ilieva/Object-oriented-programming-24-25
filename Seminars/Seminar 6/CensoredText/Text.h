#pragma once
#include "Censor.h"
constexpr size_t SIZE = 32;

class Text
{
	char content[SIZE];
	Censor& censor;

public:
	Text(const char* str, Censor& censor);
	void setContent(const char* str);
	void print() const;
};

