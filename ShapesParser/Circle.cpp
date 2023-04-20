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


