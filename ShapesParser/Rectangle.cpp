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
void Rectangle::setWidth(double width)
{
	_width = width;
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
void Rectangle::setHeight(double height)
{
	_height = height;
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