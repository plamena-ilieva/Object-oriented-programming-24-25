#pragma once
class Censor
{
	bool (*shouldCensor) (char a);

	void printSymbol(char a) const;

public:
	Censor() : shouldCensor([](char a) { return false; }) {};
	Censor(bool (*pred) (char a)) : shouldCensor(pred) {}

	void print(const char* str) const;
};

