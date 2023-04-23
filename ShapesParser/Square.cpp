#include "Square.h"
using std::to_string, std::stringstream;

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
	//Convert to string for printing out
	stringstream ss;
	ss << fixed << setprecision(2) << this->_edge;
	string str_edge = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << this->type()
		<< left << setw(35) << " | Edge = " + str_edge
		<< left << setw(20) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}