#include "Rectangle.h"

/// <summary>
/// Initialize a Rectangle object with default width = 1.0 and height = 1.0
/// </summary>
Rectangle::Rectangle():_width(1.0), _height(1.0){}

/// <summary>
/// Initialize a Rectangle object with input width and height
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
Rectangle::Rectangle(double width, double height):_width(width), _height(height){}

/// <summary>
/// Delete Rectangle object
/// </summary>
Rectangle::~Rectangle(){}

/// <summary>
/// Set width of Rectangle object
/// </summary>
/// <param name="width"></param>
void Rectangle::setWidth(double value)
{
	_width = value;
}

/// <summary>
/// Get width of Rectangle object
/// </summary>
/// <returns>width</returns>
double Rectangle::width() const
{
	return _width;
}

/// <summary>
/// Set height of Reactangle object
/// </summary>
/// <param name="height"></param>
void Rectangle::setHeight(double value)
{
	_height = value;
}

/// <summary>
/// Get height of Rectangle object
/// </summary>
/// <returns></returns>
double Rectangle::height() const
{
	return _height;
}

/// <summary>
/// Get type = "Rectangle" of a Rectangle object
/// </summary>
/// <returns>string "Rectangle"</returns>
string Rectangle::type() const
{
	return "Rectangle";
}

/// <summary>
/// Calculate Area of a Rectangle object
/// </summary>
/// <returns>Area = height * weight</returns>
double Rectangle::area() const 
{
	return _width*_height;
}

/// <summary>
/// Calculate perimeter of a Rectangle object
/// </summary>
/// <returns>Perimeter = (width+height)*2</returns>
double Rectangle::perimeter() const
{
	return (_width+_height)*2;
}

void Rectangle::simplePrint(ostream& out) const
{
	out << this->type() << ": Height = " << this->height() << ", Width = " << this->width();
}

void Rectangle::detailedPrint(ostream& out) const
{
	stringstream ss;
	ss << fixed << setprecision(2) << this->height();
	string str_height = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->width();
	string str_width = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + this->type()
		<< left << setw(40) << " | Height =  " + str_height + ", Width = " + str_width
		<< left << setw(25) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}