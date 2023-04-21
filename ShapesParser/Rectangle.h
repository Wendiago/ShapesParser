#pragma once
#include "IShape.h"

class Rectangle :public IShape {
private:
	double _width;
	double _height;
public:
	Rectangle();
	Rectangle(double, double);
	~Rectangle();
public:
	void setWidth(double);
	double width() const;
	void setHeight(double);
	double height() const;
	string type() const;
public:
	double area() const override;
	double perimeter() const override;
};