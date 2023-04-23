#include "Circle.h"
using std::stringstream;

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

	out << left << setw(15) << this->type()
		<< left << setw(35) << " | Radius = " + str_radius
		<< left << setw(20) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}