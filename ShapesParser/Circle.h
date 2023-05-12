#pragma once
#include "IShape.h"
#include <iomanip>
#include <sstream>
#include <string>
using std::left, std::setw, std::fixed, std::setprecision, std::stringstream;

class Circle :public IShape {
public:
	inline static const double pi = 3.14;
private:
	double _radius;
public:
	Circle();
	Circle(double);
	~Circle();
public:
	void setRadius(double);
	double radius() const;
	string type() const;
public:
	double area() const override;
	double perimeter() const override;
};