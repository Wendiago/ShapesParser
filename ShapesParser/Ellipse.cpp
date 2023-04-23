#include "Ellipse.h"

Ellipse::Ellipse():_major_axis(1.0), _minor_axis(1.0) {}

Ellipse::Ellipse(double major_axis, double minor_axis):_major_axis(major_axis), _minor_axis(minor_axis) {}

Ellipse::~Ellipse() {}

void Ellipse::setMajorAxis(double major_axis) 
{
	_major_axis = major_axis;
}

void Ellipse::setMinorAxis(double minor_axis) 
{
	_minor_axis = minor_axis;
}

double Ellipse::major_axis() const 
{
	return _major_axis;
}

double Ellipse::minor_axis() const 
{
	return _minor_axis;
}

string Ellipse::type() const 
{
	return "Ellipse";
}

double Ellipse::area() const
{
	double a = _major_axis / 2.0;
	double b = _minor_axis / 2.0;
	return a * b * pi;
}

double Ellipse::perimeter() const
{
	double a = _major_axis / 2.0;
	double b = _minor_axis / 2.0;
	return pi * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

void Ellipse::doPrint(ostream& out) const {
	out << left << setw(15) << this->type()
		<< left << setw(10) << " | Major Axis = " << this->_major_axis << ", Minor Axis = " << this->_minor_axis
		<< left << setw(10) << " | Perimeter = " << fixed << setprecision(1) << this->perimeter()
		<< left << setw(10) << " | Area = " << fixed << setprecision(2) << this->area()
		<< " | ";
}