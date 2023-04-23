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
	stringstream ss;
	ss << fixed << setprecision(2) << _major_axis;
	string str_major = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << _minor_axis;
	string str_minor = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();


	out << left << setw(15) << this->type()
		<< left << setw(35) << " | Major Axis = " + str_major + ", Minor Axis = " << str_minor
		<< left << setw(20) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}