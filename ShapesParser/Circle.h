#pragma once
#include "IShape.h"
#include <iomanip>

using std::left, std::setw, std::setprecision;

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
public:
	void doPrint(ostream&) const override;
};