#pragma once
#include "IShape.h"
#include <iomanip>
#include <sstream>
#include <string>

using std::left, std::setw, std::fixed, std::setprecision, std::stringstream;

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
	void simplePrint(ostream& out) const override;
	void detailedPrint(ostream& out) const override;
};