#include "Rectangle.h"

Rectangle::Rectangle():_width(1.0), _height(1.0){}

Rectangle::Rectangle(double width, double height):_width(width), _height(height){}

Rectangle::~Rectangle(){}

void Rectangle::setWidth(double width)
{
	_width = width;
}

double Rectangle::width() const
{
	return _width;
}

void Rectangle::setHeight(double height)
{
	_height = height;
}

double Rectangle::height() const
{
	return _height;
}

string Rectangle::type() const
{
	return "Rectangle";
}

double Rectangle::area() const 
{
	return _width*_height;
}

double Rectangle::perimeter() const
{
	return (_width+_height)*2;
}

void Rectangle ::doPrint(ostream& out) const{
	out << left << setw(15) << this->type()
		<< left << setw(10) << " | Height = " << this->_height << ", Width = " << this->_width
		<< left << setw(10) << " | Perimeter = " << fixed << setprecision(1) << this->perimeter()
		<< left << setw(10) << " | Area = " << fixed << setprecision(2) << this->area()
		<< " | ";
}