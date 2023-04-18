#pragma once
#include "IShape.h"
using namespace std;

class Rectangle :public IShape {
private:
	double _width;
	double _height;
public:
	Rectangle();
	Rectangle(double, double);
	~Rectangle();
public:
	double area() const;
	double perimeter() const;
};