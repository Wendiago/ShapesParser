#pragma once
#include "IShape.h"
#include <sstream>
#include <iomanip>
using namespace std;
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
public:
	void doPrint(ostream&) const override;

};