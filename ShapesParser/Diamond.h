#pragma once
#include "IShape.h"
#include <iomanip>
#include <sstream>
#include <string>

using std::left, std::setw, std::fixed, std::setprecision, std::stringstream;

class Diamond :public IShape {
private:
	double _diagonal_p;
	double _diagonal_q;
public:
	Diamond();
	Diamond(double, double);
	~Diamond();
public:
	void setDiagonalP(double);
	void setDiagonalQ(double);
	double diagonal_p() const;
	double diagonal_q() const;
	string type() const;
public:
	double area() const override;
	double perimeter() const override;
public:
	void simplePrint(ostream& out) const override;
	void detailedPrint(ostream& out) const override;
};