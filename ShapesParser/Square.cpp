#include "Square.h"

/// <summary>
/// Initialize a Square object with default edge = 1.0
/// </summary>
Square::Square() : _edge(1.0) {}

/// <summary>
/// Initialize a Square object with input edge
/// </summary>
/// <param name="edge"></param>
Square::Square(double edge): _edge{edge}{}

/// <summary>
/// Delete Square object
/// </summary>
Square::~Square(){}

/// <summary>
/// Set edge of a Square object
/// </summary>
/// <param name="edge"></param>
void Square::setEdge(double edge)
{
	_edge = edge;
}

/// <summary>
/// Get edge from a Square object
/// </summary>
/// <returns>edge</returns>
double Square::edge() const
{
	return _edge;
}

/// <summary>
/// Get type = "Square" of a Square object
/// </summary>
/// <returns>string "Square"</returns>
string Square::type() const
{
	return "Square";
}

/// <summary>
/// Calculate area of a Square object
/// </summary>
/// <returns>Area = edge^2</returns>
double Square::area() const
{
	return _edge*_edge;
}

/// <summary>
/// Calculate perimeter of a Square object
/// </summary>
/// <returns>Perimeter = edge*4</returns>
double Square::perimeter() const
{
	return _edge*4;
}