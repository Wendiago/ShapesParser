#include "Triangle.h"

/// <summary>
/// Initialize a Triangle object with default 3 edges = 3.0, 4.0 and 5.0 respectively
/// </summary>
Triangle::Triangle():_a(3.0), _b(4.0), _c(5.0){}

/// <summary>
/// Initialize a Triangle object with 3 input edges 
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="c"></param>
Triangle::Triangle(double a, double b, double c)
{
	_a = a;
	_b = b;
	_c = c;
}

/// <summary>
/// Delete a Triangle object
/// </summary>
Triangle::~Triangle(){}

/// <summary>
/// Set first edge
/// </summary>
/// <param name="a"></param>
void Triangle::set_a(double a)
{
	_a = a;
}

/// <summary>
/// Set second edge
/// </summary>
/// <param name="b"></param>
void Triangle::set_b(double b)
{
	_b = b;
}

/// <summary>
/// Set third edge
/// </summary>
/// <param name="c"></param>
void Triangle::set_c(double c)
{
	_c = c;
}

/// <summary>
/// Get first edge
/// </summary>
/// <returns>first edge a</returns>
double Triangle::a() const
{
	return _a;
}

/// <summary>
/// Get second edge
/// </summary>
/// <returns>Second edge b</returns>
double Triangle::b() const
{
	return _b;
}

/// <summary>
/// Get third edge c
/// </summary>
/// <returns>Third edge c</returns>
double Triangle::c() const
{
	return _c;
}

/// <summary>
/// Get type = "Triangle" of a Triangle object
/// </summary>
/// <returns>string "Triangle"</returns>
string Triangle::type() const
{
	return "Triangle";
}

/// <summary>
/// Calculate area of a Triangle object using Heron formula
/// </summary>
/// <returns>Area</returns>
double Triangle::area() const
{
	double p = (_a + _b + _c) / 2.0;
	return sqrt(p * (p - _a) * (p - _b) * (p - _c));
}

/// <summary>
/// Calculate circumference of a Triangle object
/// </summary>
/// <returns>Circumference = a+b+c</returns>
double Triangle::perimeter() const
{
	return _a + _b + _c;
}

/// <summary>
/// Display Triangle object with type of shape, dimensions, area and circumference, each field separated by "|"
/// </summary>
/// <param name="out"></param>
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

	out << left << setw(15) << " | " + this->type()
		<< left << setw(40) << " | a = " + str_a + ", b = " + str_b + ", c = " + str_c
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}


