#include "Circle.h"

/// <summary>
/// Initialize a Circle object with default radius = 1.0
/// </summary>
Circle::Circle():_radius(1.0){}

/// <summary>
/// Initialize a Circle object with input radius
/// </summary>
/// <param name="radius"></param>
Circle::Circle(double radius):_radius(radius){}

/// <summary>
/// Delete Circle object
/// </summary>
Circle::~Circle(){}

/// <summary>
/// Set radius for Circle object
/// </summary>
/// <param name="radius"></param>
void Circle::setRadius(double radius)
{
	_radius = radius;
}

/// <summary>
/// Get radius from Circle object
/// </summary>
/// <returns>_radius</returns>
double Circle::radius() const
{
	return _radius;
}

/// <summary>
/// Get type = "Circle" from Circle object
/// </summary>
/// <returns>"Circle"</returns>
string Circle::type() const
{
	return "Circle";
}

/// <summary>
/// Caculate area of Circle object
/// </summary>
/// <returns>Area = radius^2 * PI</returns>
double Circle::area() const
{
	return _radius*_radius*pi;
}

/// <summary>
/// Calculate circumference of Circle object
/// </summary>
/// <returns>Circumference = 2PI * radius</returns>
double Circle::perimeter() const
{
	return 2*pi*_radius;
}

/// <summary>
/// Display Circle object with type of shape, dimensions, area and circumference, each field separated by "|"
/// </summary>
/// <param name="out"></param>
void Circle::doPrint(ostream& out) const{
	//Convert to string for printing out
	stringstream ss;
	ss << fixed << setprecision(2) << this->_radius;
	string str_radius = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + this->type()
		<< left << setw(40) << " | Radius = " + str_radius
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}