#include "Ellipse.h"

/// <summary>
/// Initialize an Ellipse object with default major axis = 1.0 and minor axis = 1.0
/// </summary>
Ellipse::Ellipse():_major_axis(1.0), _minor_axis(1.0) {}

/// <summary>
/// Initialize an Ellipse object with input major and minor axis
/// </summary>
/// <param name="major_axis"></param>
/// <param name="minor_axis"></param>
Ellipse::Ellipse(double major_axis, double minor_axis):_major_axis(major_axis), _minor_axis(minor_axis) {}


/// <summary>
/// Delete Ellipse object
/// </summary>
Ellipse::~Ellipse() {}

/// <summary>
/// Set major axis of Ellipse object
/// </summary>
/// <param name="major_axis"></param>
void Ellipse::setMajorAxis(double value) 
{
	_major_axis = value;
}

/// <summary>
/// Set minor  axis of Ellipse object
/// </summary>
/// <param name="minor_axis"></param>
void Ellipse::setMinorAxis(double value)
{
	_minor_axis = value;
}

/// <summary>
/// Get major axis of Ellipse object
/// </summary>
/// <returns>major axis</returns>
double Ellipse::major_axis() const 
{
	return _major_axis;
}

/// <summary>
/// Get minor axis of Ellipse object
/// </summary>
/// <returns>minor axis</returns>
double Ellipse::minor_axis() const 
{
	return _minor_axis;
}

/// <summary>
/// Get type = "Ellipse" of Ellipse object
/// </summary>
/// <returns>"Ellipse"</returns>
string Ellipse::type() const 
{
	return "Ellipse";
}

/// <summary>
/// Calculate area of Ellipse object
/// </summary>
/// <returns>Area = major_axis/2 * minor_axis/2 * PI</returns>
double Ellipse::area() const
{
	double a = _major_axis / 2.0;
	double b = _minor_axis / 2.0;
	return a * b * pi;
}

/// <summary>
/// Calculate circumference of Ellipse object
/// </summary>
/// <returns>Circumference of Ellipse</returns>
double Ellipse::perimeter() const
{
	double a = _major_axis / 2.0;
	double b = _minor_axis / 2.0;
	return pi * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

void Ellipse::simplePrint(ostream& out) const
{
	out << this->type() << ": Major Axis = " << this->major_axis() << ", Minor Axis = " << this->minor_axis();
}

void Ellipse::detailedPrint(ostream& out) const
{
	stringstream ss;
	ss << fixed << setprecision(2) << this->major_axis();
	string str_major = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->minor_axis();
	string str_minor = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();


	out << left << setw(15) << " | " + this->type()
		<< left << setw(40) << " | Major Axis = " + str_major + ", Minor Axis = " + str_minor
		<< left << setw(25) << " | Circumference = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}