#include "Rectangle.h"

using namespace std;
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
	//Convert to string for printing out
	stringstream ss;
	ss << fixed << setprecision(2) << _height;
	string str_height = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << _width;
	string str_width = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << this->type()
		<< left << setw(35) << " | Height =  " + str_height + ", Width = " + str_width
		<< left << setw(20) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}