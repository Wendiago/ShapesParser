#include "Triangle.h"

Triangle::Triangle():_a(3.0), _b(4.0), _c(5.0){}

Triangle::Triangle(double a, double b, double c)
{
	_a = a;
	_b = b;
	_c = c;
}

Triangle::~Triangle()
{
}

void Triangle::set_a(double a)
{
	_a = a;
}

void Triangle::set_b(double b)
{
	_b = b;
}

void Triangle::set_c(double c)
{
	_c = c;
}

double Triangle::a() const
{
	return _a;
}

double Triangle::b() const
{
	return _b;
}

double Triangle::c() const
{
	return _c;
}

string Triangle::type() const
{
	return "Triangle";
}

double Triangle::area() const
{
	double p = (_a + _b + _c) / 2.0;
	return sqrt(p * (p - _a) * (p - _b) * (p - _c));
}

double Triangle::perimeter() const
{
	return _a + _b + _c;
}

void Triangle::doPrint(ostream& out) const
{
	stringstream ss;
	ss << fixed << setprecision(2) << _a;
	string str_a = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << _b;
	string str_b = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << _c;
	string str_c = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << this->type()
		<< left << setw(35) << " | a = " + str_a + ", b = " + str_b + ", c = " + str_c
		<< left << setw(20) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}


