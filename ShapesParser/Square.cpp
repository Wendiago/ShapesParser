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
void Square::setEdge(double value)
{
	_edge = value;
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

void Square::simplePrint(ostream& out) const
{
	out << this->type() << ": Edge = " << this->edge();
}

void Square::detailedPrint(ostream& out) const
{
	stringstream ss;
	ss << fixed << setprecision(2) << this->edge();
	string str_edge = ss.str();

	ss.str("");
	ss << fixed << setprecision(1) << this->perimeter();
	string str_peri = ss.str();

	ss.str("");
	ss << fixed << setprecision(2) << this->area();
	string str_area = ss.str();

	out << left << setw(15) << " | " + this->type()
		<< left << setw(40) << " | Edge = " + str_edge
		<< left << setw(25) << " | Perimeter = " + str_peri
		<< left << setw(16) << " | Area = " + str_area
		<< " | ";
}