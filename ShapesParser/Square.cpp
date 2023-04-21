#include "Square.h"

Square::Square() : _edge(1.0) {}

Square::Square(double edge): _edge{edge}{}

Square::~Square(){}

void Square::setEdge(double edge)
{
	_edge = edge;
}

double Square::edge() const
{
	return _edge;
}

string Square::type() const
{
	return "Square";
}

double Square::area() const
{
	return _edge*_edge;
}

double Square::perimeter() const
{
	return _edge*4;
}

void Square::doPrint(ostream& out) const{
	out << left << setw(15) << this->type()
		<< left << setw(2) << "|"
		<< left << setw(30) << "Edge = " << this->_edge
		<< left << setw(2) << "|"
		<< left << setw(20) << "Perimeter = " << setprecision(1) << this->perimeter()
		<< left << setw(2) << "|"
		<< left << setw(20) << "Area = " << setprecision(2) << this->area();
}