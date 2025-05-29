#pragma once
#include <iostream>
class Complex
{
public:
	Complex();
	Complex(double real, double im);

	Complex getConjugated() const;

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);

	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);

	friend bool operator==(const Complex& lhs, const Complex& rhs);
	friend bool operator!=(const Complex& lhs, const Complex& rhs);

private:
	double real;
	double im;
};
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);