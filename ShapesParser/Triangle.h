#pragma once
#include "IShape.h"
#include <iomanip>
#include <sstream>
#include <string>

using std::left, std::setw, std::fixed, std::setprecision, std::stringstream;

class Triangle :public IShape {
private:
	double _a;
	double _b;
	double _c;
public:
	Triangle();
	Triangle(double, double, double);
	~Triangle();
public:
	void set_a(double);
	void set_b(double);
	void set_c(double);
	double a() const;
	double b() const;
	double c() const;
	string type() const;
public:
	double area() const;
	double perimeter() const;
	static bool isTriangle(double, double, double);
public:
	void simplePrint(ostream& out) const override;
	void detailedPrint(ostream& out) const override;
};