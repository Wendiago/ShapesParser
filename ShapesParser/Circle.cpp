#include "Circle.h"

Circle::Circle():_radius(1.0){}

Circle::Circle(double radius):_radius(radius){}

Circle::~Circle(){}

void Circle::setRadius(double radius)
{
	_radius = radius;
}

double Circle::radius() const
{
	return _radius;
}

string Circle::type() const
{
	return "Circle";
}

double Circle::area() const
{
	return _radius*_radius*pi;
}

double Circle::perimeter() const
{
	return 2*pi*_radius;
}

void Circle::doPrint(ostream& out) const{
	out << left << setw(15) << this->type()
		<< left << setw(2) << "|"
		<< "Radius = " << this->_radius
		<< left << setw(2) << "|"
		<< left << setw(12) << "Perimeter = " << fixed << setprecision(1) << this->perimeter()
		<< left << setw(2) << "|"
		<< left << setw(7) << "Area = " << fixed << setprecision(2) << this->area()
		<< left << setw(2) << "|";
}