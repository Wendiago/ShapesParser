#pragma once
#include "IShape.h"
#include <iomanip>
#include <sstream>
#include <string>

using std::left, std::setw, std::fixed, std::setprecision, std::stringstream;

class Ellipse :public IShape {
public:
	inline static const double pi = 3.14;
private:
	double _major_axis;
	double _minor_axis;
public:
	Ellipse();
	Ellipse(double, double);
	~Ellipse();
public:
	void setMajorAxis(double);
	void setMinorAxis(double);
	double major_axis() const;
	double minor_axis() const;
	string type() const;
public:
	double area() const override;
	double perimeter() const override;
public:
	void simplePrint(ostream& out) const override;
	void detailedPrint(ostream& out) const override;
};