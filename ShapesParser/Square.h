#pragma once
#include "IShape.h"
#include <iomanip>

using std::left, std::setw, std::setprecision;

class Square :public IShape {
private:
	double _edge;
public:
	Square();
	Square(double);
	~Square();
public:
	void setEdge(double);
	double edge() const;
	string type() const;
public:
	double area() const override;
	double perimeter() const override;
public:
	void doPrint(ostream&) const override;
};