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




