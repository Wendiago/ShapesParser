#include "Rectangle.h"

Rectangle::Rectangle():_width(0), _height(0){}

Rectangle::Rectangle(double width, double height):_width(width), _height(height){}

Rectangle::~Rectangle()
{
	//
}

double Rectangle::area() const
{
	return _width*_height;
}

double Rectangle::perimeter() const
{
	return (_width+_height)*2;
}


